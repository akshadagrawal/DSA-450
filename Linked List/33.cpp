//delete nodes with value greater on right side
#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node *next;
        Node(){
            next=NULL;
        }
};
class SLL{
    Node *head;
    public: 
    SLL(){
        head = NULL;
    }
    Node* push(int val);
    void print();
    Node* updateLL();

};
Node *SLL:: push(int val){
    if(head==NULL){
         head= new Node();
         head->data= val;
    }
    else {
        Node *p=head;
        while(p->next!=NULL) p= p->next;
        Node *q;
        q= new Node();
        q->data= val;
        p-> next= q;  
    }
    return head;
    
}
void SLL:: print(){
    Node *p=head;
    while(p!=NULL) {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
Node *findMax(Node *head){
    if (head==NULL || head->next==NULL) return head;
    Node *p= head, *maxNode;
    int max= INT_MIN;
    while(p!=NULL){
        if(p->data > max) {
            max= p->data;
            maxNode= p;
        }
        p=p->next;
    }
    return maxNode;
}
Node* SLL:: updateLL(){
    SLL temp;
    Node *p=head;
    Node * max= findMax(head);
    temp.push(max->data);
    
    while(max!=NULL){
        max= findMax(max->next);
        max!=NULL && temp.push(max->data);
    }

     head= temp.head;
    return head;
}

int main(){
    SLL ll;
    ll.push(12);
    ll.push(15);
    ll.push(10);
    ll.push(11);
    ll.push(5);
    ll.push(6);
    ll.push(2);
    ll.push(3);
    ll.print();



    ll.updateLL();
    ll.print();
} 