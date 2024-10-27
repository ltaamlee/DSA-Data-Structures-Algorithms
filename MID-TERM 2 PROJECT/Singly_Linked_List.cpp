#include <bits/stdc++.h>
using namespace std;
#define MAX 100
ifstream f1;

struct BOOK{
	string id;
	string name;
	string author;
	int year;
};

struct Node{
	BOOK data;
	Node *next;
};

typedef struct Node* node;

struct LIST{
	node Head;
	node Tail;
};

void Init(LIST& l){
	l.Head=l.Tail=NULL;
}

void CreateList(LIST &l){
	l.Head=l.Tail=NULL;	
}

node CreateNode(BOOK x){
	node p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}

int IsEmpty(LIST l){
	if (l.Head==NULL)
		return 1;
	return 0;
}

node Search(LIST l, string x){
	node p=l.Head;
	while(p!=NULL){
		if (p->data.name==x)
			return p;
		p=p->next;
	}
	return NULL;
}

void AddFirst(LIST &l, node p){
	if (IsEmpty(l)){
		l.Head=p;
		l.Tail=l.Head;
	}
	else{
		p->next=l.Head;
		l.Head=p;
	}
}

void AddLast(LIST &l, node p){
	if (IsEmpty(l)){
		l.Head=p;
		l.Tail=l.Head;
	}
	else{
		l.Tail->next=p;
		l.Tail=p;
	}
}

void AddAfterQ(LIST &l, node p, node q){
	p->next=q->next;
	q->next=p;
	if (l.Tail==q)
		l.Tail=p;
}

void AddNode(LIST &l, BOOK &x){
	node k=CreateNode(x);
	if (k->data.year<l.Head->data.year) AddFirst(l,k);
	else if (k->data.year>l.Tail->data.year) AddLast(l,k);
	else{
		node p=l.Head;
		node q=NULL;
		while (p!=NULL && p->data.year<x.year){
			q=p;
			p=p->next;	
		}
		AddAfterQ(l,k,q);
	}	
}

void RemoveFirst(LIST &l){
	if (IsEmpty(l))
		cout<<"Danh sach rong ! \n";
	else{
		node p=l.Head;
		if (l.Head==l.Tail) l.Head=l.Tail=NULL;
		l.Head=l.Head->next;
		delete p;
	}
}

void RemoveLast(LIST &l){
	if (IsEmpty(l))
		cout<<"Danh sach rong ! \n";
	else{
		node q=l.Tail;
		if (l.Head==l.Tail) l.Head=l.Tail=NULL;
		else{
			node p=new Node;
			for (p=l.Head; p->next!=l.Tail; p=p->next);
			p->next=NULL;
			l.Tail=p;
		}
		delete q;
	}
}

void RemoveAfterQ(LIST &l, node q){
	node p=q->next;
	if (p==NULL){
		cout<<"Khong ton tai phan tu q \n";
	}
	else{
		q->next=p->next;
		if (p==l.Tail)
			l.Tail=q;
		delete p;
	}
}

void RemoveNode(LIST &l, string x){
	node p, q=NULL;
	if (l.Head->data.name==x) RemoveFirst(l);
	else if (l.Tail->data.name==x) RemoveLast(l);
	else{
		p=l.Head;
		while((p!=NULL)){
			if (p->data.name==x)
				RemoveAfterQ(l,q);
			else
				q=p;
				p=p->next;
		}
	}
	
}


void SelectionSort(LIST& l){
	node Min=new Node;
	for (node i=l.Head; i!=NULL; i=i->next){
		Min=i;
		for (node j=i->next; j!=NULL; j=j->next){
			if (j->data.year < Min->data.year){
				Min=j;
			}
		}
		swap(Min->data, i->data);
	}
}

void DoSort(LIST &l){
	node p, x;
	LIST l1, l2;
	if (l.Head==l.Tail) return;
	CreateList(l1);
	CreateList(l2);
	x=l.Head;
	l.Head=x->next;
	while(l.Head!=NULL){
		p=l.Head;
		l.Head=p->next;
		p->next=NULL;
		if (p->data.year<= x->data.year)
			AddFirst(l1,p);
		else
			AddFirst(l2,p);
	}
	DoSort(l1);
	DoSort(l2);
	if (l1.Head!=NULL){
		l.Head=l1.Head;
		l1.Tail->next=x;
	}
	else
		l.Head=x;
	x->next=l2.Head;
	if (l2.Head!=NULL)
		l.Tail=l2.Tail;
	else
		l.Tail=x;
}

void Input(LIST &l, const string& filename){
    ifstream f1(filename);
    BOOK x;
    string line;
    while (getline(f1, line)){
        stringstream ss(line);
        if (getline(ss,x.id,',') && getline(ss,x.name,',') && getline(ss,x.author,',') && ss>>x.year){
        	node p=CreateNode(x);
            AddLast(l,p);
            if (f1.eof()) break;
        }
    }
}

