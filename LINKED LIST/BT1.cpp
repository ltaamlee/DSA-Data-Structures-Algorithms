#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node* node;

typedef struct List{
	node pHead;
	node pTail;
}LIST;

node CREATE_N(int x){
	node n=new Node;
	n->data=x;
	n->next=NULL;
	return n;
}

void CREATE_L(LIST &l){
	l.pHead=l.pTail=NULL;	
}

void PRINT_L(LIST l){
	node p;
	p=l.pHead;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<"\n";
}

void ADD_HEAD(LIST &l, node p){
	if (l.pHead==NULL){
		l.pHead=p;
		l.pTail=l.pHead;
	}
	else{
		p->next=l.pHead;
		l.pHead=p;
	}
}

void ADD_TAIL(LIST &l, node p){
	if (l.pHead==NULL){
		l.pHead=p;
		l.pTail=l.pHead;
	}
	else{
		l.pTail->next=p;
		l.pTail=p;
	}
}

node SEARCH(LIST l, int x){
	node p=l.pHead;
	while (p!=NULL && p->data!=x)
		p=p->next;
	return p;
}

int REMOVE_HEAD(LIST &l){
	node p=l.pHead;
	l.pHead=l.pHead->next;
	delete p;
	if (p==NULL) return 0;
	return 1;
}

int REMOVE_AFTERQ(LIST &l, node q){
	node p;
	if (q!=NULL){
		p=q->next;
		if (p!=NULL){
			if (p==l.pTail)
				l.pTail=q;
			q->next=p->next;
			delete p;
		}
		return 1;
	}
}

int REMOVE_X(LIST &l, int x){
	node p, q=NULL;
	p=l.pHead;
	while((p!=NULL) && p->data!=x){
		q=p;
		p=p->next;
	}
	if (p==NULL)
		return 0;
	if (q!=NULL)
		REMOVE_AFTERQ(l,q);
	else
		REMOVE_HEAD(l);
}

void QUICK_SORT(LIST &l){
	node p, x;
	LIST l1, l2;
	if (l.pHead==l.pTail) return;
	CREATE_L(l1);
	CREATE_L(l2);
	x=l.pHead;
	l.pHead=x->next;
	while(l.pHead!=NULL){
		p=l.pHead;
		l.pHead=p->next;
		p->next=NULL;
		if (p->data <= x->data)
			ADD_HEAD(l1,p);
		else
			ADD_HEAD(l2,p);
	}
	QUICK_SORT(l1);
	QUICK_SORT(l2);
	if (l1.pHead!=NULL){
		l.pHead=l1.pHead;
		l1.pTail->next=x;
	}
	else
		l.pHead=x;
	x->next=l2.pHead;
	if (l2.pHead!=NULL)
		l.pTail=l2.pTail;
	else
		l.pTail=x;
}

void INSERT(LIST &l, int x){
	node p=CREATE_N(x), q=l.pHead;
	if (p->data <= l.pHead->data){
		ADD_HEAD(l,p);
	}
	else
	if (p->data > l.pTail->data){
		ADD_TAIL(l,p);
	}	
	else{
		node t=new Node;
		while (q!=NULL && q->data<x){
			q=q->next;	
		}
		for (node k=l.pHead; k!=NULL; k=k->next){
			if (k->data==q->data){
				p->next=k;
				t->next=p;
			}
			t=k;
		}
	}
}
int main(){
	node p;
	LIST l;
	int x;
	CREATE_L(l);
	cout<<"Nhap vao du lieu cua xau voi moi nut la 1 so nguyen duong : \n";
	do{
		cout<<"Nhap x = ";
		cin>>x;
		if (x>0){
			p=CREATE_N(x);
			ADD_HEAD(l,p);
		}
	}while(x>0);
	int c=-1;;
	do{ 
		cout<<"\n";
		cout<<"\t-----------------------------------MENU------------------------------------------\n";
		cout<<"\t\t1. Liet ke tat ca cac thanh phan du lieu cua cac nut trong xau \n";
		cout<<"\t\t2. Tim mot phan tu trong xau co khoa bang x \n";
		cout<<"\t\t3. Xoa 1 phan tu dau xau \n";
		cout<<"\t\t4. Xoa 1 phan tu co khoa bang x trong xau \n";
		cout<<"\t\t5. Sap xep tang dan theo thanh phan du lieu \n";
		cout<<"\t\t6. Chen 1 phan tu vao xau sao cho xau van tang theo truong du lieu\n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t---------------------------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"Nhap lua chon : ";
		cin>>c;
		cout<<"\n";
		switch (c){
			case 1:{
				cout<<"Cac thanh phan du lieu cua cac nut trong xau : ";
				PRINT_L(l);
				break;
			}
			case 2:{
				cout<<"Nhap khoa x = ";
				cin>>x;
				p=SEARCH(l,x);
				cout<<"\n";
				if (p==NULL)
					cout<<"Khong tim thay x trong xau !";
				else
					cout<<"Tim thay x trong xau !";
				cout<<"\n";
				break;
			}
			case 3:{
				REMOVE_HEAD(l);
				cout<<"Xau sau khi xoa phan tu dau: ";
				PRINT_L(l);
				break;
			}
			case 4:{
				cout<<"Nhap khoa x = ";
				cin>>x;
				cout<<"\n";
				REMOVE_X(l,x);
				cout<<"Xau sau khi xoa phan tu bang khoa x : ";
				PRINT_L(l);
				break;
			}
			case 5:{
				cout<<"Sap xep xau tang dan theo truong du lieu : ";
				QUICK_SORT(l);
				PRINT_L(l);
				break;
			}
			case 6:{
				cout<<"Nhap phan tu can chen = ";
				cin>>x;
				INSERT(l,x);
				cout<<"\n";
				cout<<"Xau sau khi chen x : ";
				PRINT_L(l);
				break;
			}
			case 0:
				cout<<"Ket thuc chuong trinh !";
				break;
			default:
				cout<<"Lua chon khong ton tai trong menu !";
				cout<<"\n";
				break;
		}
	}while(c!=0);
	return 0;
}
