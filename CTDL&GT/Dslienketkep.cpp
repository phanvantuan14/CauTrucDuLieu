#include<iostream>
using namespace std;

struct Node{
	int value;
	Node *next;//tro den node tiep theo
	Node *prev;//tro den phan dau cua node
};

struct DoubleLinkedList {
	Node *head;// luon tro toi node dau tien
	Node *tail;// luon tro toi node cuoi cung 
};

void init (DoubleLinkedList &ls) {
	ls.head = NULL;
	ls.tail = NULL;
}
Node *createNode(int x) {
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	p->prev = NULL;
	
	return p;
}

void addFrist(DoubleLinkedList &ls, int x){
	Node *p = createNode(x);//node dc tao moi
	
	if(ls.head == NULL){
		ls.head = ls.tail = p;	
	}
	else{
		p->next = ls.head;
		ls.head->prev = p;
		ls.head = p;	
	}
}

void addLast(DoubleLinkedList &ls, int x ) {
	Node *p = createNode(x);
	if(ls.head ==NULL) {
		ls.head = ls.tail = p;	
	}
	else{
		p->prev = ls.tail;
		ls.tail->next = p;
		ls.tail = p;	
	}
}

void addAfter(DoubleLinkedList &ls, int v, int x ) {
	Node *q = ls.head;
	while( q!=NULL && q->value != v){
		q= q->next;	
	}
	if(q != NULL) {
		if(q == ls.tail) { //them sau ptu cuoi cung
			addLast(ls,x);
		}
		else {
			Node *p = createNode(x);
			p->next = q->next;
			q->next->prev = p;
			
			q->next = p;
			p->prev = q;  	
		}				
	}
}

void deleteFirst(DoubleLinkedList &ls){
	if(ls.head !=NULL) {
		Node *p = ls.head;
		ls.head = p->next;
		
		if(p->next == NULL){ //ds co 1 ptu 
			ls.tail = NULL;
			ls.head = NULL;
		}
		else {
			p->next->prev = NULL;
			p->next = NULL;	
		}
		delete(p);
	}
}
void outputLeftToRight(DoubleLinkedList ls) {
	Node *p = ls.head;
	while(p!=NULL) {
		cout<<p->value<<"\t";
		p = p->next;
	}
	cout<<endl;
}
void outputRightToLeft(DoubleLinkedList ls) {
	Node *p = ls.tail;
	while(p!=NULL) {
		cout<<p->value<<"\t";
		p = p->prev;
	}
	cout<<endl;
}

int main() {
	DoubleLinkedList ls;
	init(ls);
	
	addFrist(ls,4);
	addFrist(ls,9);
	addFrist(ls,5);
	addLast(ls,34);
	addAfter(ls,9,11);
	
	
//	outputLeftToRight(ls);
	outputRightToLeft(ls);
	
	return 0;
}
