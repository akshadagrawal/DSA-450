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
void preorder(Node* root){
    if(root ==NULL) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node*p= s.top();
        cout<<p->data<<" ";
        s.pop();
        if(p->right) s.push(p->right); //push right first so that you can process left first
        if(p->left) s.push(p->left);
    }
}
void preorderRec(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorderRec(root->left);
    preorderRec(root->right);
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

    preorder(root);
    cout<<endl;
    preorderRec(root);
}