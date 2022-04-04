#include<iostream>
#include<string>

using namespace std;

struct Node {
	int data;
	Node *next;
};

typedef struct Node *queue;

bool isEmpty(queue q) {
	return (q==NULL);
}

Node *createNode(int data) {
	Node *p = new Node();
	if(p == NULL) {
		return p;
	}
	p->next = NULL;
	p->data = data;
}    

void enQueue(queue &q, int data) {
	Node *p = createNode(data);
	if(q == NULL){
		q = p;
	}
	else {
		Node *ptr = q;
		while(ptr != NULL && ptr->next != NULL){//tim node cuoi cung cua ds
			ptr = ptr->next;
		}
		//ptr chinh la node cuoi cung trong dslk
		ptr->next = p;
	}
}

int peek(queue q){
	if(!isEmpty(q)){
		return q->data;
	}
	else {
		return 0;
	}
}
int deQueue(queue &q){
	if(!isEmpty(q)){
		int data = q->data;
		Node *p = q;
		q = q->next;
		delete(p);
		return data;
	}
	else {
		return 0;
	}
}

int main () {
	queue q = NULL;
	enQueue(q, 20);
	enQueue(q,64);
	
	cout<<"peek:"<<peek(q)<<endl;
	while(!isEmpty(q))  {
		int data = peek(q);
		deQueue(q);
		cout<<" "<<data<<endl;	
	}
	cout<<"peek:"<<peek(q)<<endl;
	return 0;
}
