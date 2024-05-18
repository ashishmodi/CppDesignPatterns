#pragma once
#include <iostream>
#include <string>
#include <list>
#include <cassert>
#include <functional>
#include <iterator>
#include <algorithm>

using namespace std;

class Node {
	Node(const Node&);
	Node& operator=(const Node&);
public:
	string m_sName;
	explicit Node(const string& name) : m_sName(name) {
		assert(!name.empty());
	}
	const string& getName() const		{ return m_sName; }
	void setName(const string& name)	{ m_sName = name; }
	virtual Node* copy() const = 0;
	virtual ~Node() { }
};

class SimpleNode : public Node {
	string m_sValue;
	SimpleNode(const string& name, const string& value) : Node(name), m_sValue(value) {
		cout << "SimpleNode created with name: " << name << endl;
	}
	SimpleNode(const SimpleNode&);
	SimpleNode& operator=(const SimpleNode&);
public:
	static SimpleNode* createNode(const string& name, const string& value) {
		return new SimpleNode(name, value);
	}
	const string& getValue() const		{ return m_sValue; }
	void setValue(const string& value)	{ m_sValue = value; }
	SimpleNode* copy() const override {
		return SimpleNode::createNode(getName(), getValue());
	}
};

class ComplexNode : public Node {
	typedef std::list<Node*> ChildNodes;
	ChildNodes m_listChildNodes;
	explicit ComplexNode(const string& name) : Node(name) {
		cout << "ComplexNode created with name: " << name << endl;
	}

	template<typename ITER>
	ComplexNode(const string& name, ITER begin, ITER end) : Node(name), m_listChildNodes(begin, end) { }

	ComplexNode(const ComplexNode&);
	ComplexNode& operator=(const ComplexNode&);

	void copyChild(ChildNodes& child) const {
		assert(child.empty());
		const ChildNodes& chNodes = getChildNodes();
		std::transform(chNodes.begin(), chNodes.end(), std::back_inserter(child), std::mem_fn(&Node::copy));
		assert(child.size() == chNodes.size());
	}
public:
	static ComplexNode* createNode(const string& s) { return new ComplexNode(s); }
	template<typename ITER>
	static ComplexNode* createNode(const string& s, ITER begin, ITER end) {
		return new ComplexNode(s, begin, end);
	}
	const ChildNodes& getChildNodes() const { return m_listChildNodes; }
	void appendNode(Node* n) {
		m_listChildNodes.push_back(n);
	}
	void removeNode(Node* n) {
		ChildNodes& chNodes = m_listChildNodes;
		ChildNodes::iterator it = std::find(chNodes.begin(), chNodes.end(), n);
		if (it != chNodes.end()) {
			chNodes.erase(it);
		}
	}
	ComplexNode* copy() const override {
		assert(!getName().empty());
		ChildNodes c;
		copyChild(c);
		return ComplexNode::createNode(getName(), c.begin(), c.end());
	}
	~ComplexNode() {
		const ChildNodes& c = getChildNodes();
		ChildNodes::const_iterator it = c.begin();
		for (; it != c.end(); ++it)
			delete* it;
	}
};