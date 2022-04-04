#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int x = *a;
	*a = *b;
	*b = x;
}

void  bubbleSort_1(int arr[],int n) {//noi ptu nho nhat len truoc
	for(int i=0;i< n-1; i++){
		for(int j=n-1;j > i;j--){
			if(arr[j]<arr[j-1]){//ptu dung truoc ma lon hon phan tu dung sau thi doi cho
				swap(&arr[j],&arr[j-1]);
			
			}
		}
	}
}

void  bubbleSort_2(int arr[],int n) {//noir ptu lon nhat len tuoc
	for(int i=0;i< n-1; i++){
		for(int j=0;j<n-1-i-i;j++){
			if(arr[j]>arr[j+1]){//ptu dung truoc ma lon hon phan tu dung sau thi doi cho
				swap(&arr[j],&arr[j+1]);
			
			}
		}
	}
}

void output(int arr[], int n) {
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int arr[]= {0,14,43,32,23,43,2,3,43,34,9};
	int length = sizeof(arr)/sizeof(int);
	bubbleSort_2(arr,length);
	output(arr, length);
	 
	return 0;
}
