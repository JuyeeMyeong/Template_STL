#pragma once
#include <iostream>
#include <algorithm> // sort 함수 사용용

template <typename T>
class SimpleVector
{
private:
    T* data;
    int currentSize;
    int currentCapacity;
    void resize(int newCapacity); // 배열의 크기보다 정수가 작으면 아무 동작 안하고 크면 재할당 

public:
    SimpleVector(int size = 10); //생성자
    SimpleVector(const SimpleVector& other); //복사 생성자

    ~SimpleVector(); //소멸자

    int size() const; // 원소 개수 반환

    int capacity() const; // 내부 배열 크기 반환 

    // 인자로 받은 원소를 맨 뒤에 추가
    void push_back(const T& value);
    // 마지막 원소 제거 
    void pop_back();
    // 내부 데이터 정렬 
    void sortData();
};