#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#
#include <stdlib.h>
#include <stack>
#include <queue>

#include <utility>
#include <functional>

#include <stdio.h>

using namespace std;


typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// 노드 선언
struct Node {
    ElementType Element;
    Position Next;
};


List CreatList(); // 배열 생성
Position Insert(ElementType X, List L, Position P);  // 노드 삽입
int Delete(ElementType X, List L); // 노드 삭제
Position FindPrevious(ElementType X, List L);
Position Find(ElementType X, List L); // 배열 찾기
void PrintList(List L); // 배열 출력

// =================================================================================== //

// Linked List 생성 함수
List CreatList() {

    List L; 
    // malloc : 요청한 크기의 바이트 할당 후 시작 주소 리턴
    L = (List)malloc(sizeof(struct Node)); // Node의 크기만큼 동적 할당

    // . 은 클래스의 멤버를 직접 접근
    // -> 은 포인터를 통해 멤버를 접근
    L->Element = 0; // dummy head 생성
    L->Next = NULL; // 아무것도 가르키지않는다.

    return L;
}

// =================================================================================== //

// 노드 삽입 함수
Position Insert(ElementType X, List L, Position P) {
    // P -> P2

    Position Tmp; // 삽입할 빈 노드
    Tmp = (Position)malloc(sizeof(struct Node));

    Tmp->Element = X; // 값
    Tmp->Next = P->Next; // Tmp -> P2
    P->Next = Tmp; // P -> Tmp

    // P -> Tmp -> P2
    return Tmp;
}

// =================================================================================== //

// 해당 값의 위치를 찾는 함수
Position FindPrevious(ElementType X, List L) {

    Position P = L;
    // P의 다음 노드가 없고 P의 다음 노드가 원하는 값을 가질 때까지
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next; // 처음부터 탐색

    return P;
}
// 노드 삭제 함수
int Delete(ElementType X, List L) {

    // P->Tmp->P2
    Position P, Tmp;
    P = FindPrevious(X, L);

    // P->P2로 변경
    Tmp = P->Next; 
    P->Next = Tmp->Next; // P->Next->Next와 같은 코드
    // free : 메모리 할당 해제
    free(Tmp); // Tmp (X)

    // P->P2, Tmp (X)
    return 1;

}

// =================================================================================== //

Position Find(ElementType X, List L) {

    Position P = L->Next;
    while (P->Element != X)
        if (P->Next != NULL)
            P = P->Next;

    return P;
}

// =================================================================================== //

void PrintList(List L) {

    Position P = L;
    // 다음 노드가 없을 때까지 출력 
    printf("DummyHead -> ");
    while (P ->Next != NULL) {
        printf("%d -> ", P->Next->Element); // 처음 값은 dummy head
        P = P->Next;
    }
    printf("NULL\n");

}


// 메인 함수
int main() {

    List L;
    L = CreatList();


    cout << "#### 1. 추가 ####" << endl;;
    Insert(10, L, L); // 10 -> NULL
    PrintList(L);
    Insert(5, L, L); // 5 -> 10 -> NULL
    PrintList(L);
    Insert(15, L, L); // 15 -> 5 -> 10 -> NULL
    PrintList(L);

    cout << endl;;
    cout << "#### 2. 삽입 ####" << endl;;

    Position P;
    P = Find(5, L); // 5의 위치를 찾고
    Insert(20, L, P); // 20을 5 다음으로 연결
    PrintList(L); // 15 -> 5 -> 20 -> 10 -> NULL
    
    cout << endl;;
    cout << "#### 3. 제거 ####" << endl;;

    Delete(5, L); // 5 제거
    PrintList(L); // 15 -> 20 -> 10-> NULL



    return 0;
}
