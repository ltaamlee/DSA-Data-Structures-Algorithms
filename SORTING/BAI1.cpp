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
void QUICKSORT1(vector<int> &a, int l, int r){
	int i,j,x;
	x=a[(l+r)/2];
	i=l; j=r;
	while (i<j){
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	if (l<j) QUICKSORT1(a,l,j);
	if (i<r) QUICKSORT1(a,i,r);
}
void QUICKSORT2(vector<int> &a, int l, int r){
	int i,j,x;
	x=a[(l+r)/2];
	i=l; j=r;
	while (i<j){
		while (a[i]>x) i++;
		while (a[j]<x) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	if (l<j) QUICKSORT2(a,l,j);
	if (i<r) QUICKSORT2(a,i,r);
}
int main(){
	int n;
	vector<int> a(n);
	INPUT(n,a);	 
	vector<int> pos,neg;
	for (int i=0; i<n; ++i){
		if (a[i]>=0){
			pos.push_back(a[i]);
		}
	}
	for (int i=0; i<n; ++i){
		if (a[i]<0){
			neg.push_back(a[i]);
		}
	}
	QUICKSORT2(pos,0,pos.size()-1);
	QUICKSORT1(neg,0,neg.size()-1);
	pos.insert(pos.end(),neg.begin(),neg.end());
	OUTPUT(pos.size(),pos);
	return 0;
}
/*
7
-4 2 1 15 -17 0 3
*/
