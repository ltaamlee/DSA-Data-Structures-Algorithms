#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct STACK_C{
	char a[MAX];
	int top;
};

void InitStack(STACK_C& st){
	st.top=-1;
}

int IsEmptyStack(STACK_C& st){
	if (st.top==-1)
		return 1;
	return 0;
}

int IsFullStack(STACK_C& st){
	if (st.top==MAX-1)
		return 1;
	return 0;
}

void Push(STACK_C& st, char x){
	if (IsFullStack(st))
		cout<<"Ngan xep day !\n";
	else{
		st.a[st.top+1]=x;
		st.top++;
	}
}

char Top(STACK_C& st){
	return st.a[st.top];
}

char Pop(STACK_C& st){
	char t=st.a[st.top];
	st.top--;
	return t;
}

struct STACK{
	int a[MAX];
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

void Push(STACK& st, int x){
	if (IsFullStack(st))
		cout<<"Ngan xep day !\n";
	else{
		st.a[st.top+1]=x;
		st.top++;
	}
}

int Top(STACK& st){
	return st.a[st.top];
}

int Pop(STACK& st){
	int t=st.a[st.top];
	st.top--;
	return t;
}

void Input(string& s){
	cout<<"Nhap bieu thuc dang INFIX : ";
	getline(cin,s);
}

int Priority(char o){
	if (o == '+' || o == '-') return 1;
	if (o == '*' || o == '/') return 2;
	return 0;
}

bool isOperator(char o){
	return (o == '+' || o == '-' || o == '*' || o == '/');
}

string POSTFIX(string s){
	STACK_C st;
	InitStack(st);
	string postfix;
	for (int i=0; i<s.size(); ++i){
		if (isdigit(s[i])){
			postfix+=s[i];
		}
		else if (s[i] == '('){
			Push(st,s[i]);
		}	
		else if (s[i] == ')'){
			while (!IsEmptyStack(st) && Top(st) != '('){
				postfix+=Top(st);
				Pop(st);
			}
			Pop(st);
		}
		else if (isOperator(s[i])){
			while (!IsEmptyStack(st) && (Priority(Top(st)) >= Priority(s[i]))){
				postfix+=Top(st);
				Pop(st);
			}
			Push(st,s[i]);
		}
	}
	
	while (!IsEmptyStack(st)){
		postfix+=Top(st);
		Pop(st);
	}
	return postfix;
}

void RPN(string s){
	STACK st;
	InitStack(st);
	for (int i=0; i<s.size(); ++i){
		if (isdigit(s[i])){
			Push(st,s[i]-'0');
		}
		else if (isOperator(s[i])){
			int x=Top(st); Pop(st);
			int y=Top(st); Pop(st);
			switch (s[i]){
				case '+':{
					Push(st,y+x);
					break;
				}
				case '-':{
					Push(st,y+x);
					break;
				}
				case '*':{
					Push(st,y*x);
					break;
				}
				case '/':{
					Push(st,y/x);
					break;
				}
				case '^':{
					Push(st,pow(y,x));
					break;
				}
			}
		}
	}
	cout<<"Gia tri cua bieu thuc : "<<Top(st);
}

int main(){
	string s;
	Input(s);
	cout<<"Bieu thuc dang POSTFIX : "<<POSTFIX(s)<<"\n";
	RPN(POSTFIX(s));
	return 0;
}
