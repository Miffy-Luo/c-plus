#include<iostream>
#include"KRingBuffer.h"

using namespace std;

int main() {
	cout <<  "Capacity is too small: " <<endl;
	auto minRingBuffer = new KRingBuffer(3);
	cout << "new a ringbuffer with capacity : " << minRingBuffer->getCapacity() << endl;
	int arr[] = { 1, 2, 3, 4 };
	minRingBuffer->write(arr, 4);
	cout << "after write, capacity is : " << minRingBuffer->getCapacity() << endl;
	minRingBuffer->printBuffer();
	cout << endl;

	auto data = minRingBuffer->read(3);
	cout << "read : ";
	for (size_t i = 0; i < 3; i++)
	{
		cout << data[i] << " ";
	}

	cout << endl;
	cout << endl;

	cout << "Capacity is too large: " << endl;
	auto maxRingBuffer = new KRingBuffer(10);
	cout << "new a ringbuffer with capacity : " << maxRingBuffer->getCapacity() << endl;
	maxRingBuffer->write(arr, 4);
	cout << "after write, capacity is : " << maxRingBuffer->getCapacity() << endl;
}