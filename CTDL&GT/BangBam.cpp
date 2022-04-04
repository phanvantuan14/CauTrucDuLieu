//pp ket noi truc tiep
/*#include<iostream>
using namespace std;
#define M 7
struct Node{
	int value;
	Node *next;	
};

void initHash (Node *head[]) {
 	for(int i=0; i<M; i++){
 		head[i]= NULL;
	}
}

Node *createNode (int x) {
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

int hashFunc(int value) {
	return value % M;
}

void insertNode (Node *head[], int value) {
	int h = hashFunc(value);
	Node *r = head[h];
	Node *prev = NULL;
	
	while( r!= NULL && r->value < value){
		prev = r;
		r = r->next;
	}	
	
	Node *p = createNode(value);
	if(prev==NULL){
		head[h] = p;
		p->next = r;
	}
	else if ( r == NULL) {
		prev->next = p;
	}
	else {
		p->next = r;
		prev->next = r;
	}
}

void deleteHash(Node *head[], int value) {
	int h = hashFunc(value);
	Node *r = head[h];
	Node *prev = NULL;
	while(r != NULL && r->value != value) {
		prev = r;
		r = r->next;
	}
	Node *p = createNode(value);
	if( prev==NULL) {
		head[h] = r->next;
		r->value = p->value;
	}
	if( r->next == NULL) {
		prev->next = NULL;	
	}   	
	else {
		prev->next = r;
		p->next = NULL;
	}
	
	delete(p);
}

void display(Node *head[]) {
	for(int i=0; i<M; i++) {
		if(head[i] != NULL){
			cout<<"--BucKet "<<i<<"--"<<endl;
			Node *p = head[i];
			
			while(p!=NULL) {
				cout<<p->value<<"\t";
				p = p->next;
			}
			cout<<endl;
		}
		
	}
}

Node *search(Node *head[], int value) {
	int h = hashFunc(value);
	Node *r = head[h];
	
	while(r != NULL && r->value != value) {
		r = r->next;
	}
	return r;
}

int main() {
	Node *head[M];
	initHash(head);
	
	insertNode(head, 2);
	insertNode(head, 8);
	insertNode(head,4);
	insertNode(head,9);
	insertNode(head, 15);
	deleteHash(head, 9);
	
	display(head);
	 
//	if(search(head,6)==NULL)
//	 	cout<<"khong ting thay\n";
//	 	
//	if(search(head,8) !=NULL)
//	 	cout<<" tim thay";
		
	return 0;
}   */

#include<iostream>
using namespace std;
#define M 7
struct item{
	int value;
	int next;	
};

struct HashTable{
	item h[M];
	int r;
};

void init(HashTable &t){
	for(int i=0; i< M; i++){
		t.h[i].value = -1;
		t.h[i].next = -1;	
	}
	t.r = M-1;
}  

int hashFunc(int x) {
	return x%M;
}

void insertHashItem(HashTable &t, int x) {
	if(t.r>=0) {
		int idx = hashFunc(x);
		if (t.h[idx].value == -1)	
			t.h[idx].value = x;
		else{
		
			t.h[t.r].value = x;
			while(t.h[idx].next!= -1)
				idx = t.h[idx].next;
				
			t.h[idx].next =t.r; 
		}
		while(t.r>=0 && t.h[t.r].value >= 0 ){
			t.r--;
		}
	}
}

int  search(HashTable t, int x){
	int idx = hashFunc(x);
	
	do{
	if(t.h[idx].value == x)
		return idx;

		idx = t.h[idx].next;
	}while(idx >= 0);
	
	return -1;
}


void display(HashTable t)  {
	for(int i=0; i<M; i++) {
		if(t.h[i].value>=0) {
			cout<<i<<":"<<t.h[i].value<<":"<<t.h[i].next<<endl;
		}
	}
}

 

int main() {
	HashTable t;
	init(t);
	
	insertHashItem(t, 15);
	insertHashItem(t, 8);
	insertHashItem(t,1);
	insertHashItem(t,21);
	insertHashItem(t, 14);
	
	display(t);	
	

	int idx = search(t, 15);
	if(idx >= 0)
		cout<<"Tim thay: "<<idx;
		
	return 0;
}    
