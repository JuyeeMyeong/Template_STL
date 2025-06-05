#include "Simplevector.h"

// 생성자: 기본으로 크기 10인 배열, size에 해당되는 크기의 배열 생성성
template <typename T>
SimpleVector<T>::SimpleVector(int size = 10)
    : currentSize(0), currentCapacity(size)
{
    data = new T[currentCapacity]; 
}

// 복사 생성자 
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
    : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
{
    data = new T[currentCapacity]; // 새로 메모리 할당 
    for(int i = 0; i < currentSize; ++i) // 데이터 원소 복사 
    {
        data[i] = other.data[i];
    }
}

// 동적 할당된 메모리 해제
template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] data;
}

// 현재 원소의 개수 반환환
template <typename T>
int SimpleVector<T>::size() const
{
    return currentSize;
}

// 현재 내부 배열의 크기 반환환
template <typename T>
int SimpleVector<T>::capacity() const
{
    return currentCapacity;
}

template <typename T>
void SimpleVector<T>::push_back(const T& value)
{
    if (currentSize == currentCapacity)
    {
        if (currentCapacity == 0) // 혹시 모르니 용량이 0일 때는 기본 용량 (10)으로 설정정
        {
            currentCapacity = 10;
        } else
        {
            currentCapacity *= 2;
        }
        resize(currentCapacity);
    }

    ++currentSize;
    data[currentSize - 1] = value;
}

template <typename T>
void SimpleVector<T>::pop_back()
{
    if (currentSize > 0)
    {
        //data[currentSize - 1] = nullptr;
        --currentSize;
    }
}

template <typename T>
void SimpleVector<T>::sortData()
{
    std::sort(data, data + currentSize);
}

template <typename T>
void SimpleVector<T>::resize(int newCapacity)
{
    T* copiedData = new T[newCapacity];

    for(int i = 0; i < currentSize; ++i)
    {
        copiedData[i] = data[i]; // 데이터 값 복사
    }
    delete[] data; // 메모리 해제
    data = copiedData;
    currentCapacity = newCapacity;
}