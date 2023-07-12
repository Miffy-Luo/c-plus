#include "KList.h"
#include<iostream>

using namespace std;
KList::KList()
{
	cout << "constructor" << endl;
	pHead = nullptr;
	pTail = nullptr;
	_size = 0;
}

KList::~KList()
{
	cout << "destructor" << endl;
	popAll();
}

Node* KList::push(int data)
{
	Node* pNode = new Node(data);
	if (pHead == nullptr) {
		pHead = pTail = pNode;
	}
	pTail->next = pNode;
	pNode->prev = pTail;
	pTail = pNode;
	_size++;
	return pNode;
}

Node* KList::insert(Node* node, int data)
{
	if (node == nullptr||node->next==nullptr) {
		return push(data);
	}
	Node* pNode = new Node(data);
	pNode->prev = node;
	pNode->next = node->next;
	if (node->next != nullptr) {
		node->next->prev = pNode;
		node->next = pNode;
	}
	_size++;
	return pNode;
}

Node* KList::find(int targetData)
{
	Node* temp = pHead;
	while (temp != nullptr) {
		if (temp->data == targetData) {
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

void KList::remove(Node* node)
{
	if (node == nullptr) {
		return;
	}
	node->prev->next = node->next;
	if (node->next != nullptr) {
		node->next->prev = node->prev;
	}
	if (node == pHead) {
		pHead = node->next;
	}
	if (node == pTail) {
		pTail = node->prev;
	}
	delete node;
}

void KList::popAll()
{
	Node* temp = pHead;
	while (temp != nullptr)
	{
		Node* Next = temp->next;
		delete temp;
		temp = Next;
	}
	pHead = nullptr;
	pTail = nullptr;
}

void KList::display()
{
	Node* temp = pHead;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
