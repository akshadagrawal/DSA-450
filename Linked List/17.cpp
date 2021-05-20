//divide cll into 2;


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
    void divideCLL(Node **, Node **);
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
void SLL:: divideCLL(Node ** head1, Node** head2){
    Node *p=head;
    p=p->next;
    int length=1;
    while(p!=NULL){
        if(p==head) break;
        p=p->next;
        length++;
    }
    int mid;
    length%2==0 ? mid= length/2 : mid=length/2 +1 ;
    p=head;
    for (int i=1; i<mid;i++){
        p=p->next;
    }
    *head1= head;
    *head2=p->next;
    p->next= head;
    Node *q= *head2;
    while(q->next!= head) q=q->next;
    q->next = *head2;

    
    


}
void SLL:: print(){
    Node *p=head;
    do{
        cout<<p->data<<"->";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}

int main(){
    SLL ll, ll1, ll2;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(20);
    ll.push(30);
        ll.push(30);

    ll.head->next->next->next->next->next->next= ll.head;
    ll.divideCLL(& ll1.head, & ll2.head);
    ll.print();
    ll1.print();
    ll2.print();
} 