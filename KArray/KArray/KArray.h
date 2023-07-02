#pragma once
#include <ostream>

/*
实现数组以及一下api
auto arr = new CustomArray();
arr.reserve(4);
arr.push(1);
arr.push(2);
arr.insert(1, 3);
arr.remove(1);
arr.pop();
arr.clear();
int index = arr.findIndex(1);
*/
class KArray
{
public:
	KArray();
	~KArray();
	void reserve(const size_t size);
	void push(const int target);
	void insert(const size_t index,const int target);
	void remove(const size_t index);
	void pop();
	void clear();
	int findIndex(const size_t target);
	friend std::ostream& operator<<(std::ostream& out, KArray& arr);

private:
	size_t _size;
	size_t _capacity;
	int* _data;
};

