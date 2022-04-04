#include<iostream>
using namespace std;

void swap (int *a, int *b){
	int x = *a;
	*a = *b;
	*b = x;
}

int partion(int arr[], int l, int h){
	int p = arr[h];
	int i=l-1; //bien giam sat trinh tu thuc hien
	for(int j=l;j<h;j++) {
		if(arr[j]<p){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	//tim duoc vi tri chinh xac cho p
	swap(&arr[i+1],&arr[h]);
	return i+1;
}

void quickSort(int arr[], int l, int h){
	if(l < h) {
		int p = partion(arr,l, h);
			quickSort(arr,l, p-1);
			quickSort(arr,p+1, h);
	}
}

//int binarySearch(int arr[], int l, int h,int x) {//tim phien ban vong lap tim ptu theo cay
//	while(l<h) {
//		int m = l + (h - l)/2;
//		if(arr[m]==x) {
//			return m;//tim thay
//		}	
//		if(arr[m] < x) { //co the x nam phai mid
//			l = m+1;
//		}           
//		if(arr[m]> x) {//co the x nam trai cua mid
//			h = m-1;
//		}
//	}
//	  return -1;
//}


int binarySearch (int arr[], int l, int h, int x) { // search theo phien ban de quy
	if(l <= h) {
		int m = l+ (h-l)/2;
		if(arr[m] == x){
			return m;
		}
		if(arr[m] < x) {
			return binarySearch(arr, m+1, h,x);
		}
		else {
			 return binarySearch(arr,l, m-1,x );
		}
	}
	return -1;
}

void output (int arr[], int n){
	for(int i=0; i < n;i++) 
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main() {
	 int arr[]={9,9,435,5,3,5,35,3,22,1,1};
	 int length = sizeof(arr)/sizeof(int);
	 quickSort(arr,0,length-1);
	 output(arr,length);
	 
	int x = 9;
	int index = binarySearch(arr, 0, length-1,x);
	if(index != -1){
		cout<<"Ton tai gia tri:  "<<x<<endl;
	}
	else {
		cout<<"Khong ton tai gia tri"<<endl;
	}
	return 0;
}
