#include <bits/stdc++.h>
using namespace std;
#define ElementType int
#define MAX 100

struct QUEUE{
	ElementType a[MAX];
	int front;
	int rear;
};

void InitQueue(QUEUE &q){
	q.front=q.rear=-1;
}

int IsEmptyQueue(QUEUE q){
	if (q.front==-1)
		return 1;
	return 0;
}

ElementType DeQueue(QUEUE &q){
	if (!IsEmptyQueue(q)){
		ElementType x=q.a[q.front];
		q.front++;
		if (q.front>q.rear){
			q.front=q.rear=-1;
		}
		return 1;
	}	
	else{
		cout<<"Queue rong !\n";
		return 0;
	}
}

ElementType Front(QUEUE q){
	return q.a[q.front];
}


void EnQueue(QUEUE &q, ElementType x){
	int i, f, r;
	if (q.rear-q.front+1==MAX){
		cout<<"Queue day ! ";
	}
	else{
		if (IsEmptyQueue(q)){
			q.front=0;
			q.rear=-1;
		}
		if (q.rear==MAX-1){
			f=q.front;
			r=q.rear;
			for (i=f; i<=r; ++i){
				q.a[i-f]=q.a[i];
			}
			q.front=0;
			q.rear=r-f;
		}
		q.rear++;
		q.a[q.rear]=x;
	}
}

void Print(QUEUE q){
	while (!IsEmptyQueue(q)){
		cout<<Front(q)<<" ";
		DeQueue(q);
	}
}

int main(){
    QUEUE q;
	InitQueue(q);
	int key;
	do{
		cout<<"\t----------CHUONG TRINH QUEUE KIEU MANG----------\n";
		cout<<"\t\t1. Them 1 phan tu vao hang doi \n";
		cout<<"\t\t2. Huy 1 phan tu o dau hang doi \n";
		cout<<"\t\t3. Lay thong tin phan tu o dau hang doi \n";
		cout<<"\t\t4. Kiem hang doi rong \n";
		cout<<"\t\t5. In hang doi \n";
		cout<<"\t\t0. Ket thuc chuong trinh !\n";
		cout<<"\t------------------------------------------------\n\n";
		cout<<"Nhap lua chon cua ban : ";
		cin>>key;
		switch (key){
			case 1:{
				cout<<"Nhap phan tu can them : ";
				ElementType n; cin>>n;
				EnQueue(q,n);
				break;
			}
			case 2:{
				if (IsEmptyQueue(q))
					cout<<"Hang doi rong !\n";
				else
					DeQueue(q);
				break;
			}		
			case 3:{
				cout<<"Phan tu o dinh hang doi : "<<Front(q)<<"\n";
				break;
			}
			case 4:{
				if (IsEmptyQueue(q))
					cout<<"Hang doi rong !\n";
				else
					cout<<"Hang doi khong rong !\n";
				break;
			}	
			case 5:{
				cout<<"Queue : ";
				Print(q);
				cout<<"\n";
				break;
			}
			case 0:{
				cout<<"Ket thuc chuong trinh !\n";
				break;
			}		
			default:{
				cout<<"Lua chon khong ton tai !\n";
				break;
			}
		}
	}while (key!=0);
	return 0;
}
