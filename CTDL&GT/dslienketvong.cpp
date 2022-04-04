#include<iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
};

struct CircleLinkedList {
	Node *head;
	Node *tail;
};

void init (CircleLinkedList &ls) {
	ls.head = NULL;
	ls.tail = NULL;
}
 Node *createNode (int x) {
 	Node *p = new Node;
 	p->next = NULL;
 	p->value = x ;
 	
 	return p;
 }
 
void addFirst(CircleLinkedList &ls, int x) {
	Node *p = createNode(x);
	if(ls.head == NULL) {
		ls.head = ls.tail = p;
		ls.tail->next = ls.head;  
	}
	else {
		p->next = ls.head;
		ls.head = p;
		ls.tail->next = ls.head;
	}
}
 
void output (const CircleLinkedList ls ) {

	if(ls.head != NULL) {
		Node *p = ls.head;
		do {
			cout <<p->value<<"\t";
			p = p->next;
		}while (p != ls.head);
	}
} 
int main() {
	CircleLinkedList ls;
	init(ls);
	
	addFirst(ls, 9);
	addFirst(ls, 10);
	
	output(ls);
	
	return 0;
}

