#include<iostream> 
using namespace std;

void swap (int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

void selectionSort (int a[], int n) {
	for( int k = 0; k < n-1; k++){
		int min_pos = k;
		for (int i= k+1; i < n; i++) {
		 	if(a[i] < a[min_pos])
		 		min_pos = i;
		 		
		swap(a[min_pos],a[k]);
		} 	
	}
}

void insertionSort (int a[],int n) {
	for(int i= 1; i<n ;i++){
		int x = a[i];//phan tu muon che 
		int pos = i-1;
		while(pos >= 0 && a[pos] > x ){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}

void interchangeSort (int a[], int n) {//thuat toan chay cham nhat trong 2 thuat toan tren
		for( int i = 0; i < n-1; i++){
			for(int j= i+i; j<n ;j++) {
				if(a[i] > a[j])
					swap(a[i], a[j]);
			}
		}
	
}

void bubleSort (int a[], int n) {
	for( int i = 0; i < n-1; i++){
		for(int j= n-1; j > i ;j--) {
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
		}
	}	
}

void quickSort (int a[], int left, int right) {
	int pivot = a[(left+right)/2];
	int l = left, r= right;
	do{
		while(a[l] < pivot)
			l++;
		while(a[r]> pivot)
			r--;
		if(l <= r) {
		
			swap(a[l],a[r]);
			l++;
			r--;	
		}
	}while(l <= r); 
	
	if(left < r) 
		quickSort(a, left, r);
	
	if(l<right) 
		quickSort(a, l, right);	
}

int *merge (int *a, int n1, int *b, int n2) {
	int *c = new int [n1 + n2];
	int i=0, j=0, dem=0;
	while(i<n1 && j<n2) {
		if(a[i]<b[j]){
			c[dem++] = a[i++]; 
		}
		else{
			c[dem++] = b[j++];
		}
	}
	for(int k = i; k < n1; k++)
		c[dem++] = a[k];
	for(int k = j; k < n2; k++)
		c[dem++] = b[k];
	
	return c;
}

int *mergeSort(int a[], int n) {
	if(n==1)
		return a;
	int mid = n/2;
	int *m1 = new int[mid];
	int *m2 = new int[n-mid];
	
	for(int i=0;i<mid;i++)
		m1[i] = a[i];
	for(int i=0;i<n-mid;i++)
		m2[i] = a[mid+i];
		
	m1 = mergeSort(m1, mid);
	m2 = mergeSort(m2, n-mid);
	
	return merge(m1, mid, m2, n-mid);
		 
}

int main() {
	int a[]={5,242,13,1,5,311,431,41};
//	int b[] = {4,5,6,7};
	int n = sizeof(a)/sizeof(a[0]);
//	selectionSort(a, n);
//	insertionSort(a,n);
//	interchangeSort(a,n);
//	bubleSort(a,n);
//	quickSort(a, 0, n-1);    

//	int *c = merge(a,6,b,4);

	int *b = mergeSort(a,n);
	for(int i=0; i<n; i++) {
		cout<<b[i]<<"\t";	
	}
	cout<<endl;
	
//	delete[]c;
	return 0;
} 


