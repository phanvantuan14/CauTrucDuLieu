#include<iostream>
using namespace std;

int linearSearch(a[], int n, int x) {
	  //cach 1
	for(int i=0; i<n ;i++){
		if(	a[i]==x){
			return i;
		}
		return -1;
	}
	//cach 2
//	int vt=0;
//	while (vt < n && a[vt] != x) {
//		vt++;	
//	}
//	if(vt == n)
//		return -1;
//	return vt;
}

int binarySearch (int a[],int n,int x) {
	int left  = 0;
	int right = n-1;
	while (left <= right) {
		int mid = (left + right)/2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main() {
	a[]={1,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(a[0]);
	
//	int vt =  linearSearch(a, n, 23);
//	cout<<vt<<endl;
	
	int vt =  binarySearch(a, n, 5);
	cout<<vt<<endl;
					  
	return 0;
	
}
