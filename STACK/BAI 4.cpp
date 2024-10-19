#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ElementType int

struct STACK{
	ElementType a[MAX];
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

void Push(STACK& st, ElementType x){
	if (IsFullStack(st))
		cout<<"Ngan xep day !\n";
	else{
		st.a[st.top+1]=x;
		st.top++;
	}
}

ElementType Top(STACK& st){
	return st.a[st.top];
}

ElementType Pop(STACK& st){
	ElementType t=st.a[st.top];
	st.top--;
	return t;
}

void Input(int& n, ElementType a[MAX], STACK& st){
	cout<<"Nhap so phan tu cua mang : ";
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a[i];
		Push(st,a[i]);
	}
}

void Output(int n, ElementType a[MAX], STACK st){
	cout<<"Mang vua nhap : ";
	for (int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	cout<<"Mang sau khi dao nguoc : ";
	while (!(IsEmptyStack(st))){
		cout<<Top(st) <<" ";
		Pop(st);
	}
}
int main(){
	STACK st;
	InitStack(st);
	int n, a[MAX];
	Input(n,a,st);
	Output(n,a,st);
	return 0;
}
