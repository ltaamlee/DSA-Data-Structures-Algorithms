#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ElementType char

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
	ElementType t=st.a[st.top];
	st.top--;
	return t;
}

void Input(string& s){
	cout<<"Nhap chuoi : ";
	getline(cin,s);
}

bool Bracket_Matching(string s, STACK st){
	bool check=true;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            Push(st,s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (IsEmptyStack(st)) {
                check=false;
            } else {
                if ((s[i] == ')' && Top(st) == '(') || 
                    (s[i] == ']' && Top(st) == '[') || 
                    (s[i] == '}' && Top(st) == '{')) {
                    Pop(st);
                } else {
                    check=false;
                }
            }
        }
    }
    return check && IsEmptyStack(st);
}

int main(){
	STACK st;
	InitStack(st);
	string s;
	Input(s);
	if (Bracket_Matching(s,st)) cout<<"Day ngoac hop le !";
	else cout<<"Day ngoac khong hop le !";
	return 0;
}
