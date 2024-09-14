#include <bits/stdc++.h>
#define nmax 100
#define ElementType SINHVIEN
using namespace std;

typedef struct {
    int mssv;
    char hoten[50]; 
    float dtb;
} SINHVIEN;

char c;

int SOSANH(SINHVIEN a, SINHVIEN b) {
    if (c=='M') {
        return a.mssv<b.mssv;
    } else if (c=='D') {
        return a.dtb<b.dtb;
    }
    return -1;
}

void swap(SINHVIEN &a, SINHVIEN &b) {
    SINHVIEN temp=a;
    a=b;
    b=temp;
}

void QUICK_SORT(ElementType a[], int left, int right) {
    int i=left, j=right;
    SINHVIEN x=a[(i+j)/2];
    while (i<=j) {
        while (SOSANH(a[i],x)) i++;
        while (SOSANH(x,a[j])) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (left<j) QUICK_SORT(a,left,j);
    if (i<right) QUICK_SORT(a,i,right);
}

void SELECTION_SORT(ElementType a[], int n) {
    int Min, i, j;
    for (i=0; i<n-1; ++i) {
        Min=i;
        for (j=i+1; j<n; ++j) {
            if (SOSANH(a[j],a[Min])) {
                Min=j;
            }
        }
        swap(a[Min],a[i]);
    }
}

void INSERTION_SORT(ElementType a[], int n) {
    int pos, i;
    SINHVIEN x;
    for (i=1; i<n; ++i) {
        x=a[i];
        pos=i-1;
        while ((pos>=0) && (SOSANH(a[pos],x))) {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
    }
}

void BUBBLE_SORT(ElementType a[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=n-1; j>i; j--) {
            if (SOSANH(a[j-1],a[j])) {
                swap(a[j],a[j-1]);
            }
        }
}

void BININ_SORT(ElementType a[], int n) {
    int l, r, pos;
    SINHVIEN x;
    for (int i=1; i<n; ++i) {
        x=a[i];
        l=0;
        r=i-1;
        while (l<=r) {
            pos=(l+r)/2;
            if (SOSANH(a[pos],x))
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

void SHAKE_SORT(ElementType a[], int n) {
    int i, j, l, r, k;
    l=0;
    r=n-1;
    while (l<r) {
        for (j=r; j>l; --j) {
            if (SOSANH(a[j-1],a[j])) {
                swap(a[j],a[j-1]);
                k=j;
            }
        }
        l=k;
        for (i=l; i<r; ++i) {
            if (SOSANH(a[i],a[i+1])) {
                swap(a[i],a[i+1]);
                k=i;
            }
        }
        r=k;
    }
}

void INPUT(ElementType a[], int&n){
	cout<<"Nhap so sinh vien: ";
    cin>>n;
    for (int i=0; i<n; ++i) {
        cout<<"Sinh vien thu "<<i+1<<" : \n";
        cout<<"MSSV: "; cin>>a[i].mssv;
        cin.ignore();
        cout<<"Ho ten: "; cin.getline(a[i].hoten, 50);
        cout<<"DTB: "; cin>>a[i].dtb;
    }
}

void OUTPUT(ElementType a[], int n) {
    for (int i=0; i<n; ++i) {
        cout<<"Sinh vien thu "<<i+1<<" : \n";
        cout<<"MSSV : "<<a[i].mssv<<" Ho ten: "<<a[i].hoten<<" DTB: "<<a[i].dtb<<"\n";
    }
}

int main() {
    int n;
    SINHVIEN a[nmax]; 
    
    INPUT(a,n);
    cin.ignore();
    cout<<"Chon phuong thuc sap xep theo MSSV(M) hoac DTB(D): "; cin>>c;
    cout<<"Chon giai thuat sap xep : \n";
    cout<<"1. Selection Sort \n";
    cout<<"2. Insertion Sort \n";
    cout<<"3. Bubble Sort \n";
    cout<<"4. Quick Sort \n";
    cout<<"5. Binary Insertion Sort \n";
    cout<<"6. Shake Sort \n";
    cout<<"Giai thuat so : ";
    int pt; cin>>pt;
    switch (pt) {
        case 1:
            SELECTION_SORT(a,n);
            break;
        case 2:
            INSERTION_SORT(a,n);
            break;
        case 3:
            BUBBLE_SORT(a,n);
            break;
        case 4:
            QUICK_SORT(a,0,n-1); 
            break;
        case 5:
            BININ_SORT(a,n);
            break;
        case 6:
            SHAKE_SORT(a,n);
            break;
        default:
            cout<<"Lua chon sai! \n";
            break;
    }

    OUTPUT(a,n);
    return 0;
}
