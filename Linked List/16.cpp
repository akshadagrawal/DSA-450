//fcheck cll or not

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
    public: 
    Node *head;
    SLL(){
        head = NULL;
    }
    Node* push(int val);
    bool checkCLL();
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
bool SLL:: checkCLL(){
    Node *p=head;
    p=p->next;
    while(p!=NULL){
        if(p==head)  return 1;
    }
    return 0;

}
void SLL:: print(){
    Node *p=head;
    while(p!=NULL) {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    SLL ll, ll1;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(5);
    ll.push(5);

    ll.print();
} 