#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    int height;
    Node* parent;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->parent=NULL;
        this->left=NULL;
        this->right=NULL;
        this->height = 1;
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
    private:
    Node* root=NULL;
    public:
    BST(){
    }
    BST(int arr[],int size){
        for (int i=0;i<size;i++){
            Insert(arr[i]);
        }
    }
    ~BST(){
        root=NULL;
    }
    bool isEmpty(){
        if (root==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    Node* getTree(){
        return root;
    }
    void Insert(int data){
        Node *z =new Node(data);
        Node *y=NULL; //Trailing pointer
        Node *x=root; //Parent of BST
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
            root=z;
        }
        else if(z->data < y->data){
            y->left=z;
        }
        else{
        y->right=z;
        }
    }
    Node* findNode(int data){
        Node* x=root;
        while(x!=NULL && x->data!=data){
            if(data<x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        return x;
    }
    bool deleteNode(int x){
        Node* z=findNode(x);
        if(z==NULL){
            return false;
        }
        else{
            if(z->left==NULL){
                transplant(z,z->right);
            }
            else if(z->right==NULL){
                transplant(z,z->left);
            }
            else{
                Node* y=treeMinimum(z->right);
                if(y->parent!=z){
                    transplant(y,y->right);
                    y->right=z->right;
                    y->right->parent=y;
                }
                transplant(z,y);
                y->left=z->left;
                y->left->parent=y;
            }
            delete z;
            return true;
        }
    }
    void transplant(Node* u,Node* v){
        if(u->parent==NULL){
            root=v;
        }
        else if(u==u->parent->left){
            u->parent->left=v;
        }
        else{
            u->parent->right=v;
        }
        if(v!=NULL){
            v->parent=u->parent;
        }
    }
    Node* treeMinimum(Node* x){
        while(x->left!=NULL){
            x=x->left;
        }
        return x;
    }

    void inOrderTraversal(Node *p){
        if(p!=NULL){
            inOrderTraversal(p->left);
            cout<<p->data<<" ";
            inOrderTraversal(p->right);
        }
        cout<<endl;
    }
    void preOrderTraversal(Node *p){
        if(p!=NULL){
            cout<<p->data<<" ";
            preOrderTraversal(p->left);
            preOrderTraversal(p->right);
        }
        cout<<endl;
    }
    void postOrderTraversal(Node *p){
        if(p!=NULL){
            postOrderTraversal(p->left);
            postOrderTraversal(p->right);
            cout<<p->data<<" ";
        }
        cout<<endl;
    }
    int numberOfNodes(Node *p){
        if(p==NULL){
            return 0;
        }
        else{
            return numberOfNodes(p->left)+numberOfNodes(p->right)+1;
        }
    }
    int height(Node* T){
        if(T==NULL){
            return 0;
        }
        else{
            int lheight=height(T->left);
            int rheight=height(T->right);
            if(lheight>rheight){
                return lheight+1;
            }
            else{
                return rheight+1;
            }
        }
    }
    bool isBST(Node *T){
        if(T==NULL){
            return true;
        }
        else{
            if(T->left!=NULL && T->left->data>T->data){
                return false;
            }
            if(T->right!=NULL && T->right->data<T->data){
                return false;
            }
            if(!isBST(T->left) || !isBST(T->right)){
                return false;
            }
            return true;
        }
    }
    void leafNodes(Node *T){
        if(T!=NULL){
            if(T->left==NULL && T->right==NULL){
                cout<<T->data<<" ";
            }
            leafNodes(T->left);
            leafNodes(T->right);
        }
    }
    bool isSparseTree(Node *T){
        if(T==NULL){
            return true;
        }
        else{
            if(T->left==NULL && T->right==NULL){
                return true;
            }
            if(T->left!=NULL && T->right!=NULL){
                return false;
            }
            return isSparseTree(T->left) && isSparseTree(T->right);
        }
    }
    void visualizeTree(Node *T,int space){
        if(T==NULL){
            return;
        }
        space+=10;
        visualizeTree(T->right,space);
        cout<<endl;
        for(int i=10;i<space;i++){
            cout<<" ";
        }
        cout<<T->data<<endl;
        visualizeTree(T->left,space);
    }  
};
class AVLTree:BST{
    private:
    Node* root;
    public:
    AVLTree(){

    }
    AVLTree(int arr[],int size){
        for (int i=0;i<size;i++){
            Insert(arr[i]);
        }
    }
    ~AVLTree(){
        delete root;
    }
    Node* getTree(){
        return root;
    }
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        return root->height;
    }
    void leftRotate(Node*x){
        Node *y=x->right;
        x->right=y->left;
        if(y->left!=NULL){
            y->left->parent=x;
        }
        y->parent=x->parent;
        if(x->parent==NULL){
            root=y;
        }
        else if(x==x->parent->left){
            x->parent->left=y;
        }
        else{
            x->parent->right=y;
        }
        y->left=x;
        x->parent=y;
    }
    void rightRotate(Node*x){
        Node *y=x->left;
        x->left=y->right;
        if(y->right!=NULL){
            y->right->parent=x;
        }
        y->parent=x->parent;
        if(x->parent==NULL){
            root=y;
        }
        else if(x==x->parent->right){
            x->parent->right=y;
        }
        else{
            x->parent->left=y;
        }
        y->right=x;
        x->parent=y;
    }
    void Insert(int data){
        Node *z=new Node(data);
        Node *y=NULL;
        Node *x=root;
        while(x!=NULL){
            y=x;
            if(z->data<x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        z->parent=y;
        if(y==NULL){
            root=z;
        }
        else if(z->data<y->data){
            y->left=z;
        }
        else{
            y->right=z;
        }
        z->left=NULL;
        z->right=NULL;
        z->height=1;
        balance(z);
    }
    void balance(Node *z){
        while(z!=NULL){
            z->height=max(height(z->left),height(z->right))+1;
            int balanceFactor=height(z->left)-height(z->right);
            if(balanceFactor>1){
                if(height(z->left->left)>=height(z->left->right)){
                    rightRotate(z);
                }
                else{
                    leftRotate(z->left);
                    rightRotate(z);
                }
            }
            else if(balanceFactor<-1){
                if(height(z->right->right)>=height(z->right->left)){
                    leftRotate(z);
                }
                else{
                    rightRotate(z->right);
                    leftRotate(z);
                }
            }
            z=z->parent;
        }
    }
    void visualizeTree(Node *T,int space){
        if(T==NULL){
            return;
        }
        space+=10;
        visualizeTree(T->right,space);
        cout<<endl;
        for(int i=10;i<space;i++){
            cout<<" ";
        }
        cout<<T->data<<endl;
        visualizeTree(T->left,space);
    }  
    
   
};
int main(){
    AVLTree t;
    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.visualizeTree(t.getTree(),0);

}