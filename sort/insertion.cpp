#include<iostream>
using namespace std;

void insertionSort(int *A, int n){
    for(int j=1; j<n; j++){
        int key = A[j];
        int i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

int main(){
    int n;
    // cin>>n;
    int A[] = {4, 2, 5, 7, 1, 7, 3, 9};
    n = sizeof(A)/sizeof(A[0]);
    cout<<n<<endl;
    // for(int i=0; i<n; i++){
    //     cin>>A[i];
    // }

    // before sorting
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout<<endl;

    // sort array
    insertionSort(A, n);

    // after sorting
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout<<endl;
return 0;
}
