#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* Left;
    struct Node* Right;
};

typedef Node* Tnode;

void InitTree(Tnode &R){
    R=NULL;
}

Tnode CreateNode(int x){
    Tnode p=new Node;
    if (!p) return NULL;
    p->data=x;
    p->Left=NULL;
    p->Right=NULL;
    return p;
}

Tnode Search(Tnode R, int x){
	Tnode p=R;
	while(p){
		if (p->data==x) return p;
		else if (p->data>x) p=p->Left;
		else p=p->Right;
	}
	return NULL;
}

int InsertNode(Tnode &R, int x){
    if (R) {
        if (R->data==x) return 0;
        if (R->data>x) return InsertNode(R->Left,x);
        else return InsertNode(R->Right,x);
    }
    R=new Node;
    if (R==NULL) return -1;
    R->data=x;
    R->Left=R->Right=NULL;
    return 1;
}

int DeleteNode(Tnode &R, int x){
	Tnode T=R;
	if (!T) return 0;
	if (T->data>x) return DeleteNode(T->Left,x);
	if (T->data<x) return DeleteNode(T->Right,x);
	Tnode p,f,rp;
	p=T;
	if (!T->Left) T=T->Right;
	else if (!T->Right) T=T->Left;
	else{
		f=p;
		rp=p->Right;
		while (rp->Left!=NULL){
			f=rp;
			rp=rp->Left;
		}
		p->data=rp->data;
		if (f==p)
			f->Right=rp->Right;
		else
			f->Left=rp->Right;
		p=rp;
	}
	delete rp;
	return 1;
}

void DeleteTree(Tnode &R){
    if (!R) return;
    DeleteTree(R->Left);
    DeleteTree(R->Right);
    delete R;
    R=NULL;
}

void PrintTree_PreOrder(Tnode R){
    if (R != NULL){
        cout<<R->data<<" ";
        PrintTree_PreOrder(R->Left);
        PrintTree_PreOrder(R->Right);
    }
}

void PrintTree_InOrder(Tnode R){
    if (R!=NULL){
        PrintTree_InOrder(R->Left);
        cout<<R->data<<" ";
        PrintTree_InOrder(R->Right);
    }
}

void PrintTree_PostOrder(Tnode R){
    if (R!=NULL){
        PrintTree_PostOrder(R->Left);
        PrintTree_PostOrder(R->Right);
        cout <<R->data<<" ";
    }
}

int main(){
  Tnode T;
	InitTree(T);
	int n;
	cout<<"Nhap so phan tu cua cay : "; cin>>n;
	for (int i=0; i<n; ++i){
		int x; cin>>x;
		InsertNode(T,x);
	}
  cout<<"PreOrder : ";
  PrintTree_PreOrder(T);
  cout<<"\n\n";
  cout<<"Chieu cao cua cay : "<<HighTree(T)<<"\n";
  return 0;
}
