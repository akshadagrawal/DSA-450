//code to non recursively traverse the tree

#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left, *right;
        Node(int x){
            data= x;
            left=right=NULL;
        }
};
void postorder_2stack(Node* root){
    if(root==NULL) return;
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node *p= s1.top();
        s1.pop();
        s2.push(p);
        if(p->left) s1.push(p->left);
        if(p->right) s1.push(p->right);
    }
    while(!s2.empty()) {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }

}
void postorder_1stack(Node* root){
    if(root ==NULL) return;
    stack<Node*> s;
   while(1){
       while(root){
           s.push(root);
           s.push(root);
           root= root->left;
       }
       if(s.empty()) return;

       root= s.top();
       s.pop();
       //if so that we can go to right
       if(!s.empty() && s.top() == root) root= root->right;
       else  {
           //indicate that this node is leaf node
           cout<<root->data<<" ";
           root=NULL;
       }

   }
}
void postorderRec(Node* root){
    if(root== NULL) return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout<<root->data<<" ";

}
int main(){
    /*
                1
            12      9
        5       6
    */
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    postorderRec(root);
    cout<<endl;
    postorder_1stack(root);
}
