/*VERSION 1*/
#include <bits/stdc++.h>
#define nmax 100
#define ElementType1 int
#define ElementType2 SV
using namespace std;

struct LIST{
	ElementType1 a[nmax];
	int n;
};

struct SV{
	string hoten;
	string mssv;
	float dtb;
};
struct LIST_SV{
	ElementType2 a[nmax];
	int n;
};

void INIT1(LIST &l){
	l.n=0;
}
void INIT2(LIST_SV &l){
	l.n=0;
}

int isEmpty1(LIST l){
	if (l.n==0)
		return 1;
	return 0;
}
int isEmpty2(LIST_SV l){
	if (l.n==0)
		return 1;
	return 0;
}

int isFull1(LIST l){
	if (l.n==nmax)
		return 1;
	return 0;
}
int isFull2(LIST_SV l){
	if (l.n==nmax)
		return 1;
	return 0;
}

void PRINT1(LIST l){
	for (int i=0; i<l.n; ++i){
		cout<<l.a[i]<<" ";
	}
	cout<<"\n";
}
void PRINT2(LIST_SV l){
	cout<<"\t------------------DANH SACH SINH VIEN------------------\n";
	cout<<"\t"<<setw(25)<<left<<"Ho ten";
	cout<<setw(10)<<left<<"MSSV";
	cout<<setw(20)<<right<<"Diem trung binh";
	cout<<"\n";
	for (int i=0; i<l.n; ++i){
		cout<<"\t"<<setw(25)<<left<<l.a[i].hoten;
		cout<<setw(10)<<left<<l.a[i].mssv;
		cout<<setw(20)<<right<<l.a[i].dtb<<"\n";
	}
	cout<<"\n";
} 

void ADD_FIRST1(LIST &l, ElementType1 x){
	if (isFull1(l)){
		cout<<"Danh sach day !";
	}
	else{
		l.n++;
		for (int i=l.n; i>0; --i)
			l.a[i]=l.a[i-1];
		l.a[0]=x;
	}
}
void ADD_FIRST2(LIST_SV &l, ElementType2 y){
	if (isFull2(l)){
		cout<<"Danh sach day !";
	}
	else{
		l.n++;
		for (int i=l.n; i>0; --i)
			l.a[i]=l.a[i-1];
		l.a[0]=y;
	}
}

void ADD_LAST1(LIST &l, ElementType1 x){
	if (isFull1(l)){
		cout<<"Danh sach day !";
	}
	else{
		l.n++;
		l.a[l.n-1]=x;
	}
}
void ADD_LAST2(LIST_SV &l, ElementType2 y){
	if (isFull2(l)){
		cout<<"Danh sach day !";
	}
	else{
		l.n++;
		l.a[l.n-1]=y;
	}
}

void REMOVE_FIRST1(LIST &l){
	if (isEmpty1(l)){
		cout<<"Danh sach rong !";
	}
	else{
		for (int i=0; i<l.n-1; ++i)
			l.a[i]=l.a[i+1];
		l.n--;
	}
}
void REMOVE_FIRST2(LIST_SV &l){
	if (isEmpty2(l)){
		cout<<"Danh sach rong !";
	}
	else{
		for (int i=0; i<l.n-1; ++i)
			l.a[i]=l.a[i+1];
		l.n--;
	}
}

void REMOVE_LAST1(LIST &l){
	if (isEmpty1(l)){
		cout<<"Danh sach rong !";
	}
	else{
		l.n--;
	}
} 
void REMOVE_LAST2(LIST_SV &l){
	if (isEmpty2(l)){
		cout<<"Danh sach rong !";
	}
	else{
		l.n--;
	}
}

