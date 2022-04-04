#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}

void selectionSort(int arr[], int n) {
 	int min_index = 0;
	for(int i=0;i<n-1;i++){
		min_index = i;
		for(int j= i+1; j<n; j++){
			if(arr[j]<arr[min_index]) {
				min_index = j;
			}
		}
		swap(&arr[i],&arr[min_index]);
	}
	
}

void output (int arr[], int n){
	for(int i=0; i < n;i++) 
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main () {
	int arr[] ={-2,0,8,5,7,9,4,54,-34,};
	
	int  length = sizeof(arr)/sizeof(int);
	selectionSort(arr, length);
	
	output(arr, length);
	
	return 0;
}
