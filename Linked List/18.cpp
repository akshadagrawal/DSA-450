//check if linked list is palindrome or not


#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node (){
            next= NULL;
        }
};
class SLL{
    Node *head;
    public:
        SLL(){
            head= NULL;
        }
        Node *push(int x);
        void print();
        bool isPalindrome();

};
Node* SLL:: push(int x){
    if(head== NULL){
        head= new Node();
        head->data=x;
    }
    else {
        Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        Node *q= new Node();
        q->data= x;
        p->next= q;
    }
    return head;
}
void SLL:: print(){
    Node *p =head;
    while(p!=NULL) {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
bool SLL:: isPalindrome(){
    stack<int> s;
    Node *p=head;
    while(p!=NULL) {
        s.push(p->data);
        p=p->next;
    }
    p= head;
    while(p!=NULL){
       int x= s.top();
       s.pop();
       if(x != p->data) return false;
       p=p->next;
       
    }
    return true;

}
int main(){
    SLL ll;
    ll.push(2);
    ll.push(3);
    ll.push(1);
    ll.push(3);
    ll.push(2);
    ll.print();
    ll.isPalindrome() ? cout<<"Is a Palindrome" : cout<<"Not a palindrome";
    

}
