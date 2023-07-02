#include<iostream>
#include "KString.h"

using namespace std;

int main() {
	auto str1 = KString("test1");
	auto str2 = KString("test2,test3");
	str1 = "test3";
	int len = str1.len();
	KString sub1 = str1.sub(1, 2);
	str1.append("append");
	bool equal = str1 == str2;
	int index = str1.find("3");
	cout << str1 << endl;
	cout << str2 << endl;
 	KString* ret = str2.split(",");
	cout << ret[0] << endl;
}