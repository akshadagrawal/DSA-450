// //Merge sort for linke lists


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
int count(Node *head){
    Node *p=head;
    int cnt=0;
    while(p!=NULL)  {
        cnt++;
        p=p->next;
    }
    return cnt;
}
Node * merge(Node * head1, Node* head2){
    SLL final;
    Node *p=head1, *q= head2;
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            final.push(p->data);
            p=p->next;
        }
        else {
            final.push(q->data);
            q=q->next;
        }    
    }
    while(p!=NULL) {
         final.push(p->data);
        p=p->next;
    }
    while(q!=NULL) {
         final.push(q->data);
        q=q->next;
    }

    return final.head;

}
Node *findMid(Node *head){
    Node *p =head, *q= head->next;

    while(q!=NULL && q->next!= NULL){
        q=q->next->next;
        p=p->next;
    }
    return p;
    
}
Node* mergeSort(Node *head){
   if(head->next ==NULL) return head ;
   Node *head1;
   Node * mid = findMid(head);
   
    head1= mid->next;
    mid->next= NULL;
    Node * new1= mergeSort(head);
    Node * new2= mergeSort(head1);

   Node *final= merge(new1, new2);
   return final;
    
}

int main(){
    SLL ll;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(5);
    ll.push(3);

    ll.print();
    ll.head= mergeSort(ll.head);
     ll.print();
} 