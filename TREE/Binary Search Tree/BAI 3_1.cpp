#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int count;
    struct Node* Left;
    struct Node* Right;
};

typedef Node* Tnode;

void InitTree(Tnode &R){
    R=NULL;
}

Tnode CreateNode(char x){
    Tnode p=new Node;
    if (!p) return NULL;
    p->data=x;
    p->count=1;
    p->Left=NULL;
    p->Right=NULL;
    return p;
}

Tnode Search(Tnode R, char x){
	Tnode p=R;
	while(p){
		if (p->data==x) return p;
		else if (p->data>x) p=p->Left;
		else p=p->Right;
	}
	return NULL;
}

void InsertNode(Tnode &R, char x){
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

void Print_Freq(Tnode R){
	if (R==NULL) return;
	Print_Freq(R->Left);
	cout<<"Ki tu '"<<R->data<<"' xuat hien "<<R->count<<" lan \n";
	Print_Freq(R->Right);
}

int main(){
	Tnode T;
	InitTree(T);
	string s;
	cout<<"Nhap vao van ban khong dau : ";
	getline(cin,s);
	for (char x:s){
		InsertNode(T,tolower(x));
	}
	Print_Freq(T);
	char c;
	cout<<"Nhap vao ki tu can tim : ";
	cin>>c;
	Tnode ans=Search(T,c);
	if (ans!=NULL)
		cout<<"Ki tu '"<<c<<"' xuat hien "<<ans->count<<" lan \n";
	else
		cout<<"Ki tu '"<<c<<"' khong co trong van ban \n";
	return 0;
}
