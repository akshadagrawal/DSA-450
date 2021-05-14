#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node(){
            next= NULL;
        }
};
class SLL{
    Node *head;
    public:
        SLL(){
            head= NULL;
        }
        void createLinkedList();
        void printElements();
        Node* insertElements(int n);
        Node* insertAtBeg();
        Node* insertAtEnd();
        Node* insertAtPos(int pos);
        Node* deleteAtBeg();
        Node* deleteAtEnd();
        Node* deleteAtPos(int pos);

};
void SLL::createLinkedList(){
    head= new Node();
}
Node* SLL ::insertElements(int n){
    cout<<"Enter head node: ";
    int x;
    cin>>x;
    head->data= x;
    Node *p= head, *q;

    for(int i=1;i<n;i++){
        cout<<"Enter next Node: ";
        cin>>x;
        q=new Node();
        q->data= x;
        p->next=q;
        p=p->next;
    }
    return head;
}
Node* SLL::insertAtBeg (){
    cout<<"Enter node: ";
    int x;
    cin>>x;
    Node *q;
    q=new Node();
    q->data=x;
    q->next=head;
    head=q;
    return head;
}
Node* SLL::insertAtEnd (){
    cout<<"Enter node: ";
    int x;
    cin>>x;
    Node *q ,*p = head;
    q=new Node();
    q->data=x;
    while(p->next!= NULL){
        p=p->next;
    }
    p->next=q;
    return head;

}
Node* SLL:: insertAtPos(int pos){
    if(pos==1) insertAtBeg();
    else {
        cout<<"Enter node: ";
        int x;
        cin>>x;
        Node *q ,*p = head;
        q=new Node();
        q->data=x;
        for(int i=1;i < pos-1;i++)
            p=p->next;
        q->next= p->next;
        p->next= q;
    }
    return head;
}
Node* SLL:: deleteAtEnd(){
    Node *p=head;
    while(p->next->next!=NULL)
        p=p->next;
    Node *q=p->next;
    p->next=NULL;
    delete(q);
    return head;
}
Node* SLL:: deleteAtBeg(){
    Node *p=head;
    head= p->next;
    delete(p);
    return head;
}
Node* SLL:: deleteAtPos(int pos){
    Node *p=head;
    for(int i=1;i< pos-1;i++){
        p=p->next;
    }
    Node* q= p->next;
    p->next= q->next;
    delete(q);
    return head;
}
void SLL:: printElements(){
    Node *p= head;
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}

int main(){
    SLL ll;
    ll.createLinkedList();
    cout<<"Enter number of elements: ";
    int x;
    cin>>x;
    ll.insertElements(x);
    //ll.insertAtBeg();
    //ll.insertAtEnd();
    // cout<<"Enter Position: ";
    // cin>>x;
    // ll.insertAtPos(x);
    //ll.deleteAtBeg();
    //ll.deleteAtEnd();
    cout<<"Enter Position: ";
    cin>>x;
    ll.deleteAtPos(x);


    ll.printElements();
}