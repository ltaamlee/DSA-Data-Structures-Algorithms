#include <bits/stdc++.h>
using namespace std;
void INPUT(int &n, vector<int> &a){
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a[i];
	}
}
void OUTPUT(int n, vector <int> a){
	for (int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
}
int BINARY_SEARCH(vector<int> a, int x, int l, int r){
	int mid=0;
	do{
		mid=(l+r)/2;
		if (x==a[mid])
			return mid;
		else
		if (x<a[mid])
			r=mid-1;
		else
			l=mid+1;
	}
	while(l<=r);
}
void INSERTION_SORT(int n, vector<int> &a){
	int pos,i,j,k;
	int x;
	for (i=1; i<n; ++i){
		x=a[i];
		pos=i-1;
		k=BINARY_SEARCH(a,x,0,pos);
		while(pos>=k){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}	
}
int main(){
	int n;
	vector<int> a(n);
	INPUT(n,a);
	INSERTION_SORT(n,a);
	OUTPUT(n,a);
	return 0;
}
