#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int k){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == k){
            return mid;
        }else if(arr[mid] > k){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
return -1;
}

int main(){
    int arr[] = {3, 5, 7, 11, 13, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    cout<<binarySearch(arr, n, k)<<endl;
return 0;
}