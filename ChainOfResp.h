#pragma once
#include <iostream>
#include <vector>
using namespace std;

class PurchaseRequest {
	int		m_nAmount;
	bool	m_bApprovedStatus;
	string	m_sApprovedBy;
public:
	PurchaseRequest(const int amount) : m_nAmount(amount) { }
	int getAmount() const { return m_nAmount; }
	void processPR(const string& sApprover) {
		m_sApprovedBy = sApprover;
		m_bApprovedStatus = true;
	}
	void getStatus() {
		cout << "Purchase Summary => Amount: " << m_nAmount << ", Approver: " << m_sApprovedBy << ", Status: " << m_bApprovedStatus << endl;
	}
};

class Handler {
public:
	virtual Handler* setNext(Handler* next) = 0;
	virtual void handle(PurchaseRequest& request) = 0;
};

class Employee : public Handler {
	Handler*	next;
protected:
	int			m_nApprovalLimit;
	string		m_sName;
	// BaseApprover(const string& sName, const int& nLimit) : m_sName(sName), m_nApprovalLimit(nLimit), next(nullptr) { }
public:
	Employee() : next(nullptr) { }
	Employee(const string& sName, int nLimit) : m_sName(sName), m_nApprovalLimit(nLimit) { }
	virtual Handler* setNext(Handler* next) override {
		this->next = next;
		return next;
	}
	virtual void handle(PurchaseRequest& purchaseRequest) override {
		if (next != nullptr)
			next->handle(purchaseRequest);
	}
	void approve(PurchaseRequest& purchaseRequest) {
		purchaseRequest.processPR(m_sName);
	}
};

class Junior : public Employee {
public:
	Junior() : Employee("Junior", 500) {}
	void handle(PurchaseRequest& purchaseRequest) override {
		cout << m_sName << "[ ";
		if (purchaseRequest.getAmount() <= m_nApprovalLimit) {
			cout << "Y ] ";
			approve(purchaseRequest);
		}
		else {
			cout << "N ] ";
			Employee::handle(purchaseRequest);
		}
	}
};

class Senior : public Employee {
public:
	Senior() : Employee("Senior", 1500) {}
	void handle(PurchaseRequest& purchaseRequest) override {
		cout << m_sName << "[ ";
		if (purchaseRequest.getAmount() <= m_nApprovalLimit) {
			cout << "Y ] ";
			approve(purchaseRequest);
		}
		else {
			cout << "N ] ";
			Employee::handle(purchaseRequest);
		}
	}
};

class Manager : public Employee {
public:
	Manager() : Employee("Manager", 3000) {}
	void handle(PurchaseRequest& purchaseRequest) override {
		cout << m_sName << "[ ";
		if (purchaseRequest.getAmount() <= m_nApprovalLimit) {
			cout << "Y ] ";
			approve(purchaseRequest);
		}
		else {
			cout << "N ] ";
			Employee::handle(purchaseRequest);
		}
	}
};

class ApprovalHelper {
public:
	void approvalWorkflow(Handler* handler) {
		handler->setNext(new Senior())->setNext(new Manager());
		vector<PurchaseRequest> vPRs{ PurchaseRequest(200), PurchaseRequest(600), PurchaseRequest(1600), PurchaseRequest(5000) };
		for (auto& PR : vPRs) {
			handler->handle(PR);
			cout << endl;
			PR.getStatus();
		}
	}
};