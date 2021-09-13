#include<iostream>
#include<vector>

using namespace std;

vector<int> sieveOfErasthenetos(int n){
    vector<int> arr(n+1);
    arr[0]=1;
    arr[1]=1;
    for(int i=2; i*i<=n; i++){
        if(arr[i]==0){
            for(int j=i*i; j<=n; j+=i){
                arr[j] = 1;
            }
        }
    }
    vector<int> ans(0);
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            ans.push_back(i);
        }
        cout<<i<<" "<<arr[i]<<endl;
    }
return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr = sieveOfErasthenetos(n);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}