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

typedef int ElementType;

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

struct Node {
	ElementType Element;
	PtrToNode Next;
};

Stack CreateStack();
void Push(ElementType X, Stack S);
ElementType Pop(Stack S);
void PrintStack(Stack S);


Stack CreateStack() {
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	S->Element = 0;
	S->Next = NULL;

	return S;
}


void Push(ElementType X, Stack S) {
	PtrToNode Tmp;
	Tmp = (PtrToNode)malloc(sizeof(struct Node));
	Tmp->Element = X;
	Tmp->Next = S->Next;
	S->Next = Tmp;
}

ElementType Pop(Stack S) {
	PtrToNode Tmp;
	ElementType X;

	Tmp = S->Next;
	X = Tmp->Element;
	S->Next = Tmp->Next;
	free(Tmp);

	return X;
}

void PrintStack(Stack S) {
	PtrToNode Tmp;
	Tmp = S;
	while (Tmp->Next != NULL) {
		printf(" %d ", Tmp->Next->Element);
		Tmp = Tmp->Next;
	}
}


int main() {

	Stack S;

	S = CreateStack();

	Push(1, S);
	Push(2, S);
	Push(3, S);
	Push(4, S);

	cout << "==== 1 ====" << endl;
	PrintStack(S);


	Pop(S);

	cout << endl << "==== 2 ====" << endl;
	PrintStack(S);

	return 0;
}