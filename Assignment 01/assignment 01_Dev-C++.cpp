#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    char name[100];
    int student_ID;
    int status; // 0 or 1
    Position next;
};

List CreatList(); 

Position Insert(const char* name, int student_ID, int status, List L, Position P);  

void StatusCheck(List L, int del); // by status
int Delete(List L, Position P); 

Position FindPrevious(int student_ID, List L); // by student_ID
void PrintNode(int student_ID, List L);

void PrintList(List L);  


// =================================================================================== //

List CreatList() {

    List L;
    L = (List)malloc(sizeof(struct Node)); 

    strcpy(L->name, ""); 
    L->student_ID = 0;
    L->status = 0;
    L->next = NULL;

    return L;
}

// =================================================================================== //


Position Insert(const char* name, int student_ID, int status, List L, Position P) {
    // P -> P2
    Position Tmp; 
    Tmp = (Position)malloc(sizeof(struct Node));
    strcpy(Tmp->name, name); 
    Tmp->student_ID = student_ID;
    Tmp->status = status;
    Tmp->next = P->next; // Tmp -> P2
    P->next = Tmp; // P -> Tmp

    // P -> Tmp -> P2
    return Tmp;
}

// =================================================================================== //

void PrintList(List L) {

    Position P = L; 
    cout << "  	     Name" << "    student_ID" << "  Status" << endl;
    while (P->next != NULL) {
        printf("	 %13s %10d %5d\n", P->next->name, P->next->student_ID, P->next->status);
        P = P->next;
    }
}

// =================================================================================== //

int Delete(List L, Position P) {

    // P->Tmp->P2
    Position Tmp;

    Tmp = P->next;
    P->next = Tmp->next; 

    free(Tmp); // Tmp (X)

    // P->P2, Tmp (X)
    return 1;
}


void StatusCheck(List L, int del) { // by status 1
    Position P = L;
    
    while (P->next != NULL) {
        if (P->next->status == del) 
            Delete(L,P);
        else
            P = P->next; 
    }

}

// =================================================================================== //


Position FindPrevious(int student_ID, List L) {

    Position P = L;
    while (P->next != NULL && P->next->student_ID != student_ID)
        P = P->next; 

    return P;
}

void PrintNode(int student_ID, List L) { 

    Position P = FindPrevious(student_ID, L);
    cout << "  	     Name" << "    student_ID" << "  Status" << endl;
    printf("	 %13s %10d %5d\n", P->next->name, P->next->student_ID, P->next->status);
}

int main() {

    // In the main function, execute your function following the below process.

    List L;
    cout << "=============== Create a linked list ===============" << endl;
    L = CreatList(); // Create a linked list
    cout << endl;

    cout << "=================== Insert a node ===================" << endl;
    Insert("Gildong Hong", 123456789, 0, L, L); // Insert a node (¡®Gildong Hong¡¯, 123456789, 0)
    Insert("Gildong Kim", 234567891, 1, L, L); // Insert a node (¡®Gildong Kim¡¯, 234567891, 1)
    Insert("HyunTae Jo", 201921438, 1, L, L); // Insert a node (your name, your id, 1)
    Insert("Gildong Lee", 345678912, 0, L, L); // Insert a node (¡®Gildong Lee¡¯, 345678912, 0)
    Insert("Gildong Park", 456789123, 1, L, L); // Insert a node (¡®Gildong Park¡¯, 456789123, 1)
    Insert("Gildong Choi", 567891234, 0, L, L); // Insert a node (¡®Gildong Choi¡¯, 567891234, 0)

    PrintList(L); // Print all elements in the linked list
    cout << endl;

    cout << " == Print the node that contains your information == " << endl;

    PrintNode(201921438, L); // Print the node that contains your information
    cout << endl;

    cout << " ======== Delete all the nodes with status 1 ========" << endl;
    StatusCheck(L,1); // Delete all the nodes with status 1

    PrintList(L); // Print all elements in the linked list
    cout << endl;


    return 0;
}

