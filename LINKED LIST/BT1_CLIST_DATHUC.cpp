#include <bits/stdc++.h>
using namespace std;

struct DT{
	int heso;
	int somu;
};

struct Node{
	DT data;
	Node* next;
};

typedef struct Node* node;

struct LIST{
	node Head;
	node Tail;
};

void Init(LIST &l){
	l.Head=l.Tail=NULL;
}

node CreateNode(DT x){
	node n=new Node;
	n->data.heso=x.heso;
	n->data.somu=x.somu;
	n->next=NULL;
	return n;
}

int isEmptyList(LIST l){
	if (l.Head==NULL)
		return 1;
	return 0;
}

void AddFirst(LIST &l, node p){
	if (l.Head==NULL){
		l.Head=p;
		l.Tail=l.Head;
	}
	else{
		p->next=l.Head;
		l.Head=p;
	}
}

void AddLast(LIST &l, node p){
	if (l.Head==NULL){
		l.Head=p;
		l.Tail=l.Head;
	}
	else{
		l.Tail->next=p;
		l.Tail=p;
	}
}

void QuickSort(LIST &l){
	LIST l1,l2;
	Init(l1);
	Init(l2);
	if (l.Head==l.Tail) return;
	node pivot, p;
	pivot=l.Head;
	p=l.Head->next;
	while (p!=NULL){
		node q=p;
		p=p->next;
		q->next=NULL;
		if (q->data.somu > pivot->data.somu)
			AddLast(l1,q);
		else 
			AddLast(l2,q);
	}
	QuickSort(l1);
	QuickSort(l2);
	if (!isEmptyList(l1)){
		l.Head=l1.Head;
		l1.Tail->next=pivot;
	}
	else
		l.Head=pivot;
	pivot->next=l2.Head;
	if (!isEmptyList(l2))
		l.Tail=l2.Tail;
	else 
		l.Tail=pivot;
}

void Input(LIST &l){
	Init(l);
	DT x;
	do{
		cout<<"Nhap vao he so (Nhap 0 de dung): "; cin>>x.heso;
		if (x.heso==0) break;
		cout<<"Nhap vao so mu : "; cin>>x.somu;
		node p=CreateNode(x);
		AddLast(l,p);
	} while(x.heso!=0);
}

void Output(LIST l){
	QuickSort(l);
	node p=l.Head;
	while (p!=NULL){
		if (p->data.somu==0) 
			cout<<p->data.heso;
		else
			cout<<p->data.heso<<"x^"<<p->data.somu;
		if (p!=l.Tail) cout<<" + ";
		p=p->next;
	}
	cout<<"\n\n";
}

void RG(LIST &l){
	if (isEmptyList(l)) return;
	node p=l.Head;
	while(p!=NULL && p->next!=NULL){
		if (p->data.somu == p->next->data.somu){
			p->data.heso+=p->next->data.heso;
			node temp=p->next;
			p->next=temp->next;
			delete temp;
		} 
		else
			p=p->next;
	}
}

LIST CONG(LIST &l1, LIST &l2){
	QuickSort(l1);
	QuickSort(l2);
	LIST l;
	Init(l);
	node p=l1.Head, q=l2.Head;
	while (p!=NULL || q!=NULL){
		node res=new Node;
		if (p->data.somu > q->data.somu){
			AddLast(l,p);
			p=p->next;
		}
		else
		if (q->data.somu > p->data.somu){
			AddLast(l,q);
			q=q->next;
		}
		else 
		if (q->data.somu == p->data.somu){
			res->data.heso=p->data.heso+q->data.heso;
			res->data.somu=p->data.somu;
			AddLast(l,res);
			p=p->next;
			q=q->next;
		}
	}
	while (q!=NULL){
		AddLast(l,q);
		q=q->next;
	}
	while (p!=NULL){
		AddLast(l,p);
		p=p->next;
	}
	RG(l);
	return l;
}

LIST NHAN(LIST &l1, LIST &l2){
	QuickSort(l1);
	QuickSort(l2);
	LIST l;
	Init(l);
	for (node p=l1.Head; p!=NULL; p=p->next){
		for (node q=l2.Head; q!=NULL; q=q->next){
			node res=new Node;
			res->data.heso=p->data.heso*q->data.heso;
			res->data.somu=p->data.somu+q->data.somu;
			AddLast(l,res);
		}
	}
	RG(l);
	return l;
}

int main(){
	LIST l1, l2;
	Init(l1);
	Init(l2);
	int key;
	do{
		cout<<"\t------------------------------CHUONG TRINH THAO TAC VOI DA THUC-------------------------------\n";
		cout<<"\t\t1. Nhap da thuc P(x) \n";
		cout<<"\t\t2. In da thuc \n";
		cout<<"\t\t3. Rut gon da thuc \n";
		cout<<"\t\t4. Nhap vao da thuc Q(x). Cong 2 da thuc  \n";
		cout<<"\t\t5. Nhap vao da thuc Q(x). Nhan 2 da thuc \n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t----------------------------------------------------------------------------------------------\n";	
		cout<<"Nhap lua chon : ";
		cin>>key;
		switch (key){
			case 1:{
				cout<<"P(x): \n";
				Input(l1);
				break;
			}
			case 2:{
				cout<<"Da thuc vua nhap : ";
				Output(l1);
				break;
			}
			case 3:{
				cout<<"Da thuc sau khi rut gon : ";
				RG(l1);
				Output(l1);
				break;
			}
			case 4:{
				cout<<"Q(x): \n";
				Input(l2);
				cout<<"P(x) : "; Output(l1);
				cout<<"Q(x) : "; Output(l2);
				cout<<"P(x) + Q(x) = ";
				LIST l=CONG(l1,l2);
				Output(l);
				break;
			}
			case 5:{
				cout<<"Q(x): \n";
				Input(l2);
				cout<<"P(x) : "; Output(l1);
				cout<<"Q(x) : "; Output(l2);
				cout<<"P(x) + Q(x) = ";
				LIST l=NHAN(l1,l2);
				Output(l);
				break;
			}
			case 0:{
				cout<<"\t\t\t\t"<<"Ket thuc chuong trinh ! \n";
				cout<<"\t------------------------------------------------------------------------\n";
				break;
			}
			default:{
				cout<<"Lua chon khong ton tai trong menu !";
				cout<<"\n";
				break;
			}
		}
	} while (key!=0);
	return 0;
}
