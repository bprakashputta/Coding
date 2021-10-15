#include<bits/stdc++.h>
#include<string>
using namespace std;

string isBalanced(string s) {
    // if(s.length()==0){
    //     return "NO";
    // }
    stack<char> stk;
    string ans = "";
    stk.push(s[0]);
    if((s[0]==')') || (s[0]=='}') || (s[0]==']')){
        return "NO";
    }
    for(int i=1; i<s.length(); i++){
        if(!stk.empty()){
            if((s[i]=='(') || (s[i]=='{') || (s[i]=='[')){
                stk.push(s[i]);
            }else if(s[i]==')' && stk.top()=='('){
                ans = "YES";
                stk.pop();
            }else if(s[i]=='}' && stk.top()=='{'){
                ans = "YES";
                stk.pop();
            }else if(s[i]==']' && stk.top()=='['){
                ans = "YES";
                stk.pop();
            }else{
                ans = "NO";
                break;
            }
        }else{
            if((s[i]=='(') || (s[i]=='{') || (s[i]=='[')){
                stk.push(s[i]);
            }else{
                ans = "NO";
                break;
            }
        }
    }
    if(!stk.empty()){
        ans = "NO";
    }
return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<isBalanced(str)<<endl;
return 0;
}