//Reverase a linked lst in given group 

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
    Node * reverse(int k);
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
Node *reverseUtil(Node* prev,Node* head, Node* next, int k){
        Node *current= head,*p=head;
        if(current==NULL) return NULL;
        for(int i=0;i<k && current!=NULL;i++){
            next= current->next;
            current->next=prev;
            prev=current;
            current= next;
        }
        p->next= reverseUtil(NULL, current, NULL, k);
        head= prev;
        return head;
 }
Node * SLL:: reverse(int k){
        Node *prev= NULL,* next=NULL;
       head= reverseUtil(prev, head, next,k);
       return head;   
}
int main(){
    SLL ll;
    ll.push(1);
    ll.push(2);
    ll.push(2);
    ll.push(4);
    ll.push(6);
    ll.push(5);
    ll.push(7);
    ll.push(8);
    ll.print();
    int k;
    cin>>k;
    ll.reverse(k);
    ll.print();
} 