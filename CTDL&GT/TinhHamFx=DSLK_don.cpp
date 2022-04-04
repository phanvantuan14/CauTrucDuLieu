#include<iostream>
#include<math.h>
using namespace std;

struct Element {
	double coeffs;//he so
	int order;//bac cua he so
};

struct Node {
	Element value;
	Node *next;
};

void init(Node *&head){
	head == NULL;
}

Node *createNode (Element el){
	Node *p = new Node;
	p->value = el;
	p->next = NULL;
	return p;
}

void insertNode(Node *&head, Element el) {
	Node *p = createNode(el);
	if(head == NULL){  //danh sach rong
		head = p;
		return;
	}   
	
	Node *r = head;
	Node *prev = NULL;
	while(r != NULL && r->value.order <= el.order) {
		if (r->value.order == el.order){
			r->value = el;
			break;
		}     
		prev  = r;    
		r = r->next;		
	}

	if(r == NULL){//phan tu can chen o vi tri cuoi cung
		prev->next = p;
		 
	}
	else if(r->value.order != el.order)  {
	
		p->next = r; 		
		if(prev == NULL){//them dau
			head = p;
		}
		else{
			prev->next = p;
		}
			
	}	

}

double tinhGiaTriF(Node *head, double x) {
	Node *p = head;
	double kq = 0;
	while(p!=NULL) {
		kq += p->value.coeffs * pow(x, 1.0*p->value.order);
		p = p->next; 
	}
	return kq;
}

void show(Node *head) {

	Node *p = head;
	while(p != NULL) {
		cout<< p->value.coeffs<<"*x^"<< p->value.order;
		if(p->next != NULL){
			cout<<"+";
		}
		p = p->next;           
	}
}

int main() {
	cout<<"Bai Tap"<<endl;
	
	Node *head;
	init(head);
	
	Element  e5;
	Element  e2;
	Element  e3;
	
	e2.order = 2;
	e2.coeffs = 9;
	
	e3.order = 3;
	e3.coeffs = 23;
	
	e5.order = 4;
	e5.coeffs = 32;
	
	
	insertNode(head,e5);
	insertNode(head,e3);
	insertNode(head,e2);
	show(head);
	
	double k = tinhGiaTriF(head,3);
	cout<<"\nf(2)= "<<k<<endl;
	return 0;
}
