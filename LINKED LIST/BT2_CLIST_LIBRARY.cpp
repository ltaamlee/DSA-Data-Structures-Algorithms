#include <bits/stdc++.h>
using namespace std;

struct Book{
	string ten;
	vector<string> tg;
	string nxb;
	int nam;
};

struct Node{
	Book data;
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

node CreateNode(Book x){
	node n=new Node;
	n->data.ten=x.ten;
	n->data.tg=x.tg;
	n->data.nxb=x.nxb;
	n->data.nam=x.nam;
	n->next=NULL;
	return n;
}

int isEmptyList(LIST &l){
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

void Input(LIST &l){
	Book x;
	do{
		cout<<"Nhap ten quyen sach (Enter de dung viec nhap thong tin sach) : "; getline(cin,x.ten);
		if (x.ten=="") break;
		cout<<"Nhap nha xuat ban : "; getline(cin,x.nxb);
		cout<<"Nhap nam xuat ban : "; cin>>x.nam;
		cin.ignore();
		cout<<"Nhap tac gia (Toi da 5 tac gia) (Enter de dung viec nhap tac gia): "; 
		string t;
		int i=1;
		do{
			getline(cin,t);
			i++;
			if (t=="" || i>5) break;
			x.tg.push_back(t);	
		} while (t!="" && i<=5);
		node p=CreateNode(x);
		AddLast(l,p);
		x.tg.clear();
	} while (x.ten!="");
}

void Output(LIST l){
	node p=l.Head;
	cout<<"\t"<<setw(25)<<left<<"Ten quyen sach";
	cout<<setw(30)<<left<<"Nha xuat ban";
	cout<<setw(20)<<left<<"Nam xuat ban";
	cout<<setw(25)<<right<<"Ten tac gia";
	cout<<"\n\n";
	while (p!=NULL){
		cout<<"\t"<<setw(25)<<left<<p->data.ten;
		cout<<setw(30)<<left<<p->data.nxb;
		cout<<setw(20)<<left<<p->data.nam;
		if (p->data.tg.size()==1)
			cout<<setw(25)<<right<<p->data.tg[0];
		else{
			cout<<setw(25)<<right<<p->data.tg[0]<<"\n";
			for (int i=1; i<p->data.tg.size(); ++i) {
            	cout<<setw(108)<<right<<p->data.tg[i];
            	cout<<"\n";
        	}
		} 
		cout<<"\n";
		p=p->next;	
	}
}

void S3(LIST &l, string &author){
	cout<<"Nhap ten tac gia : "; 
	cin.ignore();
	getline(cin,author);
	node p=l.Head;
	int cnt=0;
	while (p!=NULL){
		for (int i=0; i<p->data.tg.size(); ++i){
			if (p->data.tg[i]==author)
				cnt++;
		}
		p=p->next;
	}
	cout<<"Tac gia "<<author<<" co "<<cnt<<" quyen sach \n";
}

void S4(LIST &l, int &n, string &nb){
	cin.ignore();
	cout<<"Nhap nam : "; cin>>n;
	cin.ignore();
	cout<<"Nhap ten nha xuat ban : "; getline(cin,nb);	
	node p=l.Head;
	int cnt=0;
	cout<<"Ten quyen sach : ";
	while (p!=NULL){
		if (p->data.nam==n && p->data.nxb==nb){
			cout<<p->data.ten<<"\n";
			cnt++;
		}
		p=p->next;
	}
	if (cnt==0) cout<<"Khong tim thay trong thu vien ! \n";
}

int main(){
	LIST l;
	Init(l);
	int key;
	do{
		cout<<"\t-----------------------------CHUONG TRINH QUAN LI SACH THU VIEN------------------------------\n";
		cout<<"\t\t1. Nhap cac thong tin cua cac quyen sach trong thu vien \n";
		cout<<"\t\t2. In danh sach thong tin cac quyen sach trong thu vien \n";
		cout<<"\t\t3. Cho biet so luong quyen sach cua 1 tac gia bat ki \n";
		cout<<"\t\t4. Nhap vao nam va nha xuat ban. Cho biet quyen sach da phat hanh dua tren 2 thong tin do \n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t----------------------------------------------------------------------------------------------\n";	
		cout<<"Nhap lua chon : ";
		cin>>key;
		switch (key){
			case 1:{
				cin.ignore();
				Input(l);
				break;
			}
			case 2:{
				Output(l);
				break;
			}
			case 3:{
				string author;
				S3(l,author);
				break;
			}
			case 4:{
				int n;
				string nb;
				S4(l,n,nb);
				break;
			}
			case 0:{
				cout<<"\t\t"<<left<<"Ket thuc chuong trinh quan li sach thu vien ! \n";
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
