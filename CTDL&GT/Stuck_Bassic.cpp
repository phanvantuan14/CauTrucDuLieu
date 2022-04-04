#include<iostream>
using namespace std;

struct Node{
	int value;
	Node *next;
};

void  init (Node *&head){
	head = NULL;
	
}

void createNode(int x){
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
}

void addFrirst(Node *&head, int x) {
	Node *p = createNode(x);
	p->next = head;
	head = p;
}

void addLast(Node *&head, int x){
	Node *p = createNode(x);
	//xac dinh node cuoi cung
	if(head = NULL) {   //danh sach rong 
		head = p
	}
	else {
			Node *last = head;
		while(last->next !=NULL){
			last = last->next;
		}
		last->next = p;	
	}
	
}

void addAfter(Node *head, int v, int x) {
	Node * p =  createNode(x);
	//tim node == v
	Node *q = head;
	while (q!=NULL && q->value != v){
		q = q->next;
	}//q == node dai dien tr ds lien ket
	if(q != NULL ){  //kiem tra v co tron ds 
		p->next = q->next;	
		q->next = p;	
	}
}

void deleteFrist(Node *&head){  //xoa ptu dau
	if(head != NULL) {
		Node *p = head;
		head = p->next;
		p->next =NULL;
		delete(p);
	}		
}

void deleteLast(Node *&head) {
	if(head != NULL){
	
	 	Node *last = head;
	 	Node *prev = NULL;
		while (last->next != NULL) {
			prev = last;
			last = last->next;	
		}
		if(prev ==NULL) {
			deleteFrist(head);
		}
		else{
		
			prev->next = NULL;
			delete(last);
		}
	}
}

void deleteNode(Node *&head,int v) {
	 if(head != NULL) {
	 	Node *p = head;
	 	Node *prev = NULL;
	 	while (p!= NULL && p->value != v) {
	 		prev = p;
	 		p = p->next;
		 }
		if(p! = NULL) {   //tim thay phan tu can xoa
		 	if(prev ==NULL) {  //ds co 1 ptu
				deleteFrist(head);
		 	}
			 else {
		 		prev->next = p->next;
		 		p->next = NULL;
				delete(p);  
			}	
		}
	}
}

void cleanAll( Node *&head) {
	while (head != NULL) {
		deleteFrist(head);	
	}
}

void output(Node *head) {
	Node *p = head;
	while ( p != NULL){
		cout<<p->value<<"\t";
		p = p->next;
	}
}

 int main() {
	Node *head;
	init(head);
	
	addFrirst(head, 14);
	addFrirst(head,3);
	addFrirst(head,8);
	output(head);
	return 0;
 }
