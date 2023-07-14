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
template<typename T>
class KArray
{
public:
	KArray() {
		_data = nullptr;
		_size = 0;
		_capacity = 0;
	}

	~KArray() {
		delete[] _data;
	}

	void reserve(const size_t size){
		if (size <= _capacity) {
			return;
		}

		int* tempData = new int[size];
		for (size_t i = 0; i < _size; i++)
		{
			tempData[i] = _data[i];
		}
		delete[] _data;
		_capacity = size;
		_data = tempData;
	}

	void push(const int target) {
		if (_size == _capacity) {
			reserve(_capacity == 0 ? 1 : _capacity * 2);
		}
		_data[_size++] = target;
	}

	void insert(const size_t index, const T target) {
		if (index >= _size) {
			reserve(_capacity == 0 ? 1 : _capacity * 2);
		}
		for (size_t i = _size; i > index; i--) {
			_data[i] = _data[i - 1];
		}
		_data[index] = target;
		_size++;
	}

	void remove(const size_t index) {
		if (index >= _size) {
			return;
		}
		for (size_t i = index; i < _size - 1; i++) {
			_data[i] = _data[i + 1];
		}
		_size--;
	}

	void pop() {
		if (_size == 0) {
			return;
		}
		_size--;
	}

	void clear() {
		_size = 0;
	}

	int findIndex(const T target) {
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == target) {
				return i;
			}
		}
		return -1;
	}

	friend std::ostream& operator<<(std::ostream& out, KArray& arr) {
		for (int i = 0; i < arr._size; i++)
			out << arr._data[i] << " ";
		return out;
	}

private:
	size_t _size;
	size_t _capacity;
	T* _data;
};

