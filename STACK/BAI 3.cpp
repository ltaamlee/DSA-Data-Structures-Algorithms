#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ElementType int

struct STACK{
	ElementType a[MAX];
	int top;
};

void InitStack(STACK& st){
	st.top=-1;
}

int IsEmptyStack(STACK& st){
	if (st.top==-1)
		return 1;
	return 0;
}

int IsFullStack(STACK& st){
	if (st.top==MAX-1)
		return 1;
	return 0;
}

void Push(STACK& st, ElementType x){
	if (IsFullStack(st))
		cout<<"Ngan xep day !\n";
	else{
		st.a[st.top+1]=x;
		st.top++;
	}
}

ElementType Top(STACK& st){
	return st.a[st.top];
}

ElementType Pop(STACK& st){
	int t=st.a[st.top];
	st.top--;
	return t;
}

void DEC_TO_BIN(int n){
	STACK st;
	InitStack(st);
	int temp=n;
	while (temp!=0){
		int r=temp%2;
		temp/=2;
		Push(st,r);
	}
	cout<<n<<"(10) = ";
	while (!(IsEmptyStack(st))){
		cout<<Top(st);
		Pop(st);
	}
	cout<<" (2) \n";
}

void BIN_TO_DEC(string b){
	STACK st;
	InitStack(st);
	for (int i=0; i<b.size(); ++i){
		Push(st,int(b[i])-48);
	}
	int res=0, power=0;
	int t=0;
	while (!(IsEmptyStack(st))){
		t=Top(st);
		res+=t*(1<<power);
		Pop(st);
		power++;
	}
	cout<<b<<" (2) = "<<res<<" (10) \n";
}

void DEC_TO_HEX(int n){
	STACK st;
	InitStack(st);
	int temp=n;
	while (temp!=0){
		int r=temp%16;
		temp/=16;
		Push(st,r);
	}
	cout<<n<<" (10) = ";
	while (!(IsEmptyStack(st))){
		string hexa="0123456789ABCDEF";
		for (int i=0; i<hexa.size(); ++i){
			if (Top(st)==i)
				cout<<hexa[i];	
		}
		Pop(st);
	}
	cout<<" (16)";
}

void HEX_TO_DEC(string h){
	STACK st;
	InitStack(st);
	for (int i=0; i<h.size(); ++i){
		if ('0'<=h[i] && h[i]<='9')
			Push(st,int(h[i])-48);
		else
			Push(st,int(h[i]-55));
	}
	int res=0, power=0;
	cout<<h<<" (16) = ";
	while (!(IsEmptyStack(st))){
		int t=Top(st);
		res+=t*(pow(16,power));
		power++;
		Pop(st);
	}
	cout<<res<<" (10) \n";
}

int main(){
	int key;
	do{
		cout<<"\t-------------CHUONG TRINH CHUYEN DOI CO SO--------------\n";
		cout<<"\t\t1. Decimal to Binary \n";
		cout<<"\t\t2. Binary to Decimal \n";
		cout<<"\t\t3. Decimal to Hexadecimal \n";
		cout<<"\t\t4. Hexadecimal to Decimal \n";
		cout<<"\t\t0. Ket thuc chuong trinh \n";
		cout<<"\t--------------------------------------------------------\n";

		cout<<"Nhap lua chon cua ban : ";
		cin>>key;
		switch (key){
			case 1:{
				int n;
				cout<<"Nhap so dang thap phan (Decimal) : ";
				cin>>n;
				DEC_TO_BIN(n);
				break;
			}
			case 2:{
				string b;
				cout<<"Nhap so dang nhi phan (Binary) : ";
				cin.ignore();
				getline(cin,b);
				BIN_TO_DEC(b);
				break;
			}		
			case 3:{
				int n;
				cout<<"Nhap so dang thap phan (Decimal) : ";
				cin>>n;
				DEC_TO_HEX(n);
				break;
			}
			case 4:{
				string h;
				cout<<"Nhap so dang thap luc phan (Hexadecimal) : ";
				cin.ignore();
				getline(cin,h);
				HEX_TO_DEC(h);
				break;
			}
			case 0:{
				cout<<"Ket thuc chuong trinh !";
				break;
			}		
			default:{
				cout<<"Lua chon khong ton tai !";
				break;
			}
		}	
	}while (key!=0);
	return 0;
}
