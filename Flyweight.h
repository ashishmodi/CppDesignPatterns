#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Tree {
	string	m_sColor;
	int		m_nHeight;
public:
	Tree(string sColor) : m_sColor(sColor), m_nHeight(6) { }
	string	getColor()		{ return m_sColor;  }
	int		getHeight()		{ return m_nHeight; }
};

class TreePosition {
	int m_nX, m_nY;
public:
	TreePosition(int x, int y) : m_nX(x), m_nY(y) { }
	int getX() { return m_nX; }
	int getY() { return m_nY; }
	void setX(int x) { m_nX = x; }
	void setY(int y) { m_nY = y; }
};

class TreeFactory {
	static inline unordered_map<string, Tree*> mapTree;		// without inline, ODR violation
public:
	TreeFactory() {		TreeFactory::mapTree = unordered_map<string, Tree*>();	}
	Tree* getTree(string sColor) {
		if (!(sColor.compare("green") != 0) && !(sColor.compare("brown") != 0))
			return nullptr;
		if (TreeFactory::mapTree.find(sColor) != TreeFactory::mapTree.end())
			return TreeFactory::mapTree[sColor];
		Tree* tree = new Tree(sColor);
		TreeFactory::mapTree[sColor] = tree;
		return tree;
	}
};

class Game {
	vector<Tree*> m_vTrees;
	vector<TreePosition*> m_vTreePositions;
	TreeFactory* m_treeFactory;
	void renderTree(int treeId) {
		cout << "Tree " + to_string(treeId) + " with color " + m_vTrees[treeId]->getColor() + " rendered at " + to_string(m_vTreePositions[treeId]->getX()) + ", " + to_string(m_vTreePositions[treeId]->getY()) << endl;
	}
public:
	Game() {
		m_treeFactory = new TreeFactory();
	}
	void addTree(int x, int y, string sColor) {
		Tree* tree = m_treeFactory->getTree(sColor);
		if (tree == nullptr)	return;
		m_vTrees.push_back(tree);
		m_vTreePositions.push_back(new TreePosition(x, y));
		int treeId = m_vTrees.size() - 1;
		renderTree(treeId);
	}
};