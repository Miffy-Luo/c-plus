#include <iostream>
#include <string>
#include <queue>

using namespace std;

class StackInfo
{
public:
    template<typename T>
    void push(const T& value);
    
    template<typename T>
    void pop(T& value);

private:
    queue<void*> queue;

    template<typename T>
    string getType(const T& value)
    {
        return typeid(value).name();
    }
};

template<typename T>
inline void StackInfo::push(const T& value)
{
    T* ptr = new T(value);
    queue.push(ptr);
}

template<typename T>
inline void StackInfo::pop(T& value)
{
    T* ptr = static_cast<T*>(queue.front());
    value = *ptr;
    delete ptr;
    queue.pop();
}
