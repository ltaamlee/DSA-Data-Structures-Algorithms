#include <bits/stdc++.h>
#define nmax 100
#define ElementType int
using namespace std;

struct Book{
	string name;
	string author;
	int year;
};

void Input(int &n, int a[]){
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a[i];
	}
}

void Input(int &n, float a[]){
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a[i];
	}
}

void Input(int &n, string a[]){
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	cin.ignore();
	for (int i=0; i<n; ++i){
		getline(cin,a[i]);
	}
}

void Input(int &n, Book a[]){
	cout<<"Nhap so luong quyen sach: ";
	cin>>n;
	for (int i=0; i<n; ++i){
		cout<<i+1<<".\n";
		cout<<"Ten quyen sach: ";
		cin.ignore();
		getline(cin,a[i].name);
		cout<<"Ten tac gia: ";
		getline(cin,a[i].author);
		cout<<"Nam xuat ban: ";
		cin>>a[i].year;
	}
}

void Output(int n, int a[]){
	for (int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void Output(int n, float a[]){
	for (int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void Output(int n, string a[]){
	for (int i=0; i<n; ++i){
		cout<<a[i]<<"\n";
	}
}

void Output(int n, Book a[]){
	cout<<"\t"<<setw(25)<<left<<"Ten quyen sach";
	cout<<setw(25)<<left<<"Ten tac gia";
	cout<<setw(20)<<right<<"Nam xuat ban";
	cout<<"\n\n";
	for (int i=0; i<n; ++i){
		cout<<"\t"<<setw(25)<<left<<a[i].name;
		cout<<setw(25)<<left<<a[i].author;
		cout<<setw(20)<<right<<a[i].year<<"\n";
	}
}

bool compare(int a, int b){
	return a>b;
}

bool compare(float a, float b){
	return a>b;
}

bool compare(string a, string b){
	return a.size()>b.size();
}

bool compare(Book a, Book b){
	return a.year<b.year;
}

void swap(string &a, string &b){
	string temp=a;
	a=b;
	b=temp;
}

void swap(Book &a, Book &b){
	Book temp=a;
	a=b;
	b=temp;
}

void SELECTION_SORT(int n, ElementType a[]) {
    int Min, i, j;
    for (i=0; i<n-1; ++i) {
        Min=i;
        for (j=i+1; j<n; ++j) {
            if (compare(a[Min],a[j])) {
                Min=j;
            }
        }
        swap(a[Min],a[i]);
    }
}

void INSERTION_SORT(int n, ElementType a[]) {
    int pos, i;
    ElementType x;
    for (i=1; i<n; ++i) {
        x=a[i];
        pos=i-1;
        while ((pos>=0) && (compare(a[pos],x))){
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
    }
}

void BUBBLE_SORT(int n, ElementType a[]) {
    for (int i=0; i<n-1; i++)
        for (int j=n-1; j>i; j--) {
            if (compare(a[j-1],a[j])) {
                swap(a[j],a[j-1]);
            }
        }
}

void SHAKER_SORT(int n, ElementType a[]) {
    int i, j, l, r, k;
    l=0;
    r=n-1;
    while (l<r) {
        for (j=r; j>l; --j) {
            if (compare(a[j-1],a[j])) {
                swap(a[j],a[j-1]);
                k=j;
            }
        }
        l=k;
        for (i=l; i<r; ++i) {
            if (compare(a[i],a[i+1])) {
                swap(a[i],a[i+1]);
                k=i;
            }
        }
        r=k;
    }
}

void QUICK_SORT_1(ElementType a[], int left, int right) {
    int i=left, j=right;
    ElementType x=a[(i+j)/2];
    while (i<=j) {
        while (compare(a[i],x)) i++;
        while (compare(x,a[j])) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (left<j) QUICK_SORT_1(a,left,j);
    if (i<right) QUICK_SORT_1(a,i,right);
}

void BININ_SORT(int n, ElementType a[]) {
    int l, r, pos;
    ElementType x;
    for (int i=1; i<n; ++i) {
        x=a[i];
        l=0;
        r=i-1;
        while (l<=r) {
            pos=(l+r)/2;
            if (compare(a[pos],x))
                r=pos-1;
            else
                l=pos+1;
        }
        for (int j=i-1; j>=l; --j) {
            a[j+1] = a[j];
        }
        a[l]=x;
    }
}

void QUICK_SORT_2(ElementType a[], int left, int right) {
    int i=left, j=right;
    ElementType x=a[i];
    while (i<=j) {
        while (compare(a[i],x)) i++;
        while (compare(x,a[j])) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (left<j) QUICK_SORT_2(a,left,j);
    if (i<right) QUICK_SORT_2(a,i,right);
}
int main(){
	ElementType a[nmax];
	int n;
	Input(n,a);
	cout<<"\n";
    cout<<"\t\t\tChon giai thuat sap xep : \n";
    cout<<"1. Selection Sort \n";
    cout<<"2. Insertion Sort \n";
    cout<<"3. Bubble Sort \n";
	cout<<"4. Shaker Sort \n";
    cout<<"5. Quick Sort 1 (phan tu linh canh nam giua) \n";
    cout<<"6. Binary Insertion Sort \n";
    cout<<"7. Quick Sort 2 (phan tu linh canh nam dau) \n";
    cout<<"0. Thoat chuong trinh !\n";
    cout<<"\n";
    cout<<"Ban chon giai thuat so (1-7): ";
    int key; 
	cin>>key;
    switch (key) {
        case 1:{
        	Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
            SELECTION_SORT(n,a);
            Output(n,a);
            cout<<"\n";
			break;
		}
        case 2:{
        	Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
            INSERTION_SORT(n,a);
            Output(n,a);
            cout<<"\n";
			break;
		}
        case 3:{
        	Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
            BUBBLE_SORT(n,a);
            Output(n,a);
            cout<<"\n";
			break;
		}
        case 4:{
        	Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
            SHAKER_SORT(n,a);
            Output(n,a);
            cout<<"\n";
			break;
		}
		case 5:{
			Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
            QUICK_SORT_1(a,0,n-1);
            Output(n,a);
            cout<<"\n";
			break;
		}	
        case 6:{
        	Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
        	BININ_SORT(n,a);
            Output(n,a);
            cout<<"\n";
			break;
		}
        case 7:{
        	Output(n,a);
        	cout<<"Mang sau khi duoc sap xep: ";
            QUICK_SORT_2(a,0,n-1);
            Output(n,a);
            cout<<"\n";
			break;
		}
        case 0:{
        	cout<<"Ket thuc chuong trinh voi cac giai thuat sap xep ! \n";
			break;
		}
        default:{
        	cout<<"Lua chon khong ton tai trong menu ! \n";
			break;
		}
    }
	return 0;
}
