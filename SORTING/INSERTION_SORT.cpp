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
void INSERTION_SORT(int n, vector<int> &a){
	int pos,i;
	int x;
	for (i=1; i<n; ++i){
		x=a[i];
		pos=i-1;
		while((pos>=0) && (a[pos]>x)){
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
