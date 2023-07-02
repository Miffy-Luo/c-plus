#pragma once
#include <iostream>
/*
实现string以下api，内部不能使用string，只能用数组存字符
auto str1 = CustomString("test1");
auto str2 = CustomString("test2, test3");
str1 = "test3";
int len = str1.len();
CustomString sub1 = str1.sub(1,2);
str1.append("append");
bool equal = str1 == str2;
int index = str1.find("es");
CustomString* ret = str2.split(",");
*/

class KString
{
public:
	KString();
	KString(const char* cstr);
	~KString();
	int len();
	KString sub(int begin, int end);
	void append(const char* str);
	bool operator==(KString& str);
	int find(const char* str);
	KString* split(const char* str);
	friend std::ostream& operator<<(std::ostream& out, KString& str);
	KString& operator=(const KString& str);

private:
	char* m_data;
	int _size = 0;
	static size_t npos;
	inline int getLength(const char* str) {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		return len;
	}
	int* build_next(const char* str);
};

