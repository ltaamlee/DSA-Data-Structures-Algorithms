#include <bits/stdc++.h>
#define ElementType int
using namespace std;
ifstream f1, f3;
ofstream f2;
char c;
struct SV{
	string name;
	string id;
	float gpa;
};

struct Node{
    ElementType info;
    Node *next;
};

typedef struct Node* node;

struct LIST{
    node Head;
    node Tail;
};

node CreateNode(int x){
    node n=new Node;
    n->info=x;
    n->next=NULL;
    return n;
}

void InitList(LIST &l){
    l.Head=l.Tail=NULL;
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

void DoSort(LIST &l){
	LIST l1,l2;
	InitList(l1);
	InitList(l2);
	if (l.Head==l.Tail) return;
	node pivot, p;
	pivot=l.Head;
	p=l.Head->next;
	while (p!=NULL){
		node q=p;
		p=p->next;
		q->next=NULL;
		if (q->info < pivot->info)
			AddLast(l1,q);
		else 
			AddLast(l2,q);
	}
	DoSort(l1);
	DoSort(l2);
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

void RemoveFirst(LIST &l){
	if (isEmptyList(l))
		cout<<"Danh sach rong !";
	else{
		node p=l.Head;
		if (l.Head==l.Tail)
			l.Head=l.Tail=NULL;
		else
			l.Head=l.Head->next;
		delete p;
	}
	
}

void RemoveLast(LIST &l){
	if (isEmptyList(l))
		cout<<"Danh sach rong";
	else{
		node p=l.Tail;
		if (l.Head==l.Tail)
			l.Head=l.Tail=NULL;
		else{
			node q;
			for (q=l.Head; q->next!=l.Tail; q=q->next);
			q->next=NULL;
			l.Tail=q;
		}
		delete p;
	}
}

void RemoveNode(LIST &l, ElementType x){
	while (l.Tail->info >= x && l.Tail->next==NULL){
		RemoveLast(l);
	}
}

int SearchNode(LIST l, ElementType x){
	node p=l.Head;
	while(p!=NULL){
		if (p->info==x)
			return 1;
		p=p->next;
	}
	return 0;
}

void Input(LIST& l, const string&filename){
	ifstream f1(filename);
	ElementType x;
	while (f1>>x){
		node p=CreateNode(x);
		AddLast(l,p);
		if (f1.eof()) break;
	}
}

void Output(LIST l){
	f2<<"Danh sach cac so nguyen : ";
	node p=l.Head;
	while(p!=NULL){
		f2<<p->info<<" ";
		p=p->next;
	}
	f2<<"\n\n";
}

void N1(LIST l, ElementType &X){
	cout<<"Nhap X = ";
	cin>>X;
	f2<<"X = "<<X<<"\n";
	f2<<"Danh sach cac phan tu co gia tri >=X : ";
	int cnt=0;
	node p=l.Head;
	while(p!=NULL){
		if (p->info >=X){
			cnt++;
			f2<<p->info<<" ";
		}
		p=p->next;
	}
	if (cnt==0) f2<<"Khong co !";
	f2<<"\n\n";
}

void N2(LIST &l, ElementType &X){
	cout<<"Nhap X = ";
	cin>>X;
	DoSort(l);
	RemoveNode(l,X);
	f2<<"X = "<<X<<"\n";
	Output(l);
}

void N3(LIST l){
	node p=l.Head;
    int Max=p->info;
    while(p!=NULL){
        if(p->info>Max){
            Max=p->info;
        }
        p=p->next;
    }
    f2<<Max<<"\n";
}

void N4(LIST l){
	node p=l.Head;
	int cnt=0;
	while(p!=NULL){
		if (p->info<0)
			cnt++;
		p=p->next;
	}
	f2<<"Co "<<cnt<<" phan tu am trong danh sach \n";
}

void N5(LIST l){
	node p=l.Head;
	int cnt=0;
	int Max=-1e9;
	while(p!=NULL){
		if (p->info<0 && p->info>Max){
			Max=p->info;
			cnt++;
		}
		p=p->next;
	}
	if (cnt>0) f2<<"So am lon nhat trong danh sach : "<<Max;
	else f2<<"Danh sach khong co so am !";
	f2<<"\n";
}

void N6(LIST l){
	node p=l.Head;
	int cnt=0;
	int Min=1e9;
	while(p!=NULL){
		if (p->info>0 && p->info<Min){
			Min=p->info;
			cnt++;
		}
		p=p->next;
	}
	if(cnt>0) f2<<"So duong nho nhat danh sach : "<<Min;
	else f2<<"Danh sach khong co so duong !";
	f2<<"\n";
}

void N7(LIST l, ElementType &X){
	cout<<"Nhap X = ";
	cin>>X;
	f2<<"X = "<<X<<"\n";
	node p=l.Head;
	int cnt=0;
	while(p!=NULL){
		if (p->info==X)
			cnt++;
		p=p->next;
	}
	f2<<"Co "<<cnt<<" phan tu X trong danh sach \n";
}

struct NodeSV{
	SV info;
	NodeSV *next;
};

typedef struct NodeSV* nodeSV;

struct LISTSV{
    nodeSV Head;
    nodeSV Tail;
};

nodeSV CreateNodeSV(SV x){ 
    nodeSV p=new NodeSV;
    p->info=x;
    p->next=NULL;
    return p;
}

int isEmptyList(LISTSV l){
	if (l.Head==NULL)
		return 1;
	return 0;
}

void InitList(LISTSV &l){
    l.Head=l.Tail=NULL;
}

void AddFirstSV(LISTSV &l, nodeSV p){
	if (l.Head==NULL){
		l.Head=p;
		l.Tail=l.Head;
	}
	else{
		p->next=l.Head;
		l.Head=p;
	}
}

void AddLastSV(LISTSV &l, nodeSV p){
	if (l.Head==NULL){
		l.Head=p;
		l.Tail=l.Head;
	}
	else{
		l.Tail->next=p;
		l.Tail=p;
	}
}

void RemoveFirstSV(LISTSV &l){
	nodeSV p=l.Head;
	if (l.Head==l.Tail)
		l.Head=l.Tail=NULL;
	else
		l.Head=l.Head->next;
	delete p;
}

void RemoveLastSV(LISTSV &l){
	if (isEmptyList(l))
		cout<<"Danh sach rong";
	else{
		nodeSV p=l.Tail;
		if (l.Head==l.Tail)
			l.Head=l.Tail=NULL;
		else{
			nodeSV q;
			for (q=l.Head; q->next!=l.Tail; q=q->next);
			q->next=NULL;
			l.Tail=q;
		}
		delete p;
	}
}

void RemoveNodeSV(LISTSV &l, float &x){
	while (l.Tail->info.gpa >= x && l.Tail->next==NULL){
		RemoveLastSV(l);
	}
}

int SearchNodeSV(LISTSV l, SV x){
	nodeSV p=l.Head;
	while(p!=NULL){
		if (p->info.gpa==x.gpa)
			return 1;
		p=p->next;
	}
	return 0;
}

void DoSort(LISTSV &l){
	LISTSV l1,l2;
	InitList(l1);
	InitList(l2);
	if (l.Head==l.Tail) return;
	nodeSV pivot, p;
	pivot=l.Head;
	p=l.Head->next;
	while (p!=NULL){
		nodeSV q=p;
		p=p->next;
		q->next=NULL;
		if (q->info.gpa < pivot->info.gpa)
			AddLastSV(l1,q);
		else 
			AddLastSV(l2,q);
	}
	DoSort(l1);
	DoSort(l2);
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

void DoSort2(LISTSV &l){
	LISTSV l1,l2;
	InitList(l1);
	InitList(l2);
	if (l.Head==l.Tail) return;
	nodeSV pivot, p;
	pivot=l.Head;
	p=l.Head->next;
	while (p!=NULL){
		nodeSV q=p;
		p=p->next;
		q->next=NULL;
		if (q->info.gpa > pivot->info.gpa)
			AddLastSV(l1,q);
		else 
			AddLastSV(l2,q);
	}
	DoSort2(l1);
	DoSort2(l2);
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

void InputSV(LISTSV &l, const string&filename){
	ifstream f3(filename);
	SV a;
	while (getline(f3,a.name) && getline(f3,a.id) && f3>>a.gpa){
		nodeSV p=CreateNodeSV(a);
		AddFirstSV(l,p);
		f3.ignore();	
		if (f3.eof()) break;	
	}
}

void OutputSV(LISTSV l){
	nodeSV p;
	p=l.Head;
	f2<<"\t"<<setw(25)<<left<<"Ten";
	f2<<setw(10)<<left<<"Ma So";
	f2<<setw(20)<<right<<"Diem trung binh";
	f2<<"\n";
	while(p!=NULL){
		f2<<"\t"<<setw(25)<<left<<p->info.name;
		f2<<setw(10)<<left<<p->info.id;
		f2<<setw(20)<<right<<p->info.gpa<<"\n";
		p=p->next;
	}
	f2<<"\n";
}

void InsertSV(LISTSV &l, nodeSV p){
	DoSort(l);
	if (p->info.gpa <= l.Head->info.gpa)
		AddFirstSV(l,p);
	else 
	if (p->info.gpa >l.Tail->info.gpa)
		AddLastSV(l,p);
	else{
		nodeSV q=l.Head;
		while (q!=NULL && q->info.gpa < p->info.gpa){
				q=q->next;
		}
		nodeSV g=new NodeSV;
		for (nodeSV k=l.Head; k!=NULL; k=k->next){
			if (k->info.gpa == q->info.gpa){
				p->next=k;
				g->next=p;
			}
			g=k;
		}
		
	}
}

void S1(LISTSV &l, SV &y){
	cout<<"Nhap ten sinh vien : "; getline(cin,y.name);
	cout<<"Nhap ma so sinh vien : "; getline(cin,y.id);
	cout<<"Nhap diem trung binh : "; cin>>y.gpa;
	nodeSV p=CreateNodeSV(y);
	InsertSV(l,p);
	OutputSV(l);
}

void S2(LISTSV &l, float x){
	cout<<"Nhap X = ";
	cin>>x;
	nodeSV p=l.Head;
	DoSort(l);
	int cnt=0;
	while(p!=NULL){
		if (p->info.gpa >= x)
			cnt++;
		p=p->next;
	}
	nodeSV q=l.Head;
	if (cnt>0){	
		f2<<"\t"<<setw(25)<<left<<"Ho ten";
		f2<<setw(10)<<left<<"MSSV";
		f2<<setw(20)<<right<<"Diem trung binh";
		f2<<"\n";
		while(q!=NULL){
			if (q->info.gpa >= x){
				f2<<"\t"<<setw(25)<<left<<q->info.name;
				f2<<setw(10)<<left<<q->info.id;
				f2<<setw(20)<<right<<q->info.gpa<<"\n";	
			}
			q=q->next;
			cnt--;
		}
	}
	else f2<<"Khong co !";
}

void S3(LISTSV l, float &x){
	cout<<"Nhap X = ";
	cin>>x;
	RemoveNodeSV(l,x);
	OutputSV(l);
}

void S4(LISTSV l, int k){
	cout<<"Nhap k = ";
	cin>>k;
	DoSort2(l);
	f2<<"\t"<<setw(25)<<left<<"Ho ten";
	f2<<setw(10)<<left<<"MSSV";
	f2<<setw(20)<<right<<"Diem trung binh";
	f2<<"\n";
	nodeSV p=l.Head;
	while(p!=NULL){
		f2<<"\t"<<setw(25)<<left<<p->info.name;
		f2<<setw(10)<<left<<p->info.id;
		f2<<setw(20)<<right<<p->info.gpa<<"\n";
		p=p->next;
		k--;
		if (k==0) break;
	}
}

int main(){
	LIST l;
	LISTSV lsv;
	InitList(l);
	InitList(lsv);
    system("cls");
	cout<<"\t---------------------CHUONG TRINH THAO TAC VOI DANH SACH-------------------------\n";
	cout<<"\tBan muon thao tac tren danh sanh kieu so nguyen hay danh sach kieu sinh vien ?\n";
	cout<<"\tChon kieu so nguyen (N), chon kieu sinh vien (S) : ";
	cin>>c;
	cout<<"\n";
	int key;
	f2.open("KQ.TXT",ios::out);
    if (c=='N'){
        f1.open("SN.TXT",ios::in);
        Input(l,"SN.TXT");
        f1.close();
        Output(l);
        do{
			cout<<"\t--------------------------CHUONG TRINH THAO TAC VOI KIEU SO NGUYEN----------------------------\n";
			cout<<"\t\t1. Lay danh sach cac phan tu co gia tri >= X \n";
			cout<<"\t\t2. Xoa danh sach cac phan tu co gia tri >= X \n";
			cout<<"\t\t3. Phan tu lon nhat trong mang \n";
			cout<<"\t\t4. Dem so phan tu co gia tri am trong mang \n";
			cout<<"\t\t5. Cho biet gia tri am lon nhat trong mang \n";
			cout<<"\t\t6. Cho biet gia tri duong nho nhat trong mang \n";
			cout<<"\t\t7. Dem so phan tu co gia tri = X. Neu khong co xuat ra cau thong bao 'Khong co !'\n";
			cout<<"\t\t0. Ket thuc chuong trinh \n";
			cout<<"\t----------------------------------------------------------------------------------------------\n";
			cout<<"Nhap lua chon : ";
			cin>>key;
			ElementType X; 
			switch (key){
				case 1:{
					f2<<"1.\n";
					N1(l,X);
					break;
				}
				case 2:{
					f2<<"2.\n";
					N2(l,X);
					break;
				}
				case 3:{
					f2<<"3. Phan tu lon nhat trong mang : ";
					N3(l);
					f2<<"\n";
					break;
				}
				case 4:{
					f2<<"4.\n";
					N4(l);
					f2<<"\n";
					break;
				}
				case 5:{
					f2<<"5.\n";
					N5(l);
					f2<<"\n";
					break;
				}
				case 6:{
					f2<<"6.\n";
					N6(l);
					f2<<"\n";
					break;
				}
				case 7:{
					f2<<"7.\n";
					N7(l,X);
					f2<<"\n";
					break;
				}
				case 0:
					cout<<setw(50)<<left<<"\t\t\tKet thuc chuong trinh thao tac voi kieu so nguyen ! \n";
					cout<<"\t------------------------------------------------------------------------\n";
					break;
				default:
					cout<<"Lua chon khong ton tai trong menu !";
					cout<<"\n";
					break;
			}
		}while (key!=0);
	}
	else
	if (c=='S'){
		f3.open("SV.TXT",ios::in);
		InputSV(lsv,"SV.TXT");
		f3.close();
		OutputSV(lsv);
		do{
			cout<<"\t-----------------------------CHUONG TRINH THAO TAC VOI KIEU SINH VIEN--------------------------------\n";
			cout<<"\t\t1. Chen 1 sinh vien vao lop hoc sao cho danh sach van tang theo diem trung binh \n";
			cout<<"\t\t2. Lay danh sach sinh vien co diem trung binh >= X. Neu khong co xuat thong bao 'Khong co !' \n";
			cout<<"\t\t3. Xoa tat ca sinh vien co diem trung binh >= X \n";
			cout<<"\t\t4. Tim k sinh vien co diem trung binh cao nhat \n";
			cout<<"\t\t0. Ket thuc chuong trinh !\n";
			cout<<"\t-----------------------------------------------------------------------------------------------------\n";
			cout<<"Nhap lua chon : ";
			cin>>key;
			float X;
			SV Y;
			int K;
			cin.ignore();
			switch (key){
				case 1:{
					f2<<"1.\n";
					S1(lsv,Y);
					f2<<"\n";
					break;
				}
				case 2:{
					f2<<"2.\n";
					S2(lsv,X);
					f2<<"\n";
					break;
				}
				case 3:{
					f2<<"3.\n";
					S3(lsv,X);
					f2<<"\n";
					break;
				}
				case 4:{
					f2<<"4.\n";
					S4(lsv,K);
					f2<<"\n";
					break;
				}
				case 0:
					cout<<setw(50)<<left<<"\t\t\tKet thuc chuong trinh thao tac voi kieu sinh vien ! \n";
					cout<<"\t------------------------------------------------------------------------\n";
					break;
				default:
					cout<<"Lua chon khong ton tai trong menu !";
					cout<<"\n";
					break;
			}
		} while (key!=0);
	}
	f2.close();
    return 0;
}
