#include<iostream>
#include"KRingBuffer.h"

using namespace std;

int main() {
	auto a = new KRingBuffer(3);
	int arr[] = { 1, 2, 3, 4 };
	a->write(arr, 4);
	cout << a->getCapacity() << endl;
	a->printBuffer();
}