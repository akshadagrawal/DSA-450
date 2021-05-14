//Reverase a linked lst

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
    Node * reverse();
    void print();

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
Node * SLL:: reverse(){
    Node *current= head;
    Node *prev= NULL, *next=NULL;
    while(current !=NULL){
        next= current->next;
        current->next= prev;
        prev= current;
        current= next;
    }
    head= prev;
    return head;

    
}
int main(){
    SLL ll;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(5);
    ll.print();
    ll.reverse();
    ll.print();
} 