#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->parent=NULL;
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
class RB{
    public:
    Node* root=NULL;

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
    }
};
int main(){
    RB r;
    r.Insert(11);
    r.Insert(2);
    r.Insert(1);
    r.Insert(10);
    r.visualizeTree(r.root,10);

}