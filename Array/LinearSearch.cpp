#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int res=-1;
    for(int i=0; i<n; i++){
        if(arr[i] == k){
            res=i;
            break;
        }
    }
    if(res!=-1){
        cout<<res<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
return 0;
}