#include<iostream>
#include<string>

using namespace std;

unsigned long long tmp[200];

void init() {
	for(int i=0; i< 200; i++){
		tmp[i] = -1;
	}
}

unsigned long long fiboQHD(int n){
	if(tmp[n] = -1){
		if(n <= 1){
			tmp[n] = n;
		}
		else{
			tmp[n] =  fiboQHD(n-1)+fiboQHD(n-2);
		}
	}
	return tmp[n];
}
 int main() {
 	init();
 	cout<< fiboQHD(20) <<endl;
 	return 0;
 }
