#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ElementType Tower

struct Tower{
	int n;
	char A;
	char B;
	char C;
};

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

void Print(STACK st){
	while (!(IsEmptyStack(st))){
		cout<<Top(st).A<<" "<<Top(st).B<<" "<<Top(st).C;
		Pop(st);
	}
}

void Move(Tower x){
	Tower t1, t2;
	STACK st;
	InitStack(st);
	Push(st,x);
	do{
		t1=Pop(st);
		if (t1.n==1){
			cout<<"Chuyen 1 dia tu "<<t1.A<<" sang "<<t1.B<<"\n";
		}
		else{
			t2.n=t1.n-1;
			t2.A=t1.C;
			t2.B=t1.B;
			t2.C=t1.A;
			Push(st,t2);
			
			t2.n=1;
			t2.A=t1.A;
			t2.B=t1.B;
			t2.C=t1.C;
			Push(st,t2);
			
			t2.n=t1.n-1;
			t2.A=t1.A;
			t2.B=t1.C;
			t2.C=t1.B;
			Push(st,t2);
		}
	}while(!IsEmptyStack(st));
}

int main(){
	Tower x;
	cout<<"Nhap so dia : "; cin>>x.n;
	x.A='A';
	x.B='B';
	x.C='C';
	cout<<"Cot A la cot nguon, B la cot dich, C la cot trung gian \n";
	Move(x);
	return 0;
}
