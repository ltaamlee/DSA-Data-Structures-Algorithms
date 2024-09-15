#include <bits/stdc++.h>
using namespace std;

struct BOOK{
	char ten[40];
	char maso[40];
	int nam;
	int m;
};

struct Node{
	BOOK data;
	Node *next;
};

typedef struct Node* node;

typedef struct List{
	node pHead;
	node pTail;
}LIST;

node CREATE_N(BOOK x){
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
	cout<<"\t"<<setw(25)<<left<<"Ten";
	cout<<setw(10)<<left<<"Ma So";
	cout<<setw(25)<<right<<"Nam xuat ban";
	cout<<setw(25)<<right<<"Tong so lan muon - tra";
	cout<<"\n";
	while(p!=NULL){
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(10)<<left<<p->data.maso;
		cout<<setw(25)<<right<<p->data.nam;
		cout<<setw(25)<<right<<p->data.m<<"\n";
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

void INPUT(LIST &l, node p, BOOK &a){
	while (true){
		cout<<"Nhap ten sach (Enter de ket thuc) : "; cin.getline(a.ten,40);
		if (strlen(a.ten)==0) break;
		cout<<"Nhap ma so sach : "; cin.getline(a.maso,40);
		cout<<"Nhap nam xuat ban : "; cin>>a.nam;
		cout<<"Nhap tong so lan muon - tra sach : "; cin>>a.m;
		cin.ignore();
		p=CREATE_N(a);
		ADD_HEAD(l,p);	
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

node SEARCH(LIST l, char* name){
	node p=l.pHead;
	while(p!=NULL && strcmp(p->data.ten,name)!=0){
		p=p->next;
	}
	return p;
}

node SEARCH_MAX(LIST l){
	node g=l.pHead;
	node p=l.pHead->next;
	while (p!=NULL){
		if (p->data.m > g->data.m)
			g=p;
		p=p->next;
	}
	return g;
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

int REMOVE_X(LIST &l, char* t){
	node p, q=NULL;
	p=l.pHead;
	while((p!=NULL) && strcmp(p->data.maso, t)!=0){
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

void PRINT_AVG(LIST l){
	node p;
	p=l.pHead;
	cout<<"\t"<<setw(25)<<left<<"Ten";
	cout<<setw(10)<<left<<"Ma So";
	cout<<setw(25)<<right<<"Nam xuat ban";
	cout<<setw(25)<<right<<"Tong so lan muon - tra";
	cout<<"\n";
	while(p!=NULL){
		if (p->data.m>=10){
			cout<<"\t"<<setw(25)<<left<<p->data.ten;
			cout<<setw(10)<<left<<p->data.maso;
			cout<<setw(25)<<right<<p->data.nam;
			cout<<setw(25)<<right<<p->data.m<<"\n";
		}
		p=p->next;
	}
	cout<<"\n";
}

void QUICK_SORT_NPH(LIST &l){
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
		if (p->data.nam <= x->data.nam)
			ADD_HEAD(l1,p);
		else
			ADD_HEAD(l2,p);
	}
	QUICK_SORT_NPH(l1);
	QUICK_SORT_NPH(l2);
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

void INSERT(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ten sach : "; cin.getline(x.ten,40);
	cout<<"Nhap ma so sach : "; cin.getline(x.maso,40);
	cout<<"Nhap nam xuat ban : "; cin>>x.nam;
	cout<<"Nhap tong so lan muon - tra sach :"; cin>>x.m;
	node p=CREATE_N(x), q=l.pHead;
	if (p->data.nam <= l.pHead->data.nam){
		ADD_HEAD(l,p);
	}
	else
	if (p->data.nam > l.pTail->data.nam){
		ADD_TAIL(l,p);
	}	
	else{
		node t=new Node;
		while (q!=NULL && q->data.nam<x.nam){
			q=q->next;	
		}
		for (node k=l.pHead; k!=NULL; k=k->next){
			if (k->data.nam==q->data.nam){
				p->next=k;
				t->next=p;
			}
			t=k;
		}
	}
}

int main(){
	node p;
	BOOK a;
	LIST l;
	CREATE_L(l);
	int c=-1;
	do{ 
		cout<<"\n";
		cout<<"\t------------------------------CHUONG TRINH QUAN LY SACH CUA THU VIEN-------------------------------\n";
		cout<<"\t\t1. Nhap danh sach cac quyen sach trong thu vien \n";
		cout<<"\t\t2. Tim quyen sach X co trong thu vien hay khong \n";
		cout<<"\t\t3. Xoa 1 quyen co ma so X \n";
		cout<<"\t\t4. Liet ke thong tin cac quyen sach co so lan muon lon hon hay bang 10 lan \n";
		cout<<"\t\t5. Sap xep cac quyen sach theo thu tu nam xuat ban tang dan \n";
		cout<<"\t\t6. Cuon sach co tong so lan muon - tra nhieu nhat \n";
		cout<<"\t\t7. Them vao 1 quyen sach vao danh sach sao cho danh sach van tang theo nam xuat ban\n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t---------------------------------------------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"Nhap lua chon : ";
		cin>>c;
		cout<<"\n";
		switch (c){
			case 1:{
				cout<<"Nhap danh sach cac quyen sach \n";
				cin.ignore();
				INPUT(l,p,a);
				break;
			}
			case 2:{
				cout<<"Nhap ten quyen sach X : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				p=SEARCH(l,x);
				cout<<"\n";
				if (p==NULL)
					cout<<"Khong tim thay quyen sach X trong thu vien !";
				else{
					cout<<"Quyen sach X co trong thu vien !\n";
				}
				break;
			}
			case 3:{
				cout<<"Nhap ma so X cua quyen sach : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				cout<<"Danh sach sau khi xoa quyen sach co ma so X : \n";
				REMOVE_X(l,x);
				PRINT_L(l);
				break;
			}
			case 4:{
				cout<<"Thong tin quyen sach co so lan muon lon hon hay bang 10 lan : \n";
				PRINT_AVG(l);
				break;
			}
			case 5:{
				cout<<"Danh sach sinh vien sau khi sap xep tang dan theo nam phat hanh : \n";
				QUICK_SORT_NPH(l);
				PRINT_L(l);
				break;
			}
			case 6:{
				cout<<"Cuon sach co tong so lan muon - tra nhieu nhat :\n";
				p=SEARCH_MAX(l);
				cout<<"\t"<<setw(25)<<left<<"Ten";
				cout<<setw(10)<<left<<"Ma So";
				cout<<setw(25)<<right<<"Nam xuat ban";
				cout<<setw(25)<<right<<"Tong so lan muon - tra";
				cout<<"\n";
				cout<<"\t"<<setw(25)<<left<<p->data.ten;
				cout<<setw(10)<<left<<p->data.maso;
				cout<<setw(25)<<right<<p->data.nam;
				cout<<setw(25)<<right<<p->data.m<<"\n";
				break;
			}
			case 7:{
				BOOK b;
				INSERT(l,b);
				cout<<"Danh sach sau khi da them vao quyen sach X : \n";
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
