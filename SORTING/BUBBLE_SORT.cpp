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
void BUBBLE_SORT(int n, vector<int> &a){
	int i,j;
	for (i=0; i<n-1; ++i){
		for (j=n-1; j>i; --j){
			if (a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
}
int main(){
	int n;
	vector<int> a(n);
	INPUT(n,a);
	BUBBLE_SORT(n,a);
	OUTPUT(n,a);
	return 0;
}
