#include<iostream> 
using namespace std;
#define MAX 100

struct Stack {
	int a[MAX];
	int top;
};

void init(Stack &s) {
	s.top =-1;
}
void  push (Stack &s, int x) {
	s.a[++s.top] = x;
}

int pop (Stack &s) {
//	int x = s.a[s.top];
//	s.top--;
	
	return s.a[s.top--];
}

bool isEmpty (Stack s) {
	return s.top < 0;     // cach 2
//	if(s.top<0)
//		return true;      //cach 1
//	return false;
}

bool isFull (Stack s) {
	return s.top == MAX;
}

void output (Stack s) {
	for(int i=0; i<=s.top; i++) {
		cout<<s.a[i]<<"\t";
	}
	cout<<endl;
}

void converDecimalToBinary (int n,int radix) {
	Stack(s);
	init(s);
	
	while(n != 0){
		push(s,n % radix);
		n/=radix;
	}
	while (isEmpty(s) == false)
		cout<<pop(s);
	cout<<endl;
}



int main() {
	
	converDecimalToBinary(25,8);
//	Stack s;
//	init(s);
//	
//	push(s, 100);
//	push(s,13);
//	push(s,47);
//	output(s);
//	
//	cout<<pop(s)<<endl;
//	output(s);
//	
	return 0;
}
