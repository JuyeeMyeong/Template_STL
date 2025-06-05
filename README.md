# 템플릿 및 STL을 활용하여 Vector 직접 구현하기

## 프로젝트 가이드

이 프로젝트는 C++의 템플릿과 STL을 활용하여 STL의 Vector처럼 작동하는 SimpleVector 클래스를 구현한 과제이다.
sort의 경우 STL의 srot함수를 활용하여 정렬하였다.

---

## 기능 소개

- `SimpleVector(int size = 10)` : 초기 크기를 지정하는 생성자 (default 크기 10)
- `SimpleVector(const SimpleVector& other)` : 복사 생성자
- `void push_back(const T& value)` : 마지막에 원소 추가 (용량 초과 시 기존 용량 늘리고 삽입)
- `void pop_back()` : 마지막 원소 제거
- `int size() const` : 현재 원소 개수 반환
- `int capacity() const` : 배열 용량 반환
- `void resize(int newCapacity)` : 용량 확장 (기존 값 유지)
- `void sortData()` : STL `sort` 함수로 정렬

---

## 파일 구성
``` less
├── main.cpp
├── SimpleVector.h       // 클래스 선언
├── SimpleVector.tpp     // 템플릿 활용 Vector 구현
```

헤더에서 `#include "SimpleVector.tpp"`를 추가하여 템플릿 본문을 포함시켰다.
