#include<iostream> 
#include<string.h>
#include <stdlib.h>
using namespace std;
#define MAX 100

struct Stack {
	char a[MAX][MAX];
	int top;
};

void init(Stack &s) {
	s.top =-1;
}
void push(Stack &s, char x[]) {
	
	strcpy(s.a[++s.top], x);
}

char* pop (Stack &s) {
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

bool checkOp(char op[]) {
		return(strcmp(op, "+") == 0 ||strcmp(op,"-")== 0 ||
			strcmp(op,"*")== 0 || strcmp(op,"/")== 0);
}   

char *strtok( char *str, const char *delim );
void cal(char s[]) {
	//s =10 5 + 2 * 3 / => 10
	Stack st;
	init(st);
	char *p = strtok(s," ");
	int t=0;
	while(p!=NULL) {
//		cout<<p<<endl;
		
		if(checkOp(p)==true) 
		{
			int b = atoi(pop(st));
			int a = atoi(pop(st));	
			if(strcmp(p, "+") == 0)
				t = a+b;
			else if(strcmp(p, "-") == 0)
				t = a-b;
			else if(strcmp(p, "*") == 0)
				t = a*b;
			else if(strcmp(p, "/") == 0)
				t = a/b;
			char tmp[MAX];
			sprintf(tmp, "%d", t);
			push(st,tmp);
		}
		else{
			push(st,p);	
		}
		p = strtok(NULL," ");
	}
	cout<<"ket qua cua bieu thuc la: "<<t<<endl;
}

int main () {
	char s[]="5 10 + 2 * 3 /";
	cal(s);
	
	return 0;
}
