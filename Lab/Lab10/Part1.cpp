#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* parent;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->parent=NULL;
        this->left=NULL;
        this->right=NULL;
    }
    ~Node(){
        delete parent;
        delete left;
        delete right;
        this->parent=NULL;
        this->left=NULL;
        this->right=NULL;
    }
};
class BST{
    public:
    Node* Root=NULL;
    BST(){

    }
    BST(int arr[],int size){
        for (int i=0;i<size;i++){
            Insert(arr[i]);
        }
    }
    ~BST(){
        Root=NULL;
    }

    //is BST exit
    bool isBST(){
        if(Root!=NULL){
            return true;
        }
        return false;
    }
      
    int height(Node* T){
        Node* x=T;
        int count=0;
        while(x!=NULL){
            if(x->left!=NULL){
                x=x->left;
                count++;
            }
            if(x->right!=NULL){
                x=x->right;
                count++;
            }
        }
        return count;
    }
    //Number of Nodes
    int NumberofNode(){
        int count=0;
        Node* x=Root;
        while(x!=NULL){
            count++;
        }
        return count;
    } 
    
    //Empty Root
    bool isEmpty(){
        if(Root==NULL){
            return true;
        }
        return false;
    }
    //get root tree
    Node* getTree(){
        return Root;
    }
     //visualize tree on console
    void visualizeTree(Node* T,int space){
        Node* node=T;
        if(node==NULL){
            return;
        }
        space+=10;
        visualizeTree(node->left,space);
        cout<<endl;
        for(int i=10;i<space;i++){
            cout<<" ";
        }
        cout<<node->data<<endl;
        visualizeTree(node->right,space);
    }
    //Traverse : Approach to each node and then print
    void printInorder(Node *p){
        if(p!=NULL){
            printInorder(p->left);
            cout<<p->data<<" ";
            printInorder(p->right);
        }
        cout<<endl;
    }
    void printPreorder(Node *p){
        if(p!=NULL){
            cout<<p->data<<" ";
            printPreorder(p->left);
            printPreorder(p->right);
        }
    }
    void printPostorder(Node *p){
        if(p!=NULL){
            printPostorder(p->left);
            printPostorder(p->right);
            cout<<p->data<<" ";
        }
    }
    //Search Iterative
    Node * searchIterative(Node *x,int k){
        while(x!=NULL && k!=x->data){
            if(k<x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        return x;
    }
    //Search Recursive 
    Node* search(Node *x,int k){
        if (x == NULL || x->data == k){
            return x;
        }
        if(k< x->data){
            search(x->left,k);
        }
        else{
            search(x->right,k);
        }
    }

    //Insertion
    void Insert(int data){
        Node *z =new Node(data);
        Node *y=NULL; //Trailing pointer
        Node *x=Root; //Parent of BST
        while(x!=NULL){
            y=x;
            if(z->data < x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        z->parent=y; //Make the parent
        if(y==NULL){
            Root=z;
        }
        else if(z->data < y->data){
            y->left=z;
        }
        else{
        y->right=z;
        }
    }
    void leafNode(Node* T){
        Node* x=T;
        if(x==NULL){
            return;
        }
        if(x->left==NULL && x->right==NULL){
            cout<<x->data<<" ";
        }
        leafNode(x->left);
        leafNode(x->right);
    }

};

int main(){ 
    //Node *Node1=new Node(2);
    BST b;
    //Node* r=b.Root;
    b.Insert(5);
    b.Insert(3);
    b.Insert(7);
    b.Insert(4);
    b.Insert(6);
    b.leafNode(b.Root);
    //b.printInorder(b.Root);
    //b.printInorder(b.Root);
    b.visualizeTree(b.Root,20);

    //Node *a=b.searchIterative(r,10);
    // Node *a=b.search(b.Root,10);
    //cout<<a->data;
    
}