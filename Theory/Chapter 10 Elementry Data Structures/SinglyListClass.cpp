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
    public:
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
    void insertAtMiddle(int data,int position){
        Node *temp=new Node(data);
        Node *p=head;
        for(int i=0;i<position-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
    void deleteAtHead(){
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    void deleteAtTail(){
        Node *p=head;
        while(p->next->next!=NULL){
            p=p->next;
        }
        Node *temp=p->next;
        p->next=NULL;
        delete temp;
    }
    void deleteAtMiddle(int position){
        Node *p=head;
        for(int i=0;i<position-1;i++){
            p=p->next;
        }
        Node *temp=p->next;
        p->next=p->next->next;
        delete temp;
    }
    void print(){
        Node *temp = this->head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    int length(){
        Node *p=this->head;
        int count=0;
        while(p!=NULL){
            count++;
            p=p->next;
        }
        return count;
    }
    void update(int data,int position){
        Node *p=head;
        for(int i=0;i<position;i++){
            p=p->next;
        }
        p->data=data;
    }
    void reverse(){
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
    }   
};
int main(){  
    LinkedList l;
    l.insertAtHead(10);
    l.insertAtHead(20);
    l.print();

    l.insertAtMiddle(40,1);
    l.print();

    l.update(30,2);
    l.print();

    l.insertAtTail(50);
    cout<<l.length()<<endl;
    
    l.deleteAtHead();
    l.print();

    l.reverse();
    l.print();

    l.deleteAtMiddle(1);
    l.print();

    l.deleteAtTail();
    l.print();
    return 0;
}