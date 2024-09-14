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
void SHAKE_SORT(int n, vector<int> &a){
	int i,j,l,r,k;
	l=0;
	r=n-1;
	k=n-1;
	while (l<r){
		for (j=r; j>l; --j){
			if (a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				k=j;
			}
		}
		l=k;
		for (i=l; i<r; ++i){
			if (a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				k=i;
			}
		}
		r=k;
	}
}
int main(){
	int n;
	vector<int> a(n);
	INPUT(n,a);
	SHAKE_SORT(n,a);
	OUTPUT(n,a);
	return 0;
}
