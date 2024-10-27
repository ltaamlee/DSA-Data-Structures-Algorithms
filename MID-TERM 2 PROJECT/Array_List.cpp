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

struct LIST{
	BOOK a[MAX];
	int n;
};

void Init(LIST& l){
	l.n=0;
}

int IsEmpty(LIST l){
	if (l.n==0)
		return 1;
	return 0;
}

int IsFull(LIST l){
	if (l.n==MAX)
		return 1;
	return 0;
}

void AddFirst(LIST& l, BOOK &x){
	if (IsFull(l))
		cout<<"Danh sach day !\n";
	else{
		l.n++;
		for (int i=l.n; i>0; --i)
			l.a[i]=l.a[i-1];
		l.a[0]=x;
	}
}

void AddLast(LIST& l, BOOK &x){
	if (IsFull(l))
		cout<<"Danh sach day !\n";
	else{
		l.n++;
		l.a[l.n-1]=x;
	}
}

void AddMid(LIST& l, int k, BOOK &x){
	if (IsFull(l)){
		cout<<"Danh sach day !\n";
	}
	else if (k<0 || k>l.n){
		cout<<"Vi tri can them khong hop le !";
	}
	else{
		l.n++;
		for (int i=l.n; i>k; --i){
			l.a[i]=l.a[i-1];
		}
		l.a[k]=x;
	}
}

void RemoveFirst(LIST& l){
	if (IsEmpty(l))
		cout<<"Danh sach rong !\n";
	else{
		for (int i=0; i<l.n-1; ++i)
			l.a[i]=l.a[i+1];
		l.n--;
	}
}

void RemoveLast(LIST& l){
	if (IsEmpty(l))
		cout<<"Danh sach rong !\n";
	else{
		l.n--;
	}
}

void RemoveK(LIST &l, int k){
	if (IsEmpty(l)){
		cout<<"Danh sach rong !";
	}
	else{
		if (k<0 || k>=l.n)
			cout<<"Vi tri can xoa khong hop le !";
		else{
			for (int i=k; i<l.n; ++i)
				l.a[i]=l.a[i+1];
			l.n--;
		}
	}
}

int Search(LIST l, string x){
	for (int i=0; i<l.n; ++i){
		if (l.a[i].name==x)
			return i;
	}
	return -1;
}

void swap(BOOK &a, BOOK &b){
	BOOK temp=a;
	a=b;
	b=temp;
}

void DoSort(LIST& l){
	int Min,i,j;
	for (i=0; i<l.n-1; ++i){
		Min=i;
		for (j=i+1; j<l.n; ++j){
			if (l.a[j].year>l.a[Min].year){
				Min=j;
			}
			swap(l.a[Min],l.a[j]);
		}
	}
}

void DoSort(LIST &l, int left, int right){
	int i,j,x;
	x=l.a[(left+right)/2].year;
	i=left; j=right;
	while (i<j){
		while (l.a[i].year<x) i++;
		while (l.a[j].year>x) j--;
		if (i<=j){
			swap(l.a[i],l.a[j]);
			i++; j--;
		}
	}
	if (left<j) DoSort(l,left,j);
	if (i<right) DoSort(l,i,right);
}

void Print(LIST l){
	cout<<"\t"<<setw(25)<<left<<"Ma so";
	cout<<setw(20)<<left<<"Ten sach";
	cout<<setw(35)<<right<<"Tac gia";
	cout<<setw(25)<<right<<"Nam xuat ban";
	cout<<"\n";
	for (int i=0; i<l.n; ++i){
		cout<<"\t"<<setw(25)<<left<<l.a[i].id;
		cout<<setw(20)<<left<<l.a[i].name;
		cout<<setw(35)<<right<<l.a[i].author;
		cout<<setw(25)<<right<<l.a[i].year<<"\n";
	}
}

void Input(LIST &l, const string& filename){
    ifstream f1(filename);
    BOOK x;
    string line;
    while (getline(f1, line)){
        stringstream ss(line);
        if (getline(ss,x.id,',') && getline(ss,x.name,',') && getline(ss,x.author,',') && ss>>x.year){
            AddLast(l,x);
            if (f1.eof()) break;
        }
    }
}

