#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ElementType string

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

void Input(string& s, ElementType a[MAX], STACK& st){
	cout<<"Nhap chuoi (gom nhieu tu cach nhau boi 1 khoang trang) : ";
	getline(cin,s);
	stringstream ss(s);
	string word;
	while(ss>>word){
		Push(st,word);
	}
}

void Output(string s, ElementType a[MAX], STACK st){
	cout<<"Chuoi vua nhap : ";
	for (int i=0; i<s.size(); ++i){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	cout<<"Chuoi sau khi dao nguoc cac tu : ";
	while (!(IsEmptyStack(st))){
		cout<<Top(st) <<" ";
		Pop(st);
	}
}
int main(){
	STACK st;
	InitStack(st);
	string s, a[MAX];
	Input(s,a,st);
	Output(s,a,st);
	return 0;
}
