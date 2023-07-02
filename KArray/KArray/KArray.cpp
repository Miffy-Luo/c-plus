#include "KArray.h"
#include <ostream>

KArray::KArray()
{
	_data = nullptr;
	_size = 0;
	_capacity = 0;
}

KArray::~KArray()
{
	delete[] _data;
}

// 调整vector对象的容量
void KArray::reserve(const size_t newCapacity)
{
	if (newCapacity <= _capacity) {
		return;
	}

	int* tempData = new int[newCapacity];
	for (size_t i = 0; i < _size; i++)
	{
		tempData[i] = _data[i];
	}
	delete[] _data;
	_capacity = newCapacity;
	_data = tempData;
}

void KArray::push(const int target)
{
	if (_size == _capacity) {
		reserve(_capacity == 0 ? 1 : _capacity * 2);
	}
	_data[_size++] = target;
}

void KArray::insert(const size_t index, const int target)
{
	if (index >= _size) {
		reserve(_capacity == 0 ? 1 : _capacity * 2);
	}
	for (size_t i = _size; i > index; i--) {
		_data[i] = _data[i - 1];
	}
	_data[index] = target;
	_size++;
}

void KArray::remove(const size_t index)
{
	if (index >= _size) {
		return;
	}
	for (size_t i = index; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	_size--;
}

void KArray::pop()
{
	if (_size == 0) {
		return;
	}
	_size--;
}

void KArray::clear()
{
	_size = 0;
}

int KArray::findIndex(const size_t target)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] == target) {
			return i;
		}
	}
	return -1;
}

std::ostream& operator<<(std::ostream& out, KArray& arr)
{
	for (int i = 0; i <arr._size; i++)
		out << arr._data[i]<<" ";
	return out;
}
