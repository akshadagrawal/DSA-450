//detect loop in a linked list

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;   
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position){
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}
class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        map<Node * ,int> m;
        Node *p =head;
        while(p!=NULL){
           if(m.find(p->next) != m.end()) return 1;
           m[p->next]++;
           p=p->next;
        }
        return 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++){
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}