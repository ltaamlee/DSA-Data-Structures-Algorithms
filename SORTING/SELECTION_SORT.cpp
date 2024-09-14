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
void SELECTION_SORT(int n, vector<int> &a){
	int Min,i,j;
	for (i=0; i<n-1; ++i){
		Min=i;
		for (j=i+1; j<n; ++j){
			if (a[j]>a[Min]){
				Min=j;
			}
			swap(a[Min],a[j]);
		}
	}
}
int main(){
	int n;
	vector<int> a(n);
	INPUT(n,a);
	SELECTION_SORT(n,a);
	OUTPUT(n,a);
	return 0;
}