void Print(LIST l){
	cout<<"\t"<<setw(25)<<left<<"Ma so";
	cout<<setw(20)<<left<<"Ten sach";
	cout<<setw(35)<<right<<"Tac gia";
	cout<<setw(25)<<right<<"Nam xuat ban";
	cout<<"\n";
	node p=l.Head;
	while (p!=NULL){
		cout<<"\t"<<setw(25)<<left<<p->data.id;
		cout<<setw(20)<<left<<p->data.name;
		cout<<setw(35)<<right<<p->data.author;
		cout<<setw(25)<<right<<p->data.year<<"\n";
		p=p->next;
	}
}

void B3(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ma so sach : "; getline(cin,x.id);
	cout<<"Nhap ten sach : "; getline(cin,x.name);
	cout<<"Nhap ten tac gia : "; getline(cin,x.author);
	cout<<"Nhap nam xuat ban : "; cin>>x.year;
	node p=CreateNode(x);
	AddFirst(l,p);
	Print(l);
}

void B4(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ma so sach : "; getline(cin,x.id);
	cout<<"Nhap ten sach : "; getline(cin,x.name);
	cout<<"Nhap ten tac gia : "; getline(cin,x.author);
	cout<<"Nhap nam xuat ban : "; cin>>x.year;
	node p=CreateNode(x);
	AddLast(l,p);
	Print(l);
}

void B7(LIST l, string x){
	cout<<"Nhap ten sach : ";
	cin.ignore();
	getline(cin,x);
	node res=Search(l,x);
	if (res!=NULL) cout<<"Quyen sach X co trong thu vien !\n";
	else cout<<"Quyen sach X khong co trong thu vien !\n";
}

void B9(LIST &l, string x){
	cout<<"Nhap ten sach : ";
	cin.ignore();
	getline(cin,x);
	RemoveNode(l,x);
	Print(l);
}

void B10(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ma so sach : "; getline(cin,x.id);
	cout<<"Nhap ten sach : "; getline(cin,x.name);
	cout<<"Nhap ten tac gia : "; getline(cin,x.author);
	cout<<"Nhap nam xuat ban : "; cin>>x.year;
	AddNode(l,x);
	Print(l);
}

int CountBook(LIST l, int &y){
	int cnt=0;
	node p=l.Head;
	while(p!=NULL){
		if (p->data.year>=y)
			cnt++;
		p=p->next;
	}
	return cnt;
}

int main(){
	LIST l;
	Init(l);
	BOOK x;
	int key=-1;
	do{ 
		cout<<"\n";
		cout<<"\t------------------------------CHUONG TRINH QUAN LY SACH CUA THU VIEN-------------------------------\n";
		cout<<"\t---------------------------------------------------------------------------------------------------\n";
		cout<<"\t\t- Cac thao tac co ban \n";
		cout<<"\t\t1. In ra danh sach cac quyen sach trong thu vien tu file BOOKS.TXT \n";
		cout<<"\t\t2. Kiem tra danh sach rong \n";
		cout<<"\t\t3. Them 1 quyen sach vao dau danh sach \n";
		cout<<"\t\t4. Them 1 quyen sach vao cuoi danh sach \n";
		cout<<"\t\t5. Huy 1 quyen sach dau danh sach \n";
		cout<<"\t\t6. Huy 1 quyen sach cuoi danh sach \n";
		cout<<"\t\t7. Tim quyen sach X co trong thu vien hay khong \n";
		cout<<"\t\t8. Sap xep cac quyen sach theo thu tu nam xuat ban tang dan \n\n";
		cout<<"\t\t- Cac thao tac nang cao \n";
		cout<<"\t\t9. Xoa 1 quyen co ten X \n";
		cout<<"\t\t10. Them 1 quyen sach vao thu vien ma khong lam mat thu tu theo nam xuat ban \n";
		cout<<"\t\t11. Dem so luong quyen sach duoc xuat ban sau nam X \n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t---------------------------------------------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"Nhap lua chon : ";
		cin>>key;
		cout<<"\n";
		switch (key){
			case 1:{
				f1.open("BOOKS.TXT",ios::in);
				Input(l,"BOOKS.TXT");
				f1.close();
				Print(l);
				break;
			}
			case 2:{
				if (IsEmpty(l))
					cout<<"Danh sach rong ! \n";
				else
					cout<<"Danh sach khong rong !\n";
				break;
			}
			case 3:{
				BOOK x;
				B3(l,x);
				break;
			}
			case 4:{
				BOOK x;
				B4(l,x);
				break;
			}
			case 5:{
				RemoveFirst(l);
				Print(l);
				break;
			}
			case 6:{
				RemoveLast(l);
				Print(l);
				break;
			}
			case 7:{
				string x;
				B7(l,x);
				break;
			}
			case 8:{
				DoSort(l);
				Print(l);
				break;
			}
			case 9:{
				string x;
				B9(l,x);
				break;
			}
			case 10:{
				BOOK x;
				B10(l,x);
				break;
			}
			case 11:{
				int year;
				cout<<"Nhap nam : ";
				cin>>year;
				cout<<"Co "<<CountBook(l,year)<<" quyen sach duoc xuat ban tu nam "<<year<<"\n";
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
	}while(key!=0);
	return 0;
}
