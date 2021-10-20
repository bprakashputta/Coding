#include<iostream>
using namespace std;

// Declare the node first
// It has data and next node
struct Node{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int sizeOfList(struct Node* head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
return count;
}

//Add node at front
struct Node* insertNodeAtFront(struct Node* head, int data){
    struct Node* temp = new Node(data);
    struct Node* curr = head;
    if(head == NULL){
        return temp;
    }else{
        temp->next = curr;
        curr = temp;
    }
return curr;
}

struct Node* insertLast(struct Node* head, int data){
    struct Node* temp = new Node(data);
    if(head == NULL){
        return temp;
    }
    struct Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
return head;
}

struct Node* insertInMiddle(Node* head, int x)
{
    //code here
    if(head == NULL){
        return new Node(x);
    }
    struct Node* temp = new Node(x);
    struct Node* curr = head;
    // struct Node* prev = NULL;
    int size = sizeOfList(head);
    if(size%2 == 1){
        size++;
    }
    int count = 1;
    while(count < size/2){
        // prev = curr;
        curr = curr->next;
        count++;
    }
    temp->next = curr->next;
    curr->next = temp;
return head;
}

struct Node* insertNodeAtK(struct Node* head, int data, int k){
    struct Node* temp = new Node(data);
    int size = sizeOfList(head);
    if(size<k-1){
        cout<<"Invalid List"<<endl;
        return head;
    }
    if(head == NULL){
        if(k==1){
            return temp;
        }else{
            cout<<"INVALID POSITION"<<endl;
            return NULL;
        }
    }
    int pos = 1;
    struct Node* curr = head;
    if(k==1){
        temp->next = curr;
        return temp;
    }
    while(curr->next != NULL && pos<k-1){
        curr = curr->next;
        pos++;
    }
    temp->next = curr->next;
    curr->next = temp;
return head;
}

struct Node * insertInSortedList(Node * head, int data)
{
    //Your code here
    if(head == NULL){
        return new Node(data);
    }
    struct Node* curr = head;
    struct Node* temp = new Node(data);
    if(data < curr->data){
        temp->next = curr;
        return temp;
    }
    while(curr->next != NULL){
        if(curr->next->data < data){
            curr = curr->next;
        }else{
            break;
        }
    }
    if(curr->next == NULL){
        curr->next = temp;
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
return head;
}

void printList(struct Node* head){
    struct Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

// struct Node* createList(int size){
//     struct Node* head = NULL;
//     struct Node* curr = NULL;
//     for(int i=0; i<size; i++){
//         int x;
//         cin>>x;
//         if(head == NULL){
//             struct Node* temp = new Node(x);
//             head = temp;
//             curr = temp;
//         }else{
//             struct Node* temp = new Node(x);
//             curr->next = temp;
//             curr = curr->next;
//         }
//     }
// return head;
// }

struct Node* createList(int arr[], int size){
    struct Node* head = NULL;
    struct Node* curr = NULL;
    for(int i=0; i<size; i++){
        // int x;
        // cin>>x;
        if(head == NULL){
            struct Node* temp = new Node(arr[i]);
            head = temp;
            curr = temp;
        }else{
            struct Node* temp = new Node(arr[i]);
            curr->next = temp;
            curr = curr->next;
        }
    }
return head;
}

struct Node* deleteNode(struct Node* head, int x){
    struct Node* curr = head;
    struct Node* prev = NULL;
    if(curr->data == x){
        return curr->next;
    }
    
    while(curr!=NULL){
        if(curr->data == x){
            break;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    if(curr == NULL){
        cout<<"Node doesnot exist"<<endl;
        return head;
    }
    prev->next = curr->next;

return head;
}

struct Node * deleteTail(Node *head)
{
    //Your Code here
        if(head == NULL){
        return NULL;
    }else if(head->next == NULL){
        return NULL;
    }
    struct Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    curr->next = curr->next->next;
return head;
}

struct Node * deleteHead(struct Node *head)
{
    if(head == NULL){
        return NULL;
    }else if(head->next == NULL){
        return NULL;
    }
return head->next;
}

struct Node* mergeTwoLists(struct Node* l1, struct Node* l2){
    struct Node* curr = l1;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = l2;
return l1;
}

struct Node* sortList(struct Node* head){
    struct Node* curr = head; 
    struct Node* itr = NULL;

    while(curr != NULL){
        int d1 = curr->data;
        itr = curr->next;
        while(itr!=NULL){
            int d2 = itr->data;
            if(d1>=d2){
                int temp = curr->data;
                curr->data = itr->data;
                itr->data = temp;
            }
            itr = itr->next;
        }
        curr = curr->next;
    }
return head;
}

void initialiseList(){
    //Initialise the nodes with NULL values
    int size;
    int arr[] = {10, 34, 23, 54, 13};
    size = sizeof(arr)/sizeof(arr[0]);
    // cin>>size;
    // struct Node* list = createList(size);
    // struct Node* list = createList(arr, size);
    // cout<<sizeOfList(list)<<endl;
    // // cout<<"Hi"<<endl;
    // printList(list);
    // cout<<"Hi"<<endl;
    // struct Node* newList = insertNodeAtFront(list, 500);
    // cout<<sizeOfList(newList)<<endl;
    // printList(newList);
    // struct Node* lastList = insertLast(newList, 500);
    // cout<<sizeOfList(lastList)<<endl;
    // printList(lastList);
    // struct Node* midList = insertNodeAtK(lastList, 501, 3);
    // cout<<sizeOfList(midList)<<endl;
    // printList(midList);
    // struct Node* delList = deleteNode(midList, 500);
    // cout<<sizeOfList(delList)<<endl;
    // printList(delList);

}

bool isSorted(Node * head)
{
    //Your code here
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL || head->next->next == NULL){
        return true;
    }
    struct Node* curr = head;
    while(curr->data == curr->next->data)
    {
        curr = curr->next;
    }
    if(curr->data < curr->next->data){
        Node* curr1 = curr;
        while(curr1->next!=NULL){
            if(curr1->data <= curr1->next->data){
                curr1 = curr1->next;
            }else{
                return false;
            }
        }
    }else{
        Node* curr2 = curr;
        while(curr2->next!=NULL){
            if(curr2->data >= curr2->next->data){
                curr2 = curr2->next;
            }else{
                return false;
            }
        }
    }
return true;
}

struct Node* reverseList(struct Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct Node* curr = head;
    struct Node* rev = NULL;
    struct Node* prev = NULL;
    while(curr!=NULL){
        prev = rev;
        rev = curr;
        curr = curr->next;
        rev->next = prev;
    }
return rev;
}



// struct Node* removeDuplicates(struct Node* llist) {
// // This code runs into runtime error
//     if(llist == NULL){
//         return NULL;
//     } else if(llist->next == NULL){
//         return llist;
//     }
    
//     Node* curr = llist;
//     curr = curr->next;
//     while(curr->next !=NULL){
//         if(curr->data == curr->next->data){
//             Node* nl = curr;
//             while(nl!=NULL && nl->data == curr->data){
//                 if(nl->next!=NULL && nl->next->data != curr->data){
//                     curr->next = nl->next;
//                     break;
//                 }else{
//                     nl = nl->next;
//                 }
//             }
//         }else{
//             curr = curr->next;
//         }
//     }
// return llist;
// }


Node* removeDuplicates(Node* llist) {
    if(llist == NULL){
        return NULL;
    } else if(llist->next == NULL){
        return llist;
    }
    
    Node* curr = llist;
    Node* res = NULL;
    Node* ans = res;
    curr = curr->next;
    while(curr->next !=NULL){
        cout<<"HI"<<endl;
        if(res == NULL){
            // cout<<"HI"<<endl;
            res->next = new Node(curr->data);
                cout<<"HI"<<endl;
            res = res->next;
            ans = res;
            // curr = curr->next;
        }else{
            if(curr->data != res->data){
                res->next = new Node(curr->data);
                res = res->next;
            }
        }
        curr = curr->next;
    }
return ans;
}

int main(){

    int arr[] = {10, 34, 23, 54, 13};
    int size = sizeof(arr)/sizeof(arr[0]);

    int arr1[] =  {10, 34, 23, 54, 13};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] =  {10, 94, 24, 54, 17};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    // struct Node* list1 = createList(arr1, size1);
    // printList(list1);
    // list1 = sortList(list1);
    // printList(list1);
    // struct Node* list2 = createList(arr2, size2);
    // printList(list2);
    // list2 = sortList(list2);
    // printList(list2);
    // struct Node* mergeList = mergeTwoLists(list1, list2);
    // printList(mergeList);


    // struct Node* l = createList(arr2, size2);
    // printList(l);
    // struct Node* revl = reverseList(l);
    // printList(revl);

    struct Node* list1 = createList(arr1, size1);
    printList(removeDuplicates(list1));
    return 0;
}
