#include<iostream>
using namespace std;
const int MAX = 1000;

int fibo[MAX] = {0};

int memo_fibo(int n){
    if(n==0||n==1){
        fibo[n] = n;
        return n;
    }

    if(fibo[n]!=0){
        return fibo[n];
    }else{
        fibo[n] = memo_fibo(n-1)+memo_fibo(n-2);
        return fibo[n];
    }
return fibo[n];
}



int main(){
    cout<<memo_fibo(4)<<endl;
return 0;
}