void REMOVE_K1(LIST &l, int k){
	if (isEmpty1(l)){
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
void REMOVE_K2(LIST_SV &l, int k){
	if (isEmpty2(l)){
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

ElementType1 LINEAR_SEARCH1(LIST l, ElementType1 x){
	for (int i=0; i<l.n; ++i){
		if (l.a[i]==x){
			return i;
		}
	}
	return -1;
}
ElementType2 LINEAR_SEARCH2(LIST_SV l, float x){
	for (int i=0; i<l.n; ++i){
		if (l.a[i].dtb==x){
			return l.a[i];
		}
	}
}

ElementType1 BINARY_SEARCH1(LIST l, int left, int right, ElementType1 x){
	int mid=0;
	do{
		mid=(left+right)/2;
		if (x==l.a[mid])
			return mid;
		else
		if (x<l.a[mid])
			right=mid-1;
		else
			left=mid+1;
	}
	while(left<=right);
	return -1;	
}
ElementType2 BINARY_SEARCH2(LIST_SV l, int left, int right, float x){
	int mid=0;
	do{
		mid=(left+right)/2;
		if (x==l.a[mid].dtb)
			return l.a[mid];
		else
		if (x<l.a[mid].dtb)
			right=mid-1;
		else
			left=mid+1;
	}
	while(left<=right);	
}

void SORT1(LIST &l){
	for (int i=0; i<l.n-1; ++i){
		for (int j=l.n-1; j>i; j--) {
            if (l.a[j-1]>l.a[j]) {
                swap(l.a[j],l.a[j-1]);
            }
        }
	}
}
void Swap(SV &a, SV &b) {
    SV temp=a;
    a=b;
    b=temp;
}
void SORT2(LIST_SV &l){
	for (int i=0; i<l.n-1; ++i){
		for (int j=l.n-1; j>i; j--) {
            if (l.a[j-1].dtb>l.a[j].dtb) {
                Swap(l.a[j],l.a[j-1]);
            }
        }
	}
}

void N1(LIST l, ElementType1 &X){
	cout<<"Nhap X = "; cin>>X;
	int cnt=0;
	SORT1(l);
	cout<<"Danh sach cac phan tu >= X : ";
	ElementType1 k=BINARY_SEARCH1(l,0,l.n-1,X);
	if (k==-1){
		cout<<"Khong co !";
	}
	else{
		for (int i=k; i<l.n; ++i){
			cout<<l.a[i]<<" ";
		}
	}
	cout<<"\n";
}
void N2(LIST &l, ElementType1 &X){
	cout<<"Nhap X = "; cin>>X;
	int i=0;
    while (i<l.n) {
        if (l.a[i]>=X) {
            REMOVE_K1(l,i);
        } else {
            i++;
        }
    }
    cout<<"Danh sach sau khi xoa cac phan tu >= X : ";
    PRINT1(l);
}
void N4(LIST l){
	int cnt=0;
	for (int i=0; i<l.n; ++i){
		if (l.a[i]<0) cnt++;
	}
	cout<<"Co "<<cnt<<" so am trong mang \n";
}
void N5(LIST l){
	ElementType1 max_x=-1e5;
	for (int i=0; i<l.n; ++i){
		if (l.a[i]<0 && l.a[i]>max_x){
			max_x=l.a[i];
		}
	}
	if (max_x!=-1e5)
	cout<<"So nguyen am lon nhat trong mang : "<<max_x;
	else cout<<"Mang khong co so am !";
	cout<<"\n";
}
void N6(LIST l){
	ElementType1 min_x=1e5;
	for (int i=1; i<l.n; ++i){
		if (l.a[i]>0 && l.a[i]<min_x){
			min_x=l.a[i];
		}
	}
	if (min_x!=1e5)
		cout<<"So nguyen duong nho nhat trong mang : "<<min_x;
	else cout<<"Mang khong co so duong !";
	cout<<"\n";
}
void N7(LIST l, ElementType1 X){
	cout<<"Nhap X = "; cin>>X;
	int cnt=0;
	for (int i=0; i<l.n; ++i){
		if (l.a[i]==X) cnt++;
	}
	if (cnt>0) 
		cout<<"Co "<<cnt<<" phan tu co gia tri bang X ";
	else 
		cout<<"Khong co !";
	cout<<"\n";
}

void S1(LIST_SV &l, ElementType2 &y){
	cin.ignore();
	cout<<"Nhap ten sinh vien : "; getline(cin,y.hoten);
	cout<<"Nhap ma so sinh vien : "; getline(cin,y.mssv);
	cout<<"Nhap diem trung binh : "; cin>>y.dtb;
	int i;
    for (i=l.n-1; i>=0 && l.a[i].dtb>y.dtb; --i) {
        l.a[i+1]=l.a[i];  
    }
    l.a[i+1]=y;
    l.n++;
	PRINT2(l);
}
void S2(LIST_SV l, float X){
	int cnt=0;
	cout<<"Nhap diem X = "; cin>>X;
	cout<<"Danh sach sinh vien co diem trung binh >= X : \n";
	for (int i=0; i<l.n; ++i){
		if (l.a[i].dtb>=X)
			cnt++;
	}
	if (cnt>0){
		cout<<"\t"<<setw(25)<<left<<"Ho ten";
		cout<<setw(10)<<left<<"MSSV";
		cout<<setw(20)<<right<<"Diem trung binh";
		cout<<"\n";
		for (int i=0; i<l.n; ++i){
			if (l.a[i].dtb>=X){
				cout<<"\t"<<setw(25)<<left<<l.a[i].hoten;
				cout<<setw(10)<<left<<l.a[i].mssv;
				cout<<setw(20)<<right<<l.a[i].dtb<<"\n";
			}
		}
	}
	else cout<<"Khong co !";
}
void S3(LIST_SV &l, float &X){
	cout<<"Nhap X = "; cin>>X;
	int i=0;
    while (i<l.n) {
        if (l.a[i].dtb>=X) {
            REMOVE_K2(l,i);
        } else {
            i++;
        }
    }
    PRINT2(l);
}
void S4(LIST_SV l, int &K){
	cout<<"Nhap K = "; cin>>K;
	if (K==0) 
		cout<<"Khong co !\n";
	else
	if (K>0 && K<=l.n){
		SORT2(l);
		cout<<"\t"<<setw(25)<<left<<"Ho ten";
		cout<<setw(10)<<left<<"MSSV";
		cout<<setw(20)<<right<<"Diem trung binh";
		cout<<"\n";
		int i=l.n-1;
		while (K!=0){
			cout<<"\t"<<setw(25)<<left<<l.a[i].hoten;
			cout<<setw(10)<<left<<l.a[i].mssv;
			cout<<setw(20)<<right<<l.a[i].dtb<<"\n";
			K--;
			i--;
		}
	}
	else
		cout<<"Pham vi vuot qua danh sach !\n";
}
int main(){
	char c;
	LIST l1;
	INIT1(l1);
	LIST_SV l2;
	INIT2(l2);
	do{
		system("cls");
		cout<<"\t---------------------CHUONG TRINH THAO TAC VOI DANH SACH-------------------------\n";
		cout<<"\tBan muon thao tac tren danh sanh kieu so nguyen hay danh sach kieu sinh vien ?\n";
		cout<<"\tChon kieu so nguyen (N), chon kieu sinh vien (S) : ";
		cin>>c;
		cout<<"\n";
		int key;
		ElementType1 x;
		if (c=='N' || c=='n'){
			do{
				cout<<"Nhap cac phan tu cua danh sach (Nhap 0 de dung ): ";
				cin>>x;
				ADD_FIRST1(l1,x);
			} while (x!=0);
			cout<<"Danh sach cac so nguyen vua nhap : "; PRINT1(l1);
			cout<<"\n";
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
				ElementType1 X; 
				switch (key){
					case 1:{
						N1(l1,X);
						break;
					}
					case 2:{
						N2(l1,X);
						break;
					}
					case 3:{
						cout<<"Phan tu lon nhat trong mang : ";
						SORT1(l1);
						if (l1.n>0)
							cout<<l1.a[l1.n-1];
						else cout<<"Khong co !";
						cout<<"\n";
						break;
					}
					case 4:{
						N4(l1);
						break;
					}
					case 5:{
						N5(l1);
						break;
					}
					case 6:{
						N6(l1);
						break;
					}
					case 7:{
						N7(l1,X);
						break;
					}
					case 0:
						cout<<setw(50)<<left<<"Ket thuc chuong trinh thao tac voi kieu so nguyen ! \n";
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
		if (c=='S' || c=='s'){
			ElementType2 a;
			int i=1;
			do{
				cout<<"Nhap thong tin sinh vien thu "<<i<<" : \n";
				cin.ignore();
				cout<<"Nhap ten sinh vien (Nhan Enter de dung): "; getline(cin,a.hoten);
				if ((a.hoten).size()==0) break;
				cout<<"Nhap ma so sinh vien : "; getline(cin,a.mssv);
				cout<<"Nhap diem trung binh : "; cin>>a.dtb;
				ADD_FIRST2(l2,a);
				i++;
			} while (a.hoten!="");
			cout<<"\n";
			PRINT2(l2);
			ElementType2 Y;
			float X;
			int K;
			cout<<"\n\n";
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
				switch (key){
					case 1:{
						S1(l2,Y);
						break;
					}
					case 2:{
						S2(l2,X);
						break;
					}
					case 3:{
						S3(l2,X);
						break;
					}
					case 4:{
						S4(l2,K);
						break;
					}
					case 0:
						cout<<setw(50)<<left<<"Ket thuc chuong trinh thao tac voi kieu sinh vien ! \n";
						cout<<"\t------------------------------------------------------------------------\n";
						break;
					default:
						cout<<"Lua chon khong ton tai trong menu !";
						cout<<"\n";
						break;
				}
			} while (key!=0);
		}
		cout<<"Ban co muon tiep tuc chuong trinh khong ? ";
		cout<<"Co (C), Khong (K) : ";
		cin>>c;
		cout<<"\n";
		if (c=='K' || c=='k') {
			cout<<"                       KET THUC CHUONG TRINH";
			break;
		}
		cout<<"\n";
	}while (c=='C' || c=='c');
	return 0;
}
