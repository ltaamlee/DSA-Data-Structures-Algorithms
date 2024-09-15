#include <bits/stdc++.h>
using namespace std;

struct SV{
	char ten[40];
	char maso[40];
	float dtb;
};

struct Node{
	SV data;
	Node *next;
};

typedef struct Node* node;

typedef struct List{
	node pHead;
	node pTail;
}LIST;

node CREATE_N(SV x){
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
	cout<<setw(20)<<right<<"Diem trung binh";
	cout<<"\n";
	while(p!=NULL){
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(10)<<left<<p->data.maso;
		cout<<setw(20)<<right<<p->data.dtb<<"\n";
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

void INPUT(LIST &l, node p, SV &a){
	while (true){
		cout<<"Nhap ten sinh vien (Enter de ket thuc) : "; cin.getline(a.ten,40);
		if (strlen(a.ten)==0) break;
		cout<<"Nhap ma so sinh vien : "; cin.getline(a.maso,40);
		cout<<"Nhap diem trung binh : "; cin>>a.dtb;
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
	while((p!=NULL) && strcmp(p->data.maso, m)!=0){
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
	cout<<setw(20)<<right<<"Diem trung binh";
	cout<<"\n";
	while(p!=NULL){
		if (p->data.dtb>=5){
			cout<<"\t"<<setw(25)<<left<<p->data.ten;
			cout<<setw(10)<<left<<p->data.maso;
			cout<<setw(20)<<right<<p->data.dtb<<"\n";
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
	cout<<setw(20)<<right<<"Diem trung binh";
	cout<<setw(20)<<right<<"Xep loai";
	cout<<"\n";
	while (p!=NULL){
		if (p->data.dtb<=3.6) r="Yeu";
		else
		if (3.6< p->data.dtb && p->data.dtb <5) r="Trung Binh Yeu";
		else
		if (5.0 <= p->data.dtb && p->data.dtb <6.5) r="Trung Binh";
		else
		if (6.5 <= p->data.dtb && p->data.dtb <7.0) r="Trung Binh Kha";
		else
		if (7.0 <= p->data.dtb && p->data.dtb <8.0) r="Kha";
		else
		if (8.0 <= p->data.dtb && p->data.dtb <9.0) r="Gioi";
		else
		if (9.0 <= p->data.dtb) r="Xuat Sac";
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(10)<<left<<p->data.maso;
		cout<<setw(20)<<right<<p->data.dtb;
		cout<<setw(20)<<right<<r<<"\n";
		p=p->next;
	}
}

void QUICK_SORT_DTB(LIST &l){
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
		if (p->data.dtb <= x->data.dtb)
			ADD_HEAD(l1,p);
		else
			ADD_HEAD(l2,p);
	}
	QUICK_SORT_DTB(l1);
	QUICK_SORT_DTB(l2);
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

void INSERT(LIST &l, SV &x){
	cin.ignore();
	cout<<"Nhap ten sinh vien : "; cin.getline(x.ten,40);
	cout<<"Nhap ma so sinh vien : "; cin.getline(x.maso,40);
	cout<<"Nhap diem trung binh : "; cin>>x.dtb;
	node p=CREATE_N(x), q=l.pHead;
	if (p->data.dtb <= l.pHead->data.dtb){
		ADD_HEAD(l,p);
	}
	else
	if (p->data.dtb > l.pTail->data.dtb){
		ADD_TAIL(l,p);
	}	
	else{
		node t=new Node;
		while (q!=NULL && q->data.dtb<x.dtb){
			q=q->next;	
		}
		for (node k=l.pHead; k!=NULL; k=k->next){
			if (k->data.dtb==q->data.dtb){
				p->next=k;
				t->next=p;
			}
			t=k;
		}
	}
}

int main(){
	node p;
	SV a;
	LIST l;
	CREATE_L(l);
	int c=-1;
	do{ 
		cout<<"\n";
		cout<<"\t----------------------------------CHUONG TRINH QUAN LY HOC SINH------------------------------------\n";
		cout<<"\t\t1. Nhap danh sach sinh vien \n";
		cout<<"\t\t2. Tim sinh vien X co trong lop hoc hay khong \n";
		cout<<"\t\t3. Xoa 1 sinh vien co ma so X \n";
		cout<<"\t\t4. Liet ke thong tin sinh vien co diem trung binh lon hon hay bang 5 \n";
		cout<<"\t\t5. Xep loai sinh vien \n";
		cout<<"\t\t6. Sap xep sinh vien theo diem trung binh tang dan \n";
		cout<<"\t\t7. Chen 1 sinh vien vao danh sach sao cho danh sach van tang theo diem trung binh\n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t---------------------------------------------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"Nhap lua chon : ";
		cin>>c;
		cout<<"\n";
		switch (c){
			case 1:{
				cout<<"Nhap danh sach sinh vien \n";
				cin.ignore();
				INPUT(l,p,a);
				break;
			}
			case 2:{
				cout<<"Nhap ten sinh vien X : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				p=SEARCH(l,x);
				cout<<"\n";
				if (p==NULL)
					cout<<"Khong tim thay sinh vien trong lop hoc !";
				else{
					cout<<"Sinh vien co trong lop hoc !\n";
				}
				break;
			}
			case 3:{
				cout<<"Nhap ma so X cua sinh vien : ";
				cin.ignore();
				char* x = new char[40];
				cin.getline(x,40);
				cout<<"Danh sach sau khi xoa sinh vien co ma so X : \n";
				REMOVE_X(l,x);
				PRINT_L(l);
				break;
			}
			case 4:{
				cout<<"Thong tin sinh vien co diem trung binh lon hon hay bang 5 : \n";
				PRINT_AVG(l);
				break;
			}
			case 5:{
				cout<<"Xep loai sinh vien : \n";
				RANK(l);
				break;
			}
			case 6:{
				cout<<"Danh sach sinh vien sau khi sap xep theo diem trung binh : \n";
				QUICK_SORT_DTB(l);
				PRINT_L(l);
				break;
			}
			case 7:{
				SV b;
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
