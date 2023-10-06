#include "KRingBuffer.h"
#include <iostream>
using namespace std;

KRingBuffer::KRingBuffer(size_t initialSize)
{
	_capacity = initialSize;
	_size = 0;
	_data = new int[initialSize];
	read_index = _data;
	write_index = _data;
}

KRingBuffer::~KRingBuffer()
{
	delete[] _data;
}

size_t KRingBuffer::getSize() const
{
	return _size;
}

size_t KRingBuffer::getCapacity() const
{
	return _capacity;
}
/**
*  写入数据
*  data 要写入的数据
*  bytes 要写入的数据的大小
*/
void KRingBuffer::write(const int* data, size_t bytes)
{
	for (size_t i = 0; i < bytes; i++)
	{
		if (_size < _capacity) {
			*write_index = data[i];
			write_index = _data + ((write_index - _data + 1) % _capacity);
			_size++;
		}
		else {
			expandCapacity();
			write(&data[i], bytes-i);
		}
	}
	if (_size < _capacity / 2) {
		shrink();
	}
}

int* KRingBuffer::read(size_t bytes)
{
	int* data = new int[bytes];
	if (_size < _capacity / 2) {
		shrink();
	}
	for (size_t i = 0; i < bytes; i++)
	{
		data[i] = *read_index;
		read_index = _data + ((read_index - _data + 1) % _capacity);
	}
	return data;
}

void KRingBuffer::printBuffer()
{
	auto temp = _data;
	cout << "Ring Buffer content is : ";
	for (size_t i = 0; i < _size; i++)
	{
		cout << temp[i] << " ";
	}
}

void KRingBuffer::expandCapacity()
{
	size_t newCapacity = _capacity * 2;
	resize(newCapacity);
}

void KRingBuffer::shrink()
{
	size_t shrinkSize = _capacity / 2;
	resize(shrinkSize);
}

void KRingBuffer::resize(size_t newSize)
{
	int* newData = new int[newSize];
	for (size_t i = 0; i < newSize; i++) {
		newData[i] = *(read_index++);
	}
	delete[] _data;

	_data = newData;
	_capacity = newSize;
	read_index = _data;
	write_index = _data + _size;
}
