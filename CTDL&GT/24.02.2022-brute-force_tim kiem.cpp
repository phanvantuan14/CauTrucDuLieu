#include<iostream>
#include<string>

using namespace std;

int bruteForce (const char *des, const char *x,int n, int m) {
	int j = 0;
	int count = 0;
	for(int i =0; i <= (n-m);i++) {
		for(j = 0;j < m && x[j] == des[i+j]; j++);
		if(j >= m){
			count ++;
		}
	}	
	return count;
}

int main() {
	const char *des = "fdsahdsdhsdjsa";
	const char *x = "h";
	
	int lenDes = strlen(des);
	int lenX = strlen(x);
	
	int res = bruteForce(des, x, lenDes, lenX);
	cout<<" xau x xuat hien"<<res<< " lan"<<endl;
	
	return 0;
}


//in ra vong lap ko dung  for

/*
#include<iostream>
using namespace std;

void noFor(int n) {
	if(n<1){
		return;
	}
	else{
	print(n-1);
	}
	cout<< n <<"";
}

int main {
	int n;
	cin>>n;
	if(n<0) {
	n *= -1;
	}
	print(n);
	cout<<endl;
	return 0;
}

	
