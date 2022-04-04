#include<iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};
typedef struct Node *stack;

bool isEmpty(stack s) {
	return (s == NULL);
} 

Node *creatNode(int data) {
	Node *p = new Node();
	if(p == NULL){
		return NULL;
	}
	else {
		p->data = data;
		p->next = NULL;
		
		return p;
	}
}

void push(stack &s, int data) {
	Node *ptr = creatNode(data);
	if(isEmpty(s)){
		s = ptr;
	}	
	else {
		ptr->next = s;
		s = ptr; 
	}
}

int top(stack s) {
	if(!isEmpty(s)){
		return s->data;
	}
	else {
		cout<<"stack is empty " <<endl;
	}
}

int pop (stack &s) {
	if(!isEmpty(s)){
		int data = s->data; // lay gia tri data cua not hien thoi 
		Node *x = s; //gan gia tri node cho x
		s = s->next;//di chuyen sang not hien thoi
		delete(x);//giai phong bo nho
		return data;
	}
	else {
		cout<<"stack is empty " <<endl;
	}
}

int main(){
	stack s; 	
	push(s,100);
	push(s,-99);
	push(s,35);
	push(s,26);
	cout<<"Top: "<<top(s)<<endl;
	pop(s);
	while(!isEmpty(s)) {
		int data = top(s);
		pop(s);
		cout<< data <<"<--";		
	}
	cout<<endl;
	return 0;
}
