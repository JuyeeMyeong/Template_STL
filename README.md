# 템플릿 및 STL을 활용하여 Vector 직접 구현하기

## 프로젝트 가이드

이 프로젝트는 C++의 템플릿과 STL을 활용하여 STL의 Vector처럼 작동하는 SimpleVector 클래스를 구현한 과제이다.
sort의 경우 STL의 srot함수를 활용하여 정렬하였다.

템플릿을 적용하지 않은 경우, 이 예시처럼 같은 SimpleVector 클래스에 대해서 `다양한 타입` (예시에서는 int와 string 사용)을 사용하지
못하기 때문에, 각 타입에 대해 새 클래스를 별도로 작성해야 하는 일이 생긴다.
하지만, 템플릿을 적용하면 모든 타입에 대해 하나의 클래스로 작성이 가능해지기 때문에 `재사용`이 가능해진다.

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

---

## push_back 작동 방식
예시) 초기 용량 currentCapacity = 2, 현재 크기 currentSize = 2

  data  →  [ 10, 20 ]
            ↑    ↑
         index 0  1

---> 새로운 값 추가 `30`

1. currentSize == currentCapacity → resize() 호출
2. resize()는 더 큰 배열 생성 (예: currentCapacity *= 2 → 10)

  copiedData  →  [ 10, 20, ?, ?, ?, ?, ?, ?, ?, ? ]

3. 기존 메모리 해제: delete[] data
4. 새 배열로 교체: data = copiedData
5. 새로운 값 삽입: data[2] = 30
6. currentSize 증가: currentSize = 3

결과:

  data  →  [ 10, 20, 30, ?, ?, ?, ?, ?, ?, ? ]
                           ↑
                        currentSize = 3
