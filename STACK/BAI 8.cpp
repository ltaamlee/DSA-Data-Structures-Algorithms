#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct STACK{
	int a[MAX];
	int top;
};

void InitStack(STACK& st){
	st.top=-1;
}

int IsEmptyStack(STACK& st){
	if (st.top==-1)
		return 1;
	return 0;
}

int IsFullStack(STACK& st){
	if (st.top==MAX-1)
		return 1;
	return 0;
}

void Push(STACK& st, int x){
	if (IsFullStack(st))
		cout<<"Ngan xep day !\n";
	else{
		st.a[st.top+1]=x;
		st.top++;
	}
}

int Top(STACK& st){
	return st.a[st.top];
}

int Pop(STACK& st){
	int t=st.a[st.top];
	st.top--;
	return t;
}

void Print(STACK st){
	while (!(IsEmptyStack(st))){
		cout<<Top(st) <<" ";
		Pop(st);
	}
}

void factorial(int n){
	STACK st;
	InitStack(st);
	int temp=n;
	while(temp!=0){
		Push(st,temp);
		temp--;
	}
	long long res=1;
	while(!IsEmptyStack(st)){
		res*=Top(st);
		Pop(st);
	}
	cout<<n<<"! = "<<res;
}

int main(){
	int n;
	cout<<"Nhap n = ";
	cin>>n;
	factorial(n);
	return 0;
}
