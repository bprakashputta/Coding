#include <iostream> 
using namespace std;

void push(int *stk, int &top, int n, int val){
    if(top==n-1){
        cout<<"Stack is Full"<<endl;
        return;
    }else {
        if(top==-1){
            top = 0;
            stk[top] = val;
        }else{
            top;
            stk[top]=val;
        }
    }
}


int pop(int *stk, int & top){
    if(top==-1){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }else{
        top--;
        return stk[top+1];
    }
return 0;
}

int main(){
    int n = 10;
    int stk[n] = {0};
    int val;
    int top = -1;
    cin>>val;

    // while(cin>>val){
    push(stk, top,n, val);
    push(stk, top,n, val);
    pop(stk, top);
    push(stk, top,n, val);
    pop(stk, top);
    push(stk, top,n, val);
    push(stk, top,n, val);
    // }
    cout<<"top:"<<top<<endl;
    for(int i=top; top>=0; top--){
        cout<<stk[top]<<" ";
    }
    cout<<endl;
return 0;
}