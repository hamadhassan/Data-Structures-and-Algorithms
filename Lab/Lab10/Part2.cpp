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
void menu(){
    int choice=0;
    cout<<"1. Insert"<<endl;
    cout<<"2. Search"<<endl;
    cout<<"3. Print Inorder"<<endl;
    cout<<"4. Print Preorder"<<endl;
    cout<<"5. Print Postorder"<<endl;
    cout<<"6. Visualize Tree"<<endl;
    cout<<"7. Number of Nodes"<<endl;
    cout<<"8. Height of Tree"<<endl;
    cout<<"9. Leaf Node"<<endl;
    cout<<"10. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    BST b;
    if(choice==1){
        int data;
        cout<<"Enter the data: ";
        cin>>data;
      
        b.Insert(data);
        menu();
    }
    else if(choice==2){
        int data;
        cout<<"Enter the data: ";
        cin>>data;
        Node* x=b.search(b.getTree(),data);
        if(x!=NULL){
            cout<<"Data found"<<endl;
        }
        else{
            cout<<"Data not found"<<endl;
        }
        menu();
    }
    else if(choice==3){
        b.printInorder(b.getTree());
        menu();
    }
    else if(choice==4){
        b.printPreorder(b.getTree());
        menu();
    }
    else if(choice==5){
        b.printPostorder(b.getTree());
        menu();
    }
    else if(choice==6){
        b.visualizeTree(b.getTree(),0);
        menu();
    }
    else if(choice==7){
        cout<<"Number of Nodes: "<<b.NumberofNode()<<endl;
        menu();
    }
    else if(choice==8){
        cout<<"Height of Tree: "<<b.height(b.getTree())<<endl;
        menu();
    }
    else if(choice==9){
        b.leafNode(b.getTree());
        menu();
    }
    else if(choice==10){
        exit(0);
    }
    else{
        cout<<"Invalid choice"<<endl;
        menu();
    }
}
int main(){ 
    BST b;
    b.Insert(5);
    b.Insert(3);
    b.Insert(7);
    b.Insert(4);
    b.Insert(6);
    b.leafNode(b.Root);
    b.visualizeTree(b.Root,20);
}