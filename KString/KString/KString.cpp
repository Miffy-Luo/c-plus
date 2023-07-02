#include "KString.h"
#include <ostream>

inline
KString::KString() {
	m_data = new char[1];
	*m_data = '\0';
	_size = 0;
}

inline
KString::KString(const char* cstr) {
	if (cstr) {
		auto len = getLength(cstr);
		m_data = new char[len + 1];
		for (int index = 0; index < len; index++) {
			m_data[index] = cstr[index];
		}
		m_data[len] = '\0';
		_size = len;
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
		_size = 0;
	}
}

inline
KString::~KString() {
	if (m_data != nullptr) {
		delete[] m_data;
		m_data = nullptr;
		_size = 0;
	}
}

int KString::len()
{
	return this->_size;
}

KString KString::sub(int begin, int end)
{
	int beginIndex = begin > _size ? _size : begin;
	int endIndex = end < 0 ? 0 : end;
	int newStrLen = endIndex - beginIndex;
	if (newStrLen <= 0) {
		return "";
	}
	char* newStr = new char[newStrLen + 1];
	for (int i = 0; i < newStrLen; ++i) {
		newStr[i] = m_data[i + begin];
	}
	newStr[newStrLen] = '\0';
	return KString(newStr);
}

void KString::append(const char* str)
{
	auto strSize = getLength(str);
	char* temp = new char[_size + strSize + 1];
	for (int i = 0; i < _size; i++) {
		temp[i] = m_data[i];
	}
	delete[] this->m_data;
	for (int i = 0; i < strSize; i++) {
		temp[_size + i] = str[i];
	}
	_size += strSize;
	m_data = new char[_size + 1];
	for (int i = 0; i < _size; i++) {
		m_data[i] = temp[i];
	}
	m_data[_size] = '\0';
	delete[] temp;
	temp = nullptr;
}

bool KString::operator==(KString& str)
{
	int targetLen = str.len();
	if (targetLen != _size)
		return false;
	for (int i = 0; i < _size; i++) {
		if (m_data[i] != str.m_data[i])
			return false;
	}
	return true;
}

int KString::find(const char* str)
{
	auto next = build_next(str);
	auto i = 0;//主串中的指针
	auto j = 0;// 字串中的指针
	while (i < _size) {
		if (m_data[i] == str[j]) {// 字符匹配成功
			i++;
			j++;
		}
		else if (j > 0) { // 根据 next 数组跳过前面的重复字符
			j = next[j - 1];
		}
		else { // 字串第一个字符就失配
			i += 1;
		}
		if (j == getLength(str))
			return i - j;
	}
	return -1;
}

KString* KString::split(const char* str)
{
	if (str == "") return this;
	KString newStr = KString(m_data);
	newStr.append(str);
	KString* result = new KString[newStr._size];
	int pos = newStr.find(str);
	int i = 0;
	while (pos != -1) {
		auto temp = newStr.sub(0, pos);
		result[i].append(temp.m_data);
		newStr = newStr.sub(pos + 1, newStr._size);
		pos = newStr.find(str);
		i++;
	}
	return result;
}

KString& KString::operator=(const KString& str)
{
	if (this == &str)// 自我赋值检查
		return *this;
	delete[] m_data;
	m_data = NULL;
	_size = str._size;
	m_data = new char[_size + 1];
	for (int i = 0; i < _size; i++) {
		m_data[i] = str.m_data[i];
	}
	m_data[_size] = '\0';
	return *this;
}


int* KString::build_next(const char* str) {
	int* next = new int[getLength(str)]; // next 数组
	next[0] = 0;
	int prefix_len = 0; //当前共同前后缀长度
	int i = 1;
	while (i < getLength(str)) {
		if (str[prefix_len] == str[i]) {
			prefix_len += 1;
			next[i] = prefix_len;
			i++;
		}
		else {
			if (prefix_len == 0) {
				next[i] = prefix_len;
				i++;
			}
			else {
				prefix_len = next[prefix_len - 1];
			}
		}
	}
	return next;
}

std::ostream& operator<<(std::ostream& out, KString& s)
{
	for (int i = 0; i < s.len(); i++)
		out << s.m_data[i];
	return out;
}
