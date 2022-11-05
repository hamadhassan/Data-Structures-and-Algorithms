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
    Node* Root;
    //Traverse : Approach to each node and then print
    void printInorder(Node *p){
        if(p!=NULL){
            printInorder(p->left);
            cout<<p->data<<" ";
            printInorder(p->right);
        }
    }
    void printPreorder(Node *p){
        if(p!=NULL){
            cout<<p->data<<" ";
            printPreorder(p->left);
            printPreorder(p->right);
        }
        cout<<endl;
    }
    void printPostorder(Node *p){
        if(p!=NULL){
            printPostorder(p->left);
            printPostorder(p->right);
            cout<<p->data<<" ";
        }
        cout<<endl;
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
};

int main(){ 
    Node *Node1=new Node(2);
    BST b;
    //Node* r=b.Root;
    b.Insert(50);
    b.Insert(30);
    b.Insert(20);
    b.Insert(40);
    b.Insert(70);
    b.Insert(60);
    b.Insert(80);
    b.printInorder(b.Root);
    //Node *a=b.searchIterative(r,10);
    // Node *a=b.search(b.Root,10);
    //cout<<a->data;
    
}