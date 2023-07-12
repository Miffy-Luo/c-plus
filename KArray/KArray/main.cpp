#include<iostream>
#include<vector>
#include <list>
#include"KArray.h"
#include "KList.h"
using namespace std;

int main(){
	cout << "-------- KArray --------" << endl;
	auto arr = KArray();
	arr.reserve(4);
	arr.push(1);
	arr.push(2);
	arr.insert(1, 3);
	arr.remove(1);
	arr.pop();
	arr.clear();
	cout << arr << endl;
	int index = arr.findIndex(1);
	cout << index << endl;

	cout << "-------- KList --------" << endl;
	auto list1 = KList();
	auto node1 = list1.push(1);
	auto node2 = list1.push(2);
	auto node3 = list1.insert(node2, 3);
	auto ret = list1.find(2);
	cout << ret << endl;
	list1.remove(node2);
	list1.display();
	list1.popAll();
}