void B4(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ma so sach : "; getline(cin,x.id);
	cout<<"Nhap ten sach : "; getline(cin,x.name);
	cout<<"Nhap ten tac gia : "; getline(cin,x.author);
	cout<<"Nhap nam xuat ban : "; cin>>x.year;
	AddFirst(l,x);
	Print(l);
}

void B5(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ma so sach : "; getline(cin,x.id);
	cout<<"Nhap ten sach : "; getline(cin,x.name);
	cout<<"Nhap ten tac gia : "; getline(cin,x.author);
	cout<<"Nhap nam xuat ban : "; cin>>x.year;
	AddLast(l,x);
	Print(l);
}

void B8(LIST l, string x){
	cout<<"Nhap ten sach : ";
	cin.ignore();
	getline(cin,x);
	int res=Search(l,x);
	if (res!=-1) cout<<"Quyen sach X co trong thu vien !\n";
	else cout<<"Quyen sach X khong co trong thu vien !\n";
}

void B10(LIST &l, string x){
	cout<<"Nhap ten sach : ";
	cin.ignore();
	getline(cin,x);
	int res=Search(l,x);
	cout<<res;
	if (res!=-1){
		RemoveK(l,res);
	}
	Print(l);
}

int FindYear(LIST l, int y){
	for (int i=0; i<l.n; ++i){
		if (l.a[i].year>=y)
			return i;
	}
	return -1;
}

void B11(LIST &l, BOOK &x){
	cin.ignore();
	cout<<"Nhap ma so sach : "; getline(cin,x.id);
	cout<<"Nhap ten sach : "; getline(cin,x.name);
	cout<<"Nhap ten tac gia : "; getline(cin,x.author);
	cout<<"Nhap nam xuat ban : "; cin>>x.year;
	int ans=FindYear(l,x.year);
	if (ans!=-1){
		AddMid(l,ans,x);
	}
	Print(l);
}

int CountBook(LIST l, int &y){
	int cnt=0;
	for (int i=0; i<l.n; ++i){
		if (l.a[i].year>=y)
			cnt++;
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
		cout<<"\t\t3. Kiem tra danh sach day \n";
		cout<<"\t\t4. Them 1 quyen sach vao dau danh sach \n";
		cout<<"\t\t5. Them 1 quyen sach vao cuoi danh sach \n";
		cout<<"\t\t6. Huy 1 quyen sach dau danh sach \n";
		cout<<"\t\t7. Huy 1 quyen sach cuoi danh sach \n";
		cout<<"\t\t8. Tim quyen sach X co trong thu vien hay khong \n";
		cout<<"\t\t9. Sap xep cac quyen sach theo thu tu nam xuat ban tang dan \n\n";
		cout<<"\t\t- Cac thao tac nang cao \n";
		cout<<"\t\t10. Xoa 1 quyen co ten X \n";
		cout<<"\t\t11. Them 1 quyen sach vao thu vien ma khong lam mat thu tu theo nam xuat ban \n";
		cout<<"\t\t12. Dem so luong quyen sach duoc xuat ban sau nam X \n";
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
				if (IsFull(l))
					cout<<"Danh sach day !\n";
				else
					cout<<"Danh sach khong day !\n";
				break;
			}
			case 4:{
				BOOK x;
				B4(l,x);
				break;
			}
			case 5:{
				BOOK x;
				B5(l,x);
				break;
			}
			case 6:{
				RemoveFirst(l);
				Print(l);
				break;
			}
			case 7:{
				RemoveLast(l);
				Print(l);
				break;
			}
			case 8:{
				string x;
				B8(l,x);
				break;
			}
			case 9:{
				DoSort(l,0,l.n-1);
				Print(l);
				break;
			}
			case 10:{
				string x;
				B10(l,x);
				break;
			}
			case 11:{
				BOOK x;
				B11(l,x);
				break;
			}
			case 12:{
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
