#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    map<string, string> mp;
    for(int i=0; i<n; i++){
        string s1,s2;
        cin>>s1>>s2;
        mp.insert({s1,s2});
    }
    string line;
    while(getline(cin, line)){
        if(line.empty()){
            break;
        } else {
            string s = line;
            bool res = false;
            for(auto it:mp){
                if(it.first == s){
                    res = true;
                    cout<<it.first<<"="<<it.second<<endl;
                    break;
                }
            }
            if(res==false){
                cout<<"Not found"<<endl;
            }
        }
    }
    return 0;
}