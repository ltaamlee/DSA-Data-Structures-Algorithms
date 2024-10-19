#include <bits/stdc++.h>
using namespace std;
#define ElementType int

struct Node{
	ElementType data;
	struct Node* next;
};

typedef struct Node* node;

struct LIST{
	node top;
};

void InitStack(LIST& st){
	st.top=NULL;
}

int IsEmptyStack(LIST& st){
	if (st.top==NULL)
		return 1;
	return 0;
}
node CreateNode(ElementType x){
	node p=new Node;
	if (p==NULL) return NULL;
	p->data=x;
	p->next=NULL;
	return p;
}

void Push(LIST& st, node p){
	p->next=st.top;
	st.top=p;
}

ElementType Top(LIST& st){
	return st.top->data;
}

ElementType Pop(LIST& st){
	node p=st.top;
	ElementType t=st.top->data;
	st.top=st.top->next;
	delete p;
	return t;
}

void Print(LIST st){
	node p=st.top;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}
int main(){
	LIST st;
	InitStack(st);
	int key;
	do{
		cout<<"\t----------CHUONG TRINH STACK KIEU LINKED LIST----------\n";
		cout<<"\t\t1. Them 1 phan tu vao ngan xep \n";
		cout<<"\t\t2. Huy 1 phan tu o dinh ngan xep \n";
		cout<<"\t\t3. Lay thong tin phan tu o dinh ngan xep \n";
		cout<<"\t\t4. Kiem tra ngan xep rong \n";
		cout<<"\t\t5. In ngan xep \n";
		cout<<"\t\t0. Ket thuc chuong trinh !\n";
		cout<<"\t-------------------------------------------------------\n\n";
		cout<<"Nhap lua chon cua ban : ";
		cin>>key;
		switch (key){
			case 1:{
				cout<<"Nhap phan tu can them : ";
				ElementType n; cin>>n;
				node p=CreateNode(n);
				Push(st,p);
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
