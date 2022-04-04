#include<iostream>
#include<string> 

using namespace std;
//ngan xep stacks
int size = -1;
const int MAX = 100;
int stack[MAX];
								 
bool isEmpty() {  //kiem tra stack rong hay khong
	return (size == -1 );
}

bool isFull() {//kiem tra stack da day hay chua     
	return (size == MAX);
}

void push (int data) { //them du lieu vao satck 
	if(!isFull()) {
		size ++;
		stack [size] = data;
	}
   else {
	cout<<"stack full"<<endl;
	}
}

int pop () { //lay ra phan tu top(them vao cuoi cung) va xoa di
	if(!isEmpty()) {
		int	data = stack [size];
		size--;
		return data;
	}
	else {
		cout<<"Stack is empty"<<endl;
	}	
}

int top () { //lay ra phan tu top(them vao cuoi cung) 
	if(!isEmpty()) {
		int	data = stack [size];
		return data;
	}
	else {
		cout<<"Stack is empty"<<endl;
	}	
}


int main() {
	push(1);   
	push(3);
	cout<<"top: "<< top() <<endl;	
	pop();
	cout<<"top: "<< top() <<endl;
	
	while(!isEmpty()) {
		int data = pop();
		cout<<data<<"-"<<endl;
	}
	return 0;
}           
