#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdbool.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <map>
#include <stdio.h>
#include <unordered_set>
#include <set>
using namespace std;

struct CircularQueue;

typedef int ElementType;
typedef struct CircularQueue *Queue;

// 구조체 선언
struct CircularQueue {
	ElementType *Array;
	int Front;
	int Rear;
	int Size;
	int Capacity;
};

// 함수 선언
int isEmpty(Queue Q); 
int isFull(Queue Q);
Queue CreateQueue(int MaxSize); // 큐 생성
void MakeEmpty(Queue Q); // 큐 비우기
int CheckIdx(int Index, Queue Q); // 큐를 삽입, 제거를 위한 idx 찾기
void Enqueue(ElementType X, Queue Q); // 큐 추가
ElementType Dequeue(Queue Q); // 큐 삭제
ElementType GetFront(Queue Q); // 큐의 Front 반환
ElementType GetRear(Queue Q); // 큐의 Rear 반환
void PrintQueue(Queue Q); // 큐 출력
void PrintArray(Queue Q); // 리스트 출력


/////////////////////////////////////////////////////////////////////////////////////////////////////
// 큐 생성
Queue CreateQueue(int MaxSize) {

	Queue Q;
	Q = (Queue)malloc(sizeof(struct CircularQueue)); // 큐 메모리 할당
	Q->Capacity = MaxSize; // Capacity = Maxsize
	Q->Array = (ElementType*)malloc(Q->Capacity*sizeof(ElementType)); // ElementType의 크기 x Capacity 의 메모리만큼 할당

	for (int i = 0; i < Q->Capacity; i++)
		Q->Array[i] = NULL; // 초기화

	Q->Size = 0; // Size = 0
	Q->Front = 1; // Front = 1
	Q->Rear = 0; // Rear = 0 (Enqueue를 하면서 Rear가 증가한 후 같아져야 하므로 Front보다 1작음.)

	return Q;

}

// 큐가 비어있는가?
int isEmpty(Queue Q) {
	return (Q->Size == 0); // 큐의 크기가 0이면 True
}

// 큐가 가득 차있는가?
int isFull(Queue Q) {
	return (Q->Size == Q->Capacity); // 큐의 크기가 최대치라면 True
}


// 큐 초기화
void MakeEmpty(Queue Q) {

	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;

}


// Enqueue, Dequeue를 실행할 때, 가장 마지막 인덱스보다 커지면 0으로 초기화를 해야한다.
int CheckIdx(int Index, Queue Q) {

	// 인덱스와 Capacity를 비교 (인덱스는 Capacity-1까지 존재하므로)
	if (++Index == Q->Capacity)
		Index = 0; // 인덱스 초기화

	return Index; // 인덱스에 1추가

}


// 큐 추가
void Enqueue(ElementType X, Queue Q) {
	
	// 큐가 가득 차있으면
	if (isFull(Q)) {
		printf("Queue is full\n");
		return; // 종료
	}

	Q->Size++; // 사이즈 1 증가
	Q->Rear = CheckIdx(Q->Rear, Q); // Rear -> CheckIdx를 통해 0으로 초기화 or 1 증가
	Q->Array[Q->Rear] = X; // 큐의 Array[변경된 Rear]에 X를 추가

}


// 큐 삭제
ElementType Dequeue(Queue Q) {

	ElementType Y = -9999;
	
	// 큐가 비어있다면
	if (isEmpty(Q)) {
		printf("Queue is Empty\n");
		return Y;
	}
	
	Q->Size--; // 사이즈 1 감소
	// Y = 지워질 원소( 큐의 Array[Front] )
	Y = GetRear(Q); // Y = Q->Array[Q->Front];
	Q->Front = CheckIdx(Q->Front, Q); // Front -> CheckIdx를 통해 0으로 초기화 or 1 증가
	
	return Y;

}

// Front 반환
ElementType GetFront(Queue Q) {
	return (Q->Array[Q->Front]);
}

// Rear 반환
ElementType GetRear(Queue Q) {
	return (Q->Array[Q->Rear]);
}

// 큐 출력
void PrintQueue(Queue Q) {

	int i = 0;
	int idx = Q->Front; // idx = Front부터 시작

	while (i < Q->Size) {
		printf(" %2d ", Q->Array[idx]);
		idx = CheckIdx(idx, Q); // idx = CheckIdx를 통해 0으로 초기화 or 1 증가
		i++;
	}
	printf("\n");
}

// 배열 출력
void PrintArray(Queue Q) {
	for (int i = 0; i < Q->Capacity; i++) 
		printf(" %2d ", Q->Array[i]);
	printf("\n");
}



int main() {

	// 큐 생성
	Queue Q;
	Q = CreateQueue(10);

	// 큐 추가
	Enqueue(1, Q);
	Enqueue(3, Q);
	Enqueue(4, Q);

	PrintQueue(Q); // 큐 출력
	PrintArray(Q); // 배열 출력


	cout << "==================== 1 ====================" << endl;

	// 큐 추가 (MaxSize만큼)
	Enqueue(5, Q);
	Enqueue(8, Q);
	Enqueue(10, Q);
	Enqueue(11, Q);
	Enqueue(12, Q);
	Enqueue(14, Q);
	Enqueue(16, Q);

	PrintQueue(Q); // 큐 출력
	PrintArray(Q); // 배열 출력


	cout << "==================== 2 ====================" << endl;

	// 큐 제거
	Dequeue(Q);
	Dequeue(Q);

	PrintQueue(Q); // 큐 출력
	PrintArray(Q); // 배열 출력


	return 0;
}