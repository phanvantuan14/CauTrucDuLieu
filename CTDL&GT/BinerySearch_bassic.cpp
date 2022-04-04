#include<iostream>
using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
};

void init (Node *&root) {
 	root = NULL;
}

Node *createNode (int x) {
	Node *p = new Node;
	p->key = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}         
	
void insertNode (Node *&root, int x){
	if(root == NULL) {
		root = createNode(x); 
	}
	//tim kiem vi tri can chen
	else {
		Node *p = root;
		Node *parent = NULL;
		while ( p!= NULL && p->key != x) {
			parent = p;
			if(p->key > x ){
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		//thuc hien chen
		if( p == NULL) {
			p = createNode(x);
			if(parent->key < x)
				parent->right = p;
			else
				parent->left = p;
		}
		
	}
}

void lnr( Node *root) {
	if(root != NULL){
		lnr(root->left);
		cout<<root->key<<"\t";
		lnr(root->right);
	}
}

void lrn( Node *root) {
	if(root != NULL){
		lrn(root->left);//left
		lrn(root->right);//phai
		cout<<root->key<<"\t";//nut goc
	}
}

void nlr( Node *root) {
	if(root != NULL){
		cout<<root->key<<"\t";//nut goc
		nlr(root->left);//left
		nlr(root->right);//phai	
	}
}

void deleteNode(Node *&root, int x) {
	if(root != NULL){
		Node *p = root;
		Node *parent = NULL;
		while(p != NULL && p->key != x){
			parent = p;
			if(p->key>x)    
				p=p->left;
			else
				p = p->right;
		}
		
		if(p != NULL) {
			
			if(p->left != NULL && p->right !=NULL)
			{
				parent = p;
				Node *r = p->right;
				while (r->left != NULL){	
					parent = r;
					r = r->left;
				}
				p->key = r->key;
				p = r;
			}
			Node *t;
			//xoa nut la hoac 1 con
			if(p->right == NULL)
				t=p->left;
			else if(p->left ==NULL)
				t = p->right;
			
			
			if(parent->key > p->key)
				parent->left = t;
			else
				parent->right = t;
				
		delete(p);
		}
	}        
}

//dem so nut la

void count (Node *root, int &n1, int &n2, int &n3 ) {
	if(root != NULL) {
	 	if(root->left != NULL && root->right != NULL) 
		 	n3++;
		else if(root->left != NULL || root->right != NULL)
			n2++;
		else
			n1++;
			
		count(root->left,n1,n2,n3);
		count(root->right,n1,n2,n3);
	}  	
	
}

//tinh chieu cao cua cay

int heightTree(Node *root) {
	if(root != NULL){
		int left = heightTree(root->left)+1;
		int right = heightTree(root->right)+1;
		return left > right ? left:right;
	}
	return 0;
}

//hien thi ra muc cua cay

void showK(Node *root, int k, int expected) {
	if(root !=NULL) {
	 k++;
	 showK(root->left, k, expected);
	 if(k == expected) 
	 	cout<<root->key<<"\t"<<endl;
	 showK(root->right,k, expected);
	 	
	}
}
int main() {
	Node *root;
	init(root);
	
	insertNode(root, 14);
	insertNode(root, 8);
	insertNode(root, 19);
	insertNode(root, 35);
	insertNode(root,9);
	insertNode(root, 10);
	
	
//	lnr(root);
//	cout<<endl;
//	
//	
//	deleteNode(root,14);  	
//	lnr(root);
//	cout<<endl;
	
//   	int n1=0,n2=0,n3=0;
//	count(root, n1, n2, n3);
//	cout<<"\nSo nut la"<<" "<<n1<<endl;
//	cout<<"\nSo nut la 1 cay con"<<" "<<n2<<endl;
//	cout<<"\nSo nut la 2 cay con"<<" "<<n3<<endl;
//	
	
	cout<<"Chieu cao cay la: "<<" "<<heightTree(root)<<endl;
	
	showK(root, -1, 0);
	
	return 0;
}
