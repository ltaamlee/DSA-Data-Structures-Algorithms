#include <bits/stdc++.h>
using namespace std;

struct CD{
	char ten[40];
	char theloai[40];
	int nam;
	int sl;
};

struct Node{
	CD data;
	Node *next;
};

typedef struct Node* node;

typedef struct List{
	node pHead;
	node pTail;
}LIST;

node CREATE_N(CD x){
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
	cout<<setw(10)<<left<<"The loai";
	cout<<setw(25)<<right<<"Nam phat hanh";
	cout<<setw(25)<<right<<"So luot thue";
	cout<<"\n";
	while(p!=NULL){
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(10)<<left<<p->data.theloai;
		cout<<setw(25)<<right<<p->data.nam;
		cout<<setw(25)<<right<<p->data.sl<<"\n";
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

void INPUT(LIST &l, node p, CD &a){
	while (true){
		cout<<"Nhap ten dia nhac (Enter de ket thuc) : "; cin.getline(a.ten,40);
		if (strlen(a.ten)==0) break;
		cout<<"Nhap the loai : "; cin.getline(a.theloai,40);
		cout<<"Nhap nam phat hanh : "; cin>>a.nam;
		cout<<"Nhap so luot thue dia : "; cin>>a.sl;
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
	while (p!=NULL && strcmp(p->data.ten, name)!=0)
		p=p->next;
	return p;
}

node SEARCH_MAX(LIST l){
	node g=l.pHead;
	node p=l.pHead->next;
	while (p!=NULL){
		if (p->data.sl > g->data.sl)
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

int REMOVE_X(LIST &l, char* m){
	node p, q=NULL;
	p=l.pHead;
	while((p!=NULL) && strcmp(p->data.theloai, m)!=0){
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
	cout<<setw(10)<<left<<"The loai";
	cout<<setw(25)<<right<<"Nam phat hanh";
	cout<<setw(25)<<right<<"So luot thue";
	cout<<"\n";
	while(p!=NULL){
		if (p->data.sl>50){
			cout<<"\t"<<setw(25)<<left<<p->data.ten;
			cout<<setw(10)<<left<<p->data.theloai;
			cout<<setw(25)<<right<<p->data.nam;
			cout<<setw(25)<<right<<p->data.sl<<"\n";
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

void INSERT(LIST &l, CD &x){
	cin.ignore();
	cout<<"Nhap ten dia nhac : "; cin.getline(x.ten,40);
	cout<<"Nhap the loai : "; cin.getline(x.theloai,40);
	cout<<"Nhap nam phat hanh : "; cin>>x.nam;
	cout<<"Nhap so luot thue dia : "; cin>>x.sl;
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
	CD a;
	LIST l;
	CREATE_L(l);
	int c=-1;
	do{ 
		cout<<"\n";
		cout<<"\t------------------------CHUONG TRINH QUAN LY DANH SACH TIEM CHO THUE DIA---------------------------\n";
		cout<<"\t\t1. Nhap danh sach bang dia cua tiem \n";
		cout<<"\t\t2. Tim bang dia X co trong tiem hay khong \n";
		cout<<"\t\t3. Xoa 1 bang dia co the loai X \n";
		cout<<"\t\t4. Liet ke thong tin bang dia co luot cho thue lon hon 50 luot \n";
		cout<<"\t\t5. The loai bang dia duoc thue nhieu nhat \n";
		cout<<"\t\t6. Sap xep bang dai tang dan theo nam phat hanh \n";
		cout<<"\t\t7. Chen 1 bang dia vao danh sach sao cho danh sach van tang theo nam phat hanh\n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t---------------------------------------------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"Nhap lua chon : ";
		cin>>c;
		cout<<"\n";
		switch (c){
			case 1:{
				cout<<"Nhap danh sach bang dia cua tiem \n";
				cin.ignore();
				INPUT(l,p,a);
				break;
			}
			case 2:{
				cout<<"Nhap ten bang dia X : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				p=SEARCH(l,x);
				cout<<"\n";
				if (p==NULL)
					cout<<"Khong tim thay bang dia X trong tiem !";
				else{
					cout<<"Tiem co bang dia X !\n";
				}
				break;
			}
			case 3:{
				cout<<"Nhap the loai X cua bang dia : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				cout<<"Danh sach sau khi xoa bang dia co ma so X : \n";
				REMOVE_X(l,x);
				PRINT_L(l);
				break;
			}
			case 4:{
				cout<<"Thong tin bang dia co luot cho thue lon hon 50 luot : \n";
				PRINT_AVG(l);
				break;
			}
			case 5:{
				cout<<"The loai bang dia co luot thue nhieu nhat : ";
				p=SEARCH_MAX(l);
				cout<<p->data.theloai<<"\n";
				break;
			}
			case 6:{
				cout<<"Danh sach sinh vien sau khi sap xep theo diem trung binh : \n";
				QUICK_SORT_NPH(l);
				PRINT_L(l);
				break;
			}
			case 7:{
				CD b;
				INSERT(l,b);
				cout<<"Danh sach sau khi da chen sinh vien X : \n";
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
