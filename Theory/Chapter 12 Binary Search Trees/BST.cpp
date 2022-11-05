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
    Node* Root;
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
};

int main(){ 

}