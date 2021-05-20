//reverse a dll

#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* prev;
        Node *next;
        Node(){
            prev= NULL;
            next=NULL;
        }
};
class DLL{
    Node *head;
    public: 
        DLL(){
            head= NULL;
        }
        Node* push(int x);
        void print();
        Node* reverse();
};
Node* DLL:: push(int x){
    if(head==NULL) {
        head =new Node();
        head->data= x;
    }
    else {
        Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        Node *q= new Node();
        q->data= x;
        p->next=q;
        q->prev=p;
    }
    return head;
}
void DLL:: print(){
    Node* p = head;
    while(p!= NULL ){
           cout<<p->data<<"->";
            p=p->next;
    }
    // while(p!=NULL){
    //     cout<<p->data<<"->";
    //     p=p->prev;
    // }
    cout<<"NULL"<<endl;
}
Node* DLL::reverse(){
    Node *current= head;
    Node* prev=NULL, *next=NULL;
    while(current!=NULL){
        next= current->next;
        current->next= prev;
        current->prev= next;
        prev=current;
        current=next;
    }
    head= prev;
    return head;
}

int main(){
    DLL ll;
    ll.push(5);
    ll.push(15);
    ll.push(9);
    ll.push(8);
    ll.print();
    ll.reverse();
    ll.print();


}
