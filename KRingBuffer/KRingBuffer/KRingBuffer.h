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
    size_t _capacity; // ����
    size_t _size; // ��С
    int* read_index; // ��ָ��
    int* write_index; // дָ��
    void expandCapacity(); // ��չ��������С��ʵ���߼�
    void shrink(); // �Զ�������������С��ʵ���߼�
    void resize(size_t newSize);
};
