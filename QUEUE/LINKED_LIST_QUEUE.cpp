#include <bits/stdc++.h>
using namespace std;
#define ElementType int

struct Node{
	ElementType data;
	struct Node* next;
};

typedef struct Node* node;

struct LIST{
	node Head;
	node Tail;
};

void Init(LIST &q){
	q.Head=q.Tail=NULL;
}

node CreateNode(ElementType x){
	node p=new Node;
	if (p==NULL) return NULL;
	p->data=x;
	p->next=NULL;
}

int IsEmptyQueue(LIST q){
	if (q.Head==NULL)
		return 1;
	return 0;
}

ElementType Push(LIST &q, ElementType x){
	node p=CreateNode(x);
	if (p==NULL) return NULL;
	if (IsEmptyQueue(q))
		q.Head=p;
	else
		q.Tail->next=p;
	q.Tail=p;
	return 1;
}

ElementType Pop(LIST &q){
	if (IsEmptyQueue(q)) return 0;
	node p=q.Head;
	q.Head=q.Head->next;
	if (q.Head==NULL)
		q.Tail=NULL;
	ElementType x=p->data;
	delete p;
	return 1;
}

ElementType Front(LIST q){
	if (!IsEmptyQueue(q))
		return q.Head->data;
	else{
		cout<<"Hang doi rong ! ";
		return 0;
	}
}

void Print(LIST q){
	node p=q.Head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}
int main(){
    LIST q;
	Init(q);
	int key;
	do{
		cout<<"\t----------CHUONG TRINH QUEUE KIEU LINKED LIST----------\n";
		cout<<"\t\t1. Them 1 phan tu vao hang doi \n";
		cout<<"\t\t2. Huy 1 phan tu o dau hang doi \n";
		cout<<"\t\t3. Lay thong tin phan tu o dau hang doi \n";
		cout<<"\t\t4. Kiem hang doi rong \n";
		cout<<"\t\t5. In hang doi \n";
		cout<<"\t\t0. Ket thuc chuong trinh !\n";
		cout<<"\t------------------------------------------------\n\n";
		cout<<"Nhap lua chon cua ban : ";
		cin>>key;
		switch (key){
			case 1:{
				cout<<"Nhap phan tu can them : ";
				ElementType n; cin>>n;
				Push(q,n);
				break;
			}
			case 2:{
				if (IsEmptyQueue(q))
					cout<<"Hang doi rong !\n";
				else
					Pop(q);
				break;
			}		
			case 3:{
				cout<<"Phan tu o dinh hang doi : "<<Front(q)<<"\n";
				break;
			}
			case 4:{
				if (IsEmptyQueue(q))
					cout<<"Hang doi rong !\n";
				else
					cout<<"Hang doi khong rong !\n";
				break;
			}	
			case 5:{
				cout<<"Queue : ";
				Print(q);
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
