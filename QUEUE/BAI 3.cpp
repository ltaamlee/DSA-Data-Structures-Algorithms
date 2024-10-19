#include <bits/stdc++.h>
using namespace std;
#define ElementType GOODS

struct GOODS{
	string id;
	string name;
	string date;
	float cost;
};

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

int Push(LIST &q, ElementType x){
	node p=CreateNode(x);
	if (p==NULL) return 0;
	if (IsEmptyQueue(q))
		q.Head=p;
	else
		q.Tail->next=p;
	q.Tail=p;
	return 1;
}

int Pop(LIST &q){
	if (IsEmptyQueue(q)) return 0;
	node p=q.Head;
	q.Head=q.Head->next;
	if (q.Head==NULL)
		q.Tail=NULL;
	ElementType x=p->data;
	delete p;
	return 1;
}

void Front(LIST q){
	node p=q.Head;
	if (!IsEmptyQueue(q)){
			cout<<"\t"<<setw(25)<<left<<"Ma don hang";
			cout<<setw(25)<<left<<"Ten don hang";
			cout<<setw(20)<<left<<"Ngay san xuat";
			cout<<setw(20)<<right<<"Gia tien(vnd)";
			cout<<"\n";
			cout<<"\t"<<setw(25)<<left<<p->data.id;
			cout<<setw(25)<<left<<p->data.name;
			cout<<setw(20)<<left<<p->data.date;
			cout<<setw(20)<<right<<p->data.cost;
	}
	else{
		cout<<"Kho hang rong !\n";
	}
}

void Print(LIST q){
	if (IsEmptyQueue(q)){
		cout<<"Kho hang rong !\n";
	}
	else{
		node p=q.Head;
		cout<<"\t"<<setw(25)<<left<<"Ma don hang";
		cout<<setw(25)<<left<<"Ten don hang";
		cout<<setw(20)<<left<<"Ngay san xuat";
		cout<<setw(20)<<right<<"Gia tien (vnd)";
		cout<<"\n";
		while(p!=NULL){
			cout<<"\t"<<setw(25)<<left<<p->data.id;
			cout<<setw(25)<<left<<p->data.name;
			cout<<setw(20)<<left<<p->data.date;
			cout<<setw(20)<<right<<p->data.cost<<"\n";
			p=p->next;
		}
	}
}

void Q1(LIST &q, int &n, GOODS &x){
	cout<<"Nhap so luong mat hang : "; cin>>n;
	for (int i=1; i<=n; ++i){
		cout<<"Mat hang thu "<<i<<" : \n";
		cout<<"Nhap ma don hang : ";
		cin.ignore();
		getline(cin,x.id);
		cout<<"Nhap ten don hang : ";
		getline(cin,x.name);
		cout<<"Nhap ngay san xuat : ";
		cin>>x.date;
		cout<<"Nhap gia tien (vnd) : ";
		cin>>x.cost;
		Push(q,x);
	}	
}

void Q2(LIST q){
	Print(q);
	cout<<"\n\n";
}

void Q3(LIST q){
	cout<<"Thong tin mat hang chuan bi xuat kho : \n";
	Front(q);
	cout<<"\n\n";
}

void Q4(LIST &q){
	cout<<"Thong tin mat hang da xuat kho : \n";
	Front(q);
	cout<<"\n\n";
	Pop(q);
	cout<<"Da xuat kho mat hang nay !\n\n";
}

void Q5(LIST q){
	if (IsEmptyQueue(q)){
		cout<<"Kho hang rong !\n\n";
	}
	else{
		node p=q.Tail;
		cout<<"Thong tin mat hang vua nhap vao kho : \n";
		cout<<"\t"<<setw(25)<<left<<"Ma don hang";
		cout<<setw(25)<<left<<"Ten don hang";
		cout<<setw(20)<<left<<"Ngay san xuat";
		cout<<setw(20)<<right<<"Gia tien(vnd)";
		cout<<"\n";
		cout<<"\t"<<setw(25)<<left<<p->data.id;
		cout<<setw(25)<<left<<p->data.name;
		cout<<setw(20)<<left<<p->data.date;
		cout<<setw(20)<<right<<p->data.cost;
		cout<<"\n\n";
	}
}

void Q6(LIST q, string &t){
	cout<<"Nhap ten mat hang bat ky : ";
	cin.ignore();
	getline(cin,t);
	node p=q.Head;
	int cnt=0;
	while(p!=NULL){
		if (p->data.name==t){
			cout<<"\t"<<setw(25)<<left<<"Ma don hang";
			cout<<setw(25)<<left<<"Ten don hang";
			cout<<setw(20)<<left<<"Ngay san xuat";
			cout<<setw(20)<<right<<"Gia tien(vnd)";
			cout<<"\n";
			cout<<"\t"<<setw(25)<<left<<p->data.id;
			cout<<setw(25)<<left<<p->data.name;
			cout<<setw(20)<<left<<p->data.date;
			cout<<setw(20)<<right<<p->data.cost;
			cout<<"\n\n";
			cnt++;
			
		}
		p=p->next;
	}
	if (cnt==0) cout<<"Mat hang nay khong ton tai trong kho !\n\n";
}

void Q7(LIST &q){
	node p=q.Head;
	while(p!=NULL){
		Pop(q);
		p=p->next;
	}
	cout<<"Hang hoa trong kho da duoc xuat ! \n\n";
}

int main(){
    LIST q;
	Init(q);
	int n;
	GOODS x;
	int key;
	do{
		cout<<"\t------------------CHUONG TRINH QUAN LY KHO HANG------------------\n";
		cout<<"\t-----------------------------------------------------------------\n";
		cout<<"\t\t1. Nhap vao danh sach cac mat hang vao kho \n";
		cout<<"\t\t2. Xem thong tin tat cac hang hoa trong kho \n";
		cout<<"\t\t3. Xem thong tin mat hang chuan bi xuat kho \n";
		cout<<"\t\t4. Xuat kho mot mat hang va xem thong tin \n";
		cout<<"\t\t5. Xem thong tin mat hang vua nhap vao kho \n";
		cout<<"\t\t6. Tim va xem thong tin mat hang bat ki trong kho \n";
		cout<<"\t\t7. Xuat toan bo hang hoa trong kho \n";
		cout<<"\t\t0. Ket thuc chuong trinh !\n";
		cout<<"\t---------------------------------------------------------------\n\n";
		cout<<"Nhap lua chon cua ban : ";
		cin>>key;
		switch (key){
			case 1:{
				Q1(q,n,x);
				break;
			}
			case 2:{
				Q2(q);
				break;
			}		
			case 3:{
				Q3(q);
				break;
			}
			case 4:{
				Q4(q);
				break;
			}	
			case 5:{
				Q5(q);
				break;
			}
			case 6:{
				string t;
				Q6(q,t);
				break;
			}
			case 7:{
				Q7(q);
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
