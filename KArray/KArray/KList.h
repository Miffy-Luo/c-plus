#pragma once

/*
实现双向链表以下api
auto list1 = new CustomList();
auto node1 = list1.push(1);
auto node2 = list1.push(2);
auto node3 = list1.insert(node2, 3);
auto ret = list1.find(2);
list1.remove(node2);
list1.popAll();
*/
struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int data) :data(data), next(nullptr), prev(nullptr) {}
};

class KList
{
public:
	KList();
	~KList();
	Node* push(int data);
	Node* insert(Node* node, int data);
	Node* find(int targetData);
	void remove(Node* node);
	void popAll();
	void display();

private:
	Node* pHead;
	Node* pTail;
	size_t _size;
};

