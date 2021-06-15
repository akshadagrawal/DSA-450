//find diameter of tree
#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left, *right;
        Node(){
            left= NULL;
            right= NULL;
        }
        Node(int x){
            data=x;
            left= NULL;
            right= NULL;
        }
};
class Tree {
    Node * root;
    void printTree(Node* );
    int height(Node * root);
    int diameter(Node* root);
    public: 
        Tree(){
            root = NULL;
        }
        void makeTree();
        Node* createTree();
        void printTree();  
        int diameter();      
};
Node* Tree::createTree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;
    Node* p= new Node(x);
    p->left= createTree();
    p->right= createTree();
    root= p;
    return root;
}
void Tree::printTree(){
    printTree(root);
}
void Tree:: printTree(Node* root){

    if(root==NULL) return;
    cout<<root->data;
    printTree(root->left);
    printTree(root->right);
}
void Tree::makeTree(){
    root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
}
int Tree:: diameter(){
    return diameter(root);
}
int Tree:: height(Node* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
 }
 int Tree:: diameter(Node* root) {
        if(root==NULL ) return 0;
        //cout<<root->data<<" "<<leftMax(root)+ rightMax(root)-1<<endl;
        return max(height(root->left) + height(root->right) +1, max(diameter(root->left), diameter(root->right)));
    }
int main(){
    Tree t;
    /*
                1
            2       3
          4   5   6  
    */
    t.makeTree();
    //t.createTree();
    t.printTree();
    cout<<endl<<t.diameter();
}