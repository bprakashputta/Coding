
#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if(llist == NULL){
        return new DoublyLinkedListNode(data);
    }
    if(llist->data > data){
        DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
        temp->next = llist;
        return temp;
    }
    
    DoublyLinkedListNode* head = llist;
    DoublyLinkedListNode* tail = NULL;
    while(head!=NULL && head->data<data){
        tail = head;
        head = head->next;
    }
    DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
    tail->next = temp;
    temp->prev = tail;
    if(head==NULL){
        return llist;
    }
    temp->next = head;
    head->prev = temp;
return llist;
}


DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(llist==NULL || llist->next == NULL){
        return llist;
    }
    
    DoublyLinkedListNode* curr = llist;
    DoublyLinkedListNode* rev = NULL;
    
    // Swap the addresses of prev and next
    // for each node
    while(curr!=NULL){
        rev = curr->prev;
        curr->prev = curr->next;
        curr->next = rev;
        curr = curr->prev;      
    }
    // return rev->prev;
    if(rev!=NULL){
        llist = rev->prev;
    }
return llist;
}