#include <iostream>
#include <stack>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

bool isOperator(char o){
    return (o == '+' || o == '-' || o == '*' || o == '/' || o == '^');
}

bool isValidChar(char c){
	return (isdigit(c) || isOperator(c) || c == '(' || c == ')' || c == ' ' || c == '.');
}

bool Bracket_Matching(string s){
	int in=0, out=0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '(') {
            in++;
        }
		if (s[i] == ')') {
            out++;
   		}
	}
    return (in==out);
}

int Priority(char o){
    if (o == '+' || o == '-') return 1;
    if (o == '*' || o == '/') return 2;
    if (o == '^') return 3;
    return 0;
}

bool isValid(string s){
	if (!Bracket_Matching(s)) return false;
	int num=0; 
	if (s.find("**")!=string::npos || s.find("//")!=string::npos) return false;
	for (int i=0; i<s.size(); ++i){
		if (s[0] == ')') return false;
		
		if (!isValidChar(s[i])) return false;
	
		if (s[i] == '(' && s[i+1] == ')') return false; 
		
		if (isdigit(s[i])){
			num++;
		}
	}
	if (num == 0) return false;
	return true;
}

string Normalize(string &s){
	stringstream ss(s);
	string temp;
	string res;
    while (ss>>temp){
    	if (!res.empty())
    		res+=" ";
    	res+=temp;
	}
	
	int idneg=s.find("---");
	while(s.find("---") != string::npos){
		s.erase(idneg,2);
	}
	if (s.find("--") != string::npos){
	    s.replace(s.find("--"), 2, "+"); 
	}
	
	int idpos=s.find("++");
	while(s.find("++")!=string::npos){
		s.erase(idpos,1);
	}
    return res;
}

void Input(string& s){
    bool check=true;
    do{
    	cout<<"\t\tNhap bieu thuc can tinh toan: ";
   		getline(cin, s);
   		if (!isValid(s)){
			check=false;
			cout<<"\t\tBieu thuc khong hop le !\n";
		}
		else check=true;
	} while (!check);
}

string RPN(string s){
	Normalize(s);
	stack<char> st;
	string postfix;
    
    for (int i=0; i<s.size(); ++i) {

		if (s[i] == '-' && (i == 0 || s[i-1] == '(' || isOperator(s[i-1]))){
			string ss="-";
			i++;
        	while (i<s.size() && isdigit(s[i]) || s[i] == '.') {
            	ss+=s[i];
            	i++;
        	}
        	postfix+=ss+" ";
        	i--;
		}
		else if (isdigit(s[i]) || s[i]=='.'){
            string ss="";
            while (i<s.size() && isdigit(s[i]) || s[i]=='.'){
                ss+=s[i];
                i++;
            }
            postfix+=ss+" ";
            i--;  
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '('){
                postfix+=st.top();
                postfix+=" ";
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(s[i])){
            while (!st.empty() && Priority(st.top()) >= Priority(s[i])){
                postfix+=st.top();
                postfix+=" ";
               	st.pop();
            }
            st.push(s[i]);
        }
    }
    
    while (!st.empty()){
        postfix+=st.top();
        postfix+=" ";
        st.pop();
    }  
    return postfix;
}

void Calculate(string s, string temp){
	stack<double> st;
	
	for (int i=0; i<s.size(); ++i) {
      	if (s[i] == ' ') continue;
      	
        string ss = "";
        if (s[i] == '-' && isdigit(s[i+1])){
        	ss+="-";
        	i++;
		} 
        while (i<s.size() && isdigit(s[i]) || s[i] == '.'){
            ss+=s[i];
            i++;
		}
        if (!ss.empty()) {
            st.push(stof(ss));
            i--;  
        }
        if (isOperator(s[i])) {
            double x=st.top();
            st.pop();
            double y=st.top();
            st.pop();

            switch (s[i]) {
                case '+': st.push(y + x); break;
                case '-': st.push(y - x); break;
                case '*': st.push(y * x); break;
                case '/':{
                	if (x == 0){
                		cout<<"\t\tLoi chia cho 0 !\n";
                		return;
					} 
                	else st.push(y / x);
					break;
				} 
                case '^': st.push(pow(y,x)); break;
            }
        }
    }
    cout<<"\t\tGia tri cua bieu thuc: "<<temp<<" = "<< st.top() << endl;
}

int main(){
	string s;
	char choice;
	do{	
		cout<<"\n";
		cout<<"\t\t-----------------CHUONG TRINH TINH TOAN BIEU THUC-----------------\n";
		cout<<"\t\t------------------------------------------------------------------\n";
		Input(s);
		string temp=s;
		Normalize(temp);
		cout<<"\t\tPostfix: "<<RPN(s)<<"\n";
    	Calculate(RPN(s),temp);
    	cout<<"\t\tBan co muon tiep tuc chuong trinh khong? Y/N \n";
    	cout<<"\t\tNhap lua chon: ";
    	cin>>choice;
    	cin.ignore();
    	if (tolower(choice) == 'y') continue;
    	else if (tolower(choice) == 'n'){
    		cout<<"\t\t----------------------Ket thuc chuong trinh !---------------------\n";
    		cout<<"\t\t------------------------------------------------------------------\n";
    		break;
		}
		else cout<<"\t\tLua chon khong ton tai !\n";
	} while (tolower(choice) == 'y');
	return 0;
}
