#include<iostream>
#include<string>

using namespace std;

string timeConversion(string s) {
    int n = s.length();
    string ans = "";
    cout<<s[0]<<endl;

    if(s[n-2]=='P'||s[n-2]=='p'){
        string s1 = "";
        s1.append(s, 0, 2);
        cout<<s1<<endl;
        int n = 0;
        if(s1 == "12"){
            n = std::stoi(s1);
        }else{
            n = 12 + std::stoi(s1);
        }
        ans = to_string(n);    
    }else {
        ans.append(s,0,2);
        if(ans == "12"){
            ans = "00";
        }
    }
    for(int i=2; i<n-2; i++){
        ans += s[i];
    }
return ans;
}

int main(){
    string st = "12:00:00PM";
    cout<<timeConversion(st)<<endl;
return 0;
}