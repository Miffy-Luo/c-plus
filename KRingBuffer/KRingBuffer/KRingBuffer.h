#pragma once

class KRingBuffer {
public:
    KRingBuffer(size_t initialSize);
    ~KRingBuffer();
    size_t getSize() const;
    size_t getCapacity() const;
    void write(const int* data, size_t bytes);
    int* read(size_t bytes);
    void printBuffer();

private:
    int* _data;
    size_t _capacity; // 容量
    size_t _size; // 大小
    int* read_index; // 读指针
    int* write_index; // 写指针
    void expandCapacity(); // 扩展缓冲区大小的实现逻辑
    void shrink(); // 自动收缩缓冲区大小的实现逻辑
    void resize(size_t newSize);
};
