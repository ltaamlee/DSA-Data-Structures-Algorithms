#include <bits/stdc++.h>
using namespace std;

struct NV{
	char ten[40];
	char id[40];
	float kpi;
};

struct Node{
	NV data;
	Node *next;
};

typedef struct Node* node;

typedef struct List{
	node pHead;
	node pTail;
}LIST;

node CREATE_N(NV x){
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
	cout<<setw(25)<<right<<"Hieu suat lam viec (%)";
	cout<<"\n";
	while(p!=NULL){
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(10)<<left<<p->data.id;
		cout<<setw(25)<<right<<p->data.kpi<<"\n";
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

void INPUT(LIST &l, node p, NV &a){
	while (true){
		cout<<"Nhap ten nhan vien (Enter de ket thuc) : "; cin.getline(a.ten,40);
		if (strlen(a.ten)==0) break;
		cout<<"Nhap ma so nhan vien : "; cin.getline(a.id,40);
		cout<<"Nhap hieu suat lam viec KPI(%) : "; cin>>a.kpi;
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

node SEARCH(LIST l){
	node g=l.pHead;
	node p=l.pHead->next;
	while (p!=NULL){
		if (p->data.kpi > g->data.kpi)
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
	while((p!=NULL) && strcmp(p->data.id, m)!=0){
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
	cout<<setw(25)<<right<<"Hieu suat lam viec (%)";
	cout<<"\n";
	while(p!=NULL){
		if (p->data.kpi>=50.0){
			cout<<"\t"<<setw(25)<<left<<p->data.ten;
			cout<<setw(10)<<left<<p->data.id;
			cout<<setw(25)<<right<<p->data.kpi<<"\n";
		}
		p=p->next;
	}
	cout<<"\n";
}

void RANK(LIST l){
	node p;
	p=l.pHead;
	string r;
	cout<<"\t"<<setw(25)<<left<<"Ten";
	cout<<setw(10)<<left<<"Ma So";
	cout<<setw(25)<<right<<"Hieu suat lam viec (%)";
	cout<<setw(25)<<right<<"Xep hang";
	cout<<"\n";
	while (p!=NULL){
		if (p->data.kpi<=30.6) r="Kem";
		else
		if (30.6< p->data.kpi && p->data.kpi <50.0) r="Yeu";
		else
		if (50.0 <= p->data.kpi && p->data.kpi <60.5) r="Trung Binh";
		else
		if (60.5 <= p->data.kpi && p->data.kpi <70.0) r="Trung Binh Kha";
		else
		if (70.0 <= p->data.kpi && p->data.kpi <80.0) r="Kha";
		else
		if (80.0 <= p->data.kpi && p->data.kpi <90.0) r="Tot";
		else
		if (90.0 <= p->data.kpi) r="Xuat Sac";
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(10)<<left<<p->data.id;
		cout<<setw(25)<<right<<p->data.kpi;
		cout<<setw(25)<<right<<r<<"\n";
		p=p->next;
	}
}

void QUICK_SORT_KPI(LIST &l){
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
		if (p->data.kpi <= x->data.kpi)
			ADD_HEAD(l1,p);
		else
			ADD_HEAD(l2,p);
	}
	QUICK_SORT_KPI(l1);
	QUICK_SORT_KPI(l2);
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

void INSERT(LIST &l, NV &x){
	cin.ignore();
	cout<<"Nhap ten nhan vien : "; cin.getline(x.ten,40);
	cout<<"Nhap ma so nhan vien : "; cin.getline(x.id,40);
	cout<<"Nhap hieu suat lam viec (%) : "; cin>>x.kpi;
	node p=CREATE_N(x), q=l.pHead;
	if (p->data.kpi <= l.pHead->data.kpi){
		ADD_HEAD(l,p);
	}
	else
	if (p->data.kpi > l.pTail->data.kpi){
		ADD_TAIL(l,p);
	}	
	else{
		node t=new Node;
		while (q!=NULL && q->data.kpi<x.kpi){
			q=q->next;	
		}
		for (node k=l.pHead; k!=NULL; k=k->next){
			if (k->data.kpi==q->data.kpi){
				p->next=k;
				t->next=p;
			}
			t=k;
		}
	}
}

int main(){
	node p;
	NV a;
	LIST l;
	CREATE_L(l);
	int c=-1;
	do{ 
		cout<<"\n";
		cout<<"\t---------------------------CHUONG TRINH QUAN LY NHAN VIEN TRONG CONG TY----------------------------\n";
		cout<<"\t\t1. Nhap danh sach nhan vien \n";
		cout<<"\t\t2. Xoa 1 nhan vien co ma so X \n";
		cout<<"\t\t3. Liet ke thong tin nhan vien co hieu suat lam viec lon hon hay bang 50% \n";
		cout<<"\t\t4. Tim nhan vien co hieu suat lam viec cao nhat \n";
		cout<<"\t\t5. Xep hang hieu suat nhan vien \n";
		cout<<"\t\t6. Sap xep nhan vien theo hieu suat lam viec tang dan \n";
		cout<<"\t\t7. Chen 1 nhan vien vao danh sach sao cho danh sach van tang theo hieu suat lam viec \n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t---------------------------------------------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"Nhap lua chon : ";
		cin>>c;
		cout<<"\n";
		switch (c){
			case 1:{
				cout<<"Nhap danh sach nhan vien \n";
				cin.ignore();
				INPUT(l,p,a);
				break;
			}
			case 2:{
				cout<<"Nhap ma so X cua sinh vien : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				cout<<"Danh sach sau khi xoa nhan vien co ma so X : \n";
				REMOVE_X(l,x);
				PRINT_L(l);
				break;
			}
			case 3:{
				cout<<"Thong tin nhan vien co hieu suat lam viec lon hon hay bang 50% : \n";
				PRINT_AVG(l);
				break;
			}
			case 4:{
				cout<<"Nhan vien co hieu suat lam viec cao nhat : \n";
				p=SEARCH(l);
				cout<<"\t"<<setw(25)<<left<<"Ten";
				cout<<setw(10)<<left<<"Ma So";
				cout<<setw(25)<<right<<"Hieu suat lam viec (%)";
				cout<<"\n";
				cout<<"\t"<<setw(25)<<left<<p->data.ten;
				cout<<setw(10)<<left<<p->data.id;
				cout<<setw(25)<<right<<p->data.kpi<<"\n";
				break;
			}
			case 5:{
				cout<<"Xep hang nhan vien : \n";
				RANK(l);
				break;
			}
			case 6:{
				cout<<"Danh sach nhan vien sau khi sap xep theo hieu suat lam viec : \n";
				QUICK_SORT_KPI(l);
				PRINT_L(l);
				break;
			}
			case 7:{
				NV b;
				INSERT(l,b);
				cout<<"Danh sach sau khi da chen nhan vien X : \n";
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
