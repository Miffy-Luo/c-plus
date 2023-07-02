#include<iostream>
#include<vector>
#include"KArray.h"
using namespace std;

int main(){
	auto arr = KArray();
	arr.reserve(4);
	arr.push(1);
	 arr.push(2);
	arr.insert(1, 3);
	arr.remove(1);
	arr.pop();
	//arr.clear();
	cout << arr << endl;
	int index = arr.findIndex(1);
	cout << index << endl;
}