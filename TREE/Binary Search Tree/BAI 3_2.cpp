#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    int count;
    struct Node* Left;
    struct Node* Right;
};

typedef Node* Tnode;

void InitTree(Tnode &R){
    R=NULL;
}

Tnode CreateNode(string x){
    Tnode p=new Node;
    if (!p) return NULL;
    p->data=x;
    p->count=1;
    p->Left=NULL;
    p->Right=NULL;
    return p;
}

Tnode Search(Tnode R, string x){
	Tnode p=R;
	while(p){
		if (p->data==x) return p;
		else if (p->data>x) p=p->Left;
		else p=p->Right;
	}
	return NULL;
}

void InsertNode(Tnode &R, string x){
    Tnode p=CreateNode(x);
    if (R==NULL) {
        R=p;
        return;
    }
	if (R->data>x)
		InsertNode(R->Left,x);
    else if (R->data<x) 
		InsertNode(R->Right,x);
    else 
		R->count++;
}

void PrintTree_PreOrder(Tnode R){
    if (R != NULL){
        cout<<R->data<<" ";
        PrintTree_PreOrder(R->Left);
        PrintTree_PreOrder(R->Right);
    }
}

void Print_Freq(Tnode R){
	if (R==NULL) return;
	Print_Freq(R->Left);
	cout<<"Tu '"<<R->data<<"' xuat hien "<<R->count<<" lan \n";
	Print_Freq(R->Right);
}

int main(){
	Tnode T;
	InitTree(T);
	string s;
	cout<<"Nhap vao van ban khong dau : ";
	getline(cin,s);
	stringstream ss(s);
	string temp;
	while(ss>>temp){
		InsertNode(T,temp);
	}
	
	Print_Freq(T);
	string c;
	cout<<"Nhap vao tu can tim : ";
	cin>>c;
	Tnode ans=Search(T,c);
	if (ans!=NULL)
		cout<<"Tu '"<<c<<"' xuat hien "<<ans->count<<" lan \n";
	else
		cout<<"Tu '"<<c<<"' khong co trong van ban \n";
	return 0;
}
