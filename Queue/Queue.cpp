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

// Linked List 기본 구성
struct Node; // 노드
typedef int ElementType; // 노드에 들어갈 타입 = int
typedef struct Node *PtrToNode; // 다음 노드로 이어지는 포인터

// Queue를 위한 추가 설정
struct FrontRear;
typedef struct FrontRear* Queue;


struct Node {
	ElementType Element; // 원소
	PtrToNode Next; // 다음 노드로 이어지는 포인터
};

struct FrontRear {
	PtrToNode Front; // Front노드
	PtrToNode Rear; // Rear노드
};

// 함수 선언
Queue CreateQueue (); // Queue 생성
void Enqueue (ElementType X, Queue Q); // Queue 등록
ElementType Dequeue(Queue Q); // Queue 삭제
void PrintQueue(Queue Q); // 모든 Queue 출력


Queue CreateQueue() {

	Queue Q; // 새로운 큐 생성
	Q = (Queue)malloc(sizeof(struct FrontRear)); // 큐 메모리 동적 할당
	Q->Front = NULL; // Front 값 없음
	Q->Rear = NULL; // Rear 값 없음

	return Q;
}

void Enqueue(ElementType X, Queue Q) {

	PtrToNode Tmp; // 새로운 노드 생성
	Tmp = (PtrToNode)malloc(sizeof(struct Node)); // 포인터 메모리 동적 할당
	Tmp->Element = X; // 원소 값
	Tmp->Next = NULL; // 다음 노드 연결 값

	// 비어 있는 큐라면 -> Q에는 노드가 이제 하나가 되었으므로
	if (Q->Front == NULL) {
		// Front, Rear 모두 같은 노드이다
		Q->Front = Tmp; 
		Q->Rear = Tmp;
		return;
	}
	// 비어 있는 큐가 아니라면 
	Q->Rear->Next = Tmp; // Rear(마지막)의 다음은 Tmp를 가르키고
	Q->Rear = Tmp; // Rear = Tmp로 변경

	// 과정 설명
	// Front -> ... -> Rear
	// Front -> ... -> Rear -> Tmp
	// Front -> ... -> Node -> Tmp(Rear)

}


ElementType Dequeue(Queue Q) {

	ElementType Y;
	// Front가 비어있다면 == Q가 비어있다면
	if (Q->Front == NULL) {
		// 제거할 노드가 없기에 강제 종료 (-9999)
		return -9999;
	}

	PtrToNode Tmp;
	Tmp = Q->Front; // Tmp = Front

	Q->Front = Tmp->Next; // 
	Y = Tmp->Element;

	if (Q->Front == NULL) {
		Q->Rear == NULL;
	}

	free(Tmp);

	return Y;

}


void PrintQueue(Queue Q) {

	// 큐가 비어있다면
	if (Q->Front == NULL) {
		cout << "NULL Queue" << endl;
		return;
	}

	PtrToNode Tmp;
	Tmp = Q->Front; // Front를 가리키는 포인터

	// 포인터가 마지막을 가르킬때까지
	while (Tmp != NULL) {
		cout << Tmp->Element << " "; // 원소 출력
		Tmp = Tmp->Next; // 포인터 다음으로
	}
	cout << endl;
}


// 메인 함수
int main() {
	
	Queue Q;
	Q = CreateQueue();

	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Enqueue(4, Q);
	Enqueue(5, Q);

	PrintQueue(Q);

	cout << "Dequeue" << endl;

	Dequeue(Q);

	PrintQueue(Q);


	return 0;
}