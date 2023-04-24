#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;


struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// 노드 선언
struct Node {
    char name[100];
    int student_ID;
    int status; // 0 or 1
    Position next;
};

// 배열 생성
List CreatList(); 

// 노드 삽입
Position Insert(const char* name, int student_ID, int status, List L, Position P);  

// 노드 삭제
void StatusCheck(List L, int del); // by status
int Delete(List L, Position P); // 노드 삭제

// 노드 찾기 + 출력
Position FindPrevious(int student_ID, List L); // by student_ID
void PrintNode(int student_ID, List L); // 자신의 노드 출력

// 배열 출력
void PrintList(List L);  // 모든 노드 출력


// =================================================================================== //

// Linked List 생성 함수
List CreatList() {

    List L;
    // malloc : 요청한 크기의 바이트 할당 후 시작 주소 리턴
    L = (List)malloc(sizeof(struct Node)); // Node의 크기만큼 동적 할당

    // dummy head 생성
    strcpy_s(L->name, ""); 
    L->student_ID = 0;
    L->status = 0;
    L->next = NULL; // 아무것도 가르키지않는다.

    return L;
}

// =================================================================================== //

// 노드 삽입 함수
Position Insert(const char* name, int student_ID, int status, List L, Position P) {
    // P -> P2
    Position Tmp; // 삽입할 빈 노드 
    Tmp = (Position)malloc(sizeof(struct Node));
    strcpy_s(Tmp->name, name); // char형 입력방법
    Tmp->student_ID = student_ID;
    Tmp->status = status;
    Tmp->next = P->next; // Tmp -> P2
    P->next = Tmp; // P -> Tmp

    // P -> Tmp -> P2
    return Tmp;
}

// =================================================================================== //

// 모든 노드의 모든 값 출력
void PrintList(List L) {

    Position P = L;
    // 다음 노드가 없을 때까지 출력 
    cout << "      Name" << "    student_ID" << "  Status" << endl;
    while (P->next != NULL) {
        printf("%13s %10d %5d\n", P->next->name, P->next->student_ID, P->next->status);
        P = P->next;
    }
}

// =================================================================================== //

// 노드 삭제 함수
int Delete(List L, Position P) {

    // P->Tmp->P2
    Position Tmp;

    // P->P2로 변경
    Tmp = P->next;
    P->next = Tmp->next; // P->Next->Next와 같은 코드
    // free : 메모리 할당 해제
    free(Tmp); // Tmp (X)

    // P->P2, Tmp (X)
    return 1;
}

// status == del(0,1)인 노드를 찾고 Delete함수를 실행시키는 함수
void StatusCheck(List L, int del) { // by status 1
    Position P = L;
    // P의 다음 노드가 없고 P의 다음 노드가 원하는 값을 가질 때까지
    
    while (P->next != NULL) {
        if (P->next->status == del) // status == del이면 삭제 -> 노드가 줄어들기 때문에 다음으로 보낼 필요 X
            Delete(L,P);
        else
            P = P->next; // 아니라면 다음으로 
    }

}

// =================================================================================== //

// 해당 student_ID의 값을 가지는 노드의 바로 전 위치를 찾는 함수
Position FindPrevious(int student_ID, List L) {

    Position P = L;
    // P의 다음 노드가 없고 P의 다음 노드가 원하는 값을 가질 때까지
    while (P->next != NULL && P->next->student_ID != student_ID)
        P = P->next; // 처음부터 탐색

    return P;
}

// student_ID를 받아서 FindPrevious 함수를 통해 해당 노드의 정보를 출력하는 함수
void PrintNode(int student_ID, List L) { 

    Position P = FindPrevious(student_ID, L);
    cout << "      Name" << "    student_ID" << "  Status" << endl;
    printf("%13s %10d %5d\n", P->next->name, P->next->student_ID, P->next->status);

}

// 메인 함수
int main() {

    // In the main function, execute your function following the below process.

    List L;
    cout << "============= 배열 생성 =============" << endl;
    L = CreatList(); // Create a linked list
    cout << endl;

    cout << "============= 배열 추가 =============" << endl;
    Insert("Gildong Hong", 123456789, 0, L, L); // Insert a node (‘Gildong Hong’, 123456789, 0)
    Insert("Gildong Kim", 234567891, 1, L, L); // Insert a node (‘Gildong Kim’, 234567891, 1)
    Insert("HyunTae Jo", 201921438, 1, L, L); // Insert a node (your name, your id, 1)
    Insert("Gildong Lee", 345678912, 0, L, L); // Insert a node (‘Gildong Lee’, 345678912, 0)
    Insert("Gildong Park", 456789123, 1, L, L); // Insert a node (‘Gildong Park’, 456789123, 1)
    Insert("Gildong Choi", 567891234, 0, L, L); // Insert a node (‘Gildong Choi’, 567891234, 0)

    PrintList(L); // Print all elements in the linked list
    cout << endl;

    cout << "============= 배열 찾기 =============" << endl;

    PrintNode(201921438, L); // Print the node that contains your information
    cout << endl;

    cout << " ====== status가 1인 배열 삭제 ======" << endl;
    StatusCheck(L,1); // Delete all the nodes with status 1

    PrintList(L); // Print all elements in the linked list
    cout << endl;


    return 0;
}
