#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next = NULL;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        delete next;
        this->next=NULL;
    }

};
class LinkedList{
    private:
        Node *head;

        ~LinkedList(){
        delete head;
        head=NULL;
    }
    public:
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    //Insert at Middle
    void insertNode(int data,int position){
        Node *temp=new Node(data);
        Node *p=head;
        for(int i=0;i<position-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
     void insertAtHead(int data){
        Node *temp=new Node(data);
        if(head!=NULL){
            temp->next=head;
        }
        head=temp;
    }
    void insertAtTail(int data){
        Node *temp=new Node(data);
        Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    bool findNode(int data){
        Node *p=head;
        while(p!=NULL){
            if(p->data==data){
                return true;
            }
            p=p->next;
        }
        return false;
    }
    bool deleteNode(int data){
        Node *p=head;
        Node *q=NULL;
        while(p!=NULL){
            if(p->data==data){
                if(p==head){
                    head=head->next;
                    delete p;
                    return true;
                }
                q->next=p->next;
                delete p;
                return true;
            }
            q=p;
            p=p->next;
        }
        return false;
    }
    bool deleteFromStart(){
        if(head==NULL){
            return false;
        }
        Node *temp=head;
        head=head->next;
        delete temp;
        return true;
    }
    bool deleteFromEnd(){
        if(head==NULL){
            return false;
        }
        Node *p=head;
        Node *q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        delete p;
        return true;
    }
    void displayList(){
        Node *p=head;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    Node* reverseList(){
        Node *p=head;
        Node *q=NULL;
        Node *r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    Node* sortList(){
        Node *p=head;
        Node *q=NULL;
        Node *r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    Node* removeDuplicates(Node *list){
        Node *p=list;
        Node *q=NULL;
        while(p!=NULL){
            q=p;
            p=p->next;
            if(q->data==p->data){
                q->next=p->next;
                delete p;
                p=q->next;
            }
        }
        return list;
    }
    Node* mergeLists(Node *list1,Node *list2){
        Node *p=list1;
        Node *q=list2;
        Node *r=NULL;
        Node *s=NULL;
        while(p!=NULL && q!=NULL){
            if(p->data<q->data){
                if(r==NULL){
                    r=p;
                    s=r;
                }
                else{
                    r->next=p;
                    r=r->next;
                }
                p=p->next;
            }
            else{
                if(r==NULL){
                    r=q;
                    s=r;
                }
                else{
                    r->next=q;
                    r=r->next;
                }
                q=q->next;
            }
        }
        if(p!=NULL){
            r->next=p;
        }
        if(q!=NULL){
            r->next=q;
        }
        return s;
    }
    Node* mergeLists(Node *list1, Node *list2){
        Node *p=list1;
        Node *q=list2;
        Node *r=NULL;
        Node *s=NULL;
        while(p!=NULL && q!=NULL){
            if(p->data<q->data){
                if(r==NULL){
                    r=p;
                    s=r;
                }
                else{
                    r->next=p;
                    r=r->next;
                }
                p=p->next;
            }
            else{
                if(r==NULL){
                    r=q;
                    s=r;
                }
                else{
                    r->next=q;
                    r=r->next;
                }
                q=q->next;
            }
        }
        if(p!=NULL){
            r->next=p;
        }
        if(q!=NULL){
            r->next=q;
        }
        return s;
    }
    Node* interestLists(Node *list1, Node *list2){
        Node *p=list1;
        Node *q=list2;
        Node *r=NULL;
        Node *s=NULL;
        while(p!=NULL && q!=NULL){
            if(p->data<q->data){
                p=p->next;
            }
            else if(p->data>q->data){
                q=q->next;
            }
            else{
                if(r==NULL){
                    r=p;
                    s=r;
                }
                else{
                    r->next=p;
                    r=r->next;
                }
                p=p->next;
                q=q->next;
            }
        }
        return s;
    }
};