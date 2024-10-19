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

int main(){
	STACK st;
	InitStack(st);
	int key;
	do{
		cout<<"\t----------CHUONG TRINH STACK KIEU MANG----------\n";
		cout<<"\t\t1. Them 1 phan tu vao ngan xep \n";
		cout<<"\t\t2. Huy 1 phan tu o dinh ngan xep \n";
		cout<<"\t\t3. Lay thong tin phan tu o dinh ngan xep \n";
		cout<<"\t\t4. Kiem tra ngan xep rong \n";
		cout<<"\t\t5. In ngan xep \n";
		cout<<"\t\t0. Ket thuc chuong trinh !\n";
		cout<<"\t------------------------------------------------\n\n";
		cout<<"Nhap lua chon cua ban : ";
		cin>>key;
		switch (key){
			case 1:{
				cout<<"Nhap phan tu can them : ";
				ElementType n; cin>>n;
				Push(st,n);
				break;
			}
			case 2:{
				if (IsEmptyStack(st))
					cout<<"Ngan xep rong !\n";
				else
					Pop(st);
				break;
			}		
			case 3:{
				cout<<"Phan tu o dinh ngan xep : "<<Top(st)<<"\n";
				break;
			}
			case 4:{
				if (IsEmptyStack(st))
					cout<<"Ngan xep rong !\n";
				else
					cout<<"Ngan xep khong rong !\n";
				break;
			}	
			case 5:{
				cout<<"Stack : ";
				Print(st);
				cout<<"\n";
				break;
			}
			case 0:{
				cout<<"Ket thuc chuong trinh !\n";
				break;
			}		
			default:{
				cout<<"Lua chon khong ton tai !\n";
				break;
			}
		}
	}while (key!=0);
	return 0;
}
