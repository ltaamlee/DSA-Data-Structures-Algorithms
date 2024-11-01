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

void InsertNode(Tnode &R, int x){
    Tnode p=CreateNode(x);
    if (R==NULL) {
        R=p;
        return;
    }
    Tnode curr=R;
    Tnode parent=NULL;

    while (curr!=NULL){
        parent=curr;
        if (x<curr->data){
            curr=curr->Left;
        }
        else{
            curr=curr->Right;
        }
    }

    if (x<parent->data){
        parent->Left=p;
    }
    else{
        parent->Right=p;
    }
}

void DeleteNode(Tnode R, int x){
	if(R==NULL){
            return;
        }
    while(true){
        if(R->data==x){
            if(R->Left==NULL && R->Right==NULL){
                delete R;
                break;
            }
            else if(R->Left==NULL){
                Tnode p=R;
                R=R->Right;
                delete p;
                break;
            }
            else if(R->Right==NULL){
                Tnode p=R;
                R=R->Left;
                delete p;
                break;
            }
            else{
                Tnode p=R->Right;
                while(p->Left!=NULL){
                    p=p->Left;
                }
                R->data=p->data;
                DeleteNode(R->Right,p->data);
                break;
            }
        }
        else if(R->data<x){
            R=R->Right;
        }
        else{
            R=R->Left;
        }
    }
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

int HighTree(Tnode R){
    if (!R) return 0;
    int hl=HighTree(R->Left);
    int hr=HighTree(R->Right);
    return (1 + max(hl, hr));
}

int CountNodeMedium(Tnode R){
	if (!R) return 0;
	int nlm=CountNodeMedium(R->Left);
	int nrm=CountNodeMedium(R->Right);
	if (R->Left || R->Right)
		return (1+nlm+nrm);
	return (nlm+nrm);
}

int CountNodeLeaf(Tnode R){
	if (!R) return 0;
	if (!R->Left && !R->Right) return 1;
	int nll=CountNodeLeaf(R->Left);
	int nrl=CountNodeLeaf(R->Right);
	return (nll+nrl);
}

int CountNodeEven(Tnode R){
	if (!R) return 0;
	int nle=CountNodeEven(R->Left);
	int nre=CountNodeEven(R->Right);
	if (R->data%2==0)
		return (1+nle+nre);
	return (nle+nre);
}

long SumNode(Tnode R){
	if (!R) return 0;
	int suml=SumNode(R->Left);
	int sumr=SumNode(R->Right);
	return (R->data+suml+sumr);
}

void NodeMin(Tnode R){
	Tnode p=R;
	while(p->Left!=NULL){
		p=p->Left;
	}
	cout<<p->data<<"\n";
}

void NodeMax(Tnode R){
	Tnode p=R;
	while(p->Right!=NULL){
		p=p->Right;
	}
	cout<<p->data<<"\n";
}

void FindMaxNeg(Tnode R){
	if (R->data<0){
		cout<<R->data<<"\n";
		return;
	}
	else{
		cout<<"Khong co !\n";
		return;
	}
	FindMaxNeg(R->Left);
}

int main(){
  Tnode T;
	InitTree(T);
	int n;
	map<int, int> mp;
	cout<<"Nhap so phan tu cua cay : "; cin>>n;
	cout<<"Nhap cac gia tri cac nut tren cay: ";
	for (int i=0; i<n; ++i){
		int x; cin>>x;
		mp[x]++;
		InsertNode(T,x);	
	}
    cout<<"PreOrder : ";
    PrintTree_PreOrder(T);
    cout<<"\n\n";
    int key=0;
    do{
    	cout<<"\t--------------------------------MENU--------------------------------\n";
    	cout<<"\t--------------------------------------------------------------------\n";
    	cout<<"\t\t1. Dem so node nhanh cua cay \n";
    	cout<<"\t\t2. Dem so node la cua cay \n";
    	cout<<"\t\t3. Dem phan tu chan tren cay \n";
    	cout<<"\t\t4. Tinh tong gia tri cac nut tren cay \n";
    	cout<<"\t\t5. Tim gia tri nguyen nho nhat va lon nhat \n";
    	cout<<"\t\t6. Tim phan tu max am tren cay \n";
    	cout<<"\t\t7. Dem gia tri phan biet cua day cho truoc \n";
    	cout<<"\t\t8. Voi moi gia tri phan biet, cho biet so luong phan tu \n";
    	cout<<"\t\t0. Ket thuc chuong trinh \n";
    	cout<<"\t------------------------------------------------------------------\n\n";
    	cout<<"Nhap lua chon cua ban : ";
    	cin>>key;
    	switch (key){
    		case 1:{
    			cout<<"So node nhanh cua cay: "<<CountNodeMedium(T)<<"\n";
				break;
			}
			case 2:{
				cout<<"So node la cua cay: "<<CountNodeLeaf(T)<<"\n";
				break;
			}
			case 3:{
				cout<<"So phan tu chan tren cay: "<<CountNodeEven(T)<<"\n";
				break;
			}
			case 4:{
				cout<<"Tong gia tri cac nut tren cay: "<<SumNode(T)<<"\n";
				break;
			}
			case 5:{
				cout<<"Gia tri nguyen nho nhat tren cay: "; NodeMin(T);
				cout<<"Gia tri nguyen lon nhat tren cay: "; NodeMax(T);
				break;
			}
			case 6:{
				cout<<"Phan tu am lon nhat tren cay: "; FindMaxNeg(T);
				break;
			}
			case 7:{
				cout<<"So luong phan tu phan biet cua day cho truoc: "<<mp.size()<<"\n\n";
				break;
			}
			case 8:{
				for (pair<int, int> it:mp){
					cout<<<<"\t\t"<<it.first<<" xuat hien "<<it.second<<" lan \n";
				}
				break;
			}
			case 0:{
				cout<<"Ket thuc chuong trinh ! \n";
				break;
			}
			default:{
				cout<<"Lua chon khong ton tai ! \n";
				break;
			}
		}
	}while (key!=0);
  return 0;
}
