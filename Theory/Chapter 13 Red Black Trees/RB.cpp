#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    char color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data,char color){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->parent=NULL;
        this->color=color;
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

    void Insert(int data,char color){  
        Node *z =new Node(data,color);
        Node *y=NULL; //Trailing pointer
        Node *x=root; //Parent of BST
        while(x!=NULL){//these are trailing to find the exact location for inseration
            y=x;
            if(z->data < x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        z->parent=y; //Make the parent
        if(y==NULL){//run only first time
            root=z;
        }
        else if(z->data < y->data){
            y->left=z;
        }
        else{
        y->right=z;
        }
        z->left=NULL;
        z->right=NULL;
        z->color='R';
        RBInsertFixup(z);
    }
    void RBInsertFixup(Node* z){
        Node *y=NULL;
        while(z->parent->color=='R'){
            if(z->parent==z->parent->parent->left){
                y=z->parent->parent->right;
                if(y->color=='R'){
                    z->parent->color='B';           //case1
                    y->color='B';                   //case1
                    z->parent->parent->color='R';   //case1
                    z=z->parent->parent;            //case1
                }
                else if (z==z->parent->right){
                    z=z->parent;                    //case2
                    leftRotate(z);                  //case2
                    z->parent->color='B';           //case3
                    z->parent->parent->color='R';   //case3
                    rigthRotate(z->parent->parent); //case3
                }            
            }
            else{
                y=z->parent->parent->left;
                if(y->color=='R'){
                    z->parent->color='B';           //case1
                    y->color='B';                   //case1
                    z->parent->parent->color='R';   //case1
                    z=z->parent->parent;            //case1
                }
                else if (z==z->parent->left){
                    z=z->parent;                    //case2
                    leftRotate(z);                  //case2
                    z->parent->color='B';           //case3
                    z->parent->parent->color='R';   //case3
                    rigthRotate(z->parent->parent); //case3
                }  
            }
        }
        root->color='B';
    }
    void leftRotate(Node* x){
        Node *y=NULL;
        y=x->right;
        x->right=y->left;
        if(y->left!=NULL){
            y->left->parent=x;
        }
        y->parent=x->parent;
        if(x->parent=NULL){
            root=y;
        }
        else if(x=x->parent->left){
            x->parent->left=y;
        }
        else{
            x->parent->right=y;
        }
        y->left=x;
        x->parent=y;
        
    }
    void rigthRotate(Node* x){
        Node *y=NULL;
        y=x->left;
        x->left=y->right;
        if(y->right!=NULL){
            y->right->parent=x;
        }
        y->parent=x->parent;
        if(x->parent=NULL){
            root=y;
        }
        else if(x=x->parent->left){
            x->parent->left=y;
        }
        else{
            x->parent->right=y;
        }
        y->right=x;
        x->parent=y;
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
        cout<<node->data <<"C:"<<node->color<<endl;
        visualizeTree(node->right,space);
    }
};
int main(){
    RB r;
    r.Insert(11,'B');
    r.Insert(14,'B');
    r.Insert(15,'R');
    r.Insert(2,'R');
    r.Insert(7,'B');
    r.Insert(1,'B');
    r.Insert(5,'R');
    r.Insert(8,'R');
    r.Insert(4,'R');
    r.visualizeTree(r.root,3);

}