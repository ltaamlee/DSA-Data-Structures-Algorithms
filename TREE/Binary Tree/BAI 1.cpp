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

int AddNodeLeft(Tnode &R, int x){
    if (R==NULL) return 0;
    if (R->Left!=NULL) return 0;
    Tnode p=CreateNode(x);
    R->Left=p;
    return 1;
}

int AddNodeRight(Tnode &R, int x){
    if (R==NULL) return 0;
    if (R->Right!=NULL) return 0;
    Tnode p=CreateNode(x);
    R->Right=p;
    return 1;
}

int DeleteNodeLeft(Tnode R){
    if (R==NULL) return 0;
    Tnode p=R->Left;
    if (p==NULL) return 0;
    if (p->Left!=NULL || p->Right!=NULL) return 0;
    delete p;
    R->Left=NULL;
    return 1;
}

int DeleteNodeRight(Tnode R){
    if (R==NULL) return 0;
    Tnode p= R->Right;
    if (p==NULL) return 0;
    if (p->Left!=NULL || p->Right!=NULL) return 0;
    delete p;
    R->Right=NULL;
    return 1;
}

Tnode FindNode(Tnode R, int x){
    if (!R) return NULL;
    if (R->data==x) return R;
    Tnode p=FindNode(R->Left,x);
    if (p) return p;
    return FindNode(R->Right,x);
}

void DeleteTree(Tnode &R){
    if (!R) return;
    DeleteTree(R->Left);
    DeleteTree(R->Right);
    delete R;
    R=NULL;
}

int HighTree(Tnode R){
    if (!R) return 0;
    int hl=HighTree(R->Left);
    int hr=HighTree(R->Right);
    return (1 + max(hl, hr));
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
	T=CreateNode(9);
	AddNodeLeft(T,2);
	AddNodeRight(T,8);
	AddNodeLeft(T->Left,6);
	AddNodeRight(T->Left,1);
	AddNodeLeft(T->Left->Right,10);
	AddNodeLeft(T->Right,5);
	AddNodeRight(T->Right,7);
	AddNodeLeft(T->Right->Left,3);
	AddNodeLeft(T->Right->Right,12);
	AddNodeRight(T->Right->Right,4);
  cout<<"PreOrder : ";
  PrintTree_PreOrder(T);
  cout<<"\n\n";
  cout<<"Chieu cao cua cay : "<<HighTree(T)<<"\n";
  return 0;
}
