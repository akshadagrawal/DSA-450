//print top view of a tree
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
void printleft(Node* root){
  if(root== NULL) return;
  printleft(root->left);
  cout<<root->data<<" ";
}
void printRight(Node* root){
  if(root== NULL) return;
 cout<<root->data<<" ";
  printRight(root->right);
}
void printTop(Node* root){
    if(root == NULL )  return;
    printleft(root->left);
    cout<<root->data<<" ";
    printRight(root->right);
}
int main(){
    /*
                    1
                2      3
             4       6      5
                              8
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(5);
    root->right->right->right = new Node(8);
    printTop(root);
}