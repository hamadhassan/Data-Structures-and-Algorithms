#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
        int size;
    public:
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void insertAtHead(int data){
        Node *temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }
    void insertAtTail(int data){
        Node *temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }
    void insertAtIthPosition(int data,int i){
        if(i<0 || i>size){
            return;
        }
        if(i==0){
            insertAtHead(data);
        }
        else if(i==size){
            insertAtTail(data);
        }
        else{
            Node *temp=new Node(data);
            Node *p=head;
            int count=0;
            while(count<i-1){
                p=p->next;
                count++;
            }
            temp->next=p->next;
            p->next->prev=temp;
            p->next=temp;
            temp->prev=p;
            size++;
        }
    }
    void deleteAtHead(){
        if(head==NULL){
            return;
        }
        else if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
            Node *temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
        size--;
    }
    void deleteAtTail(){
        if(head==NULL){
            return;
        }
        else if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
            Node *temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete temp;
        }
        size--;
    }
    void deleteAtIthPosition(int i){
        if(i<0 || i>=size){
            return;
        }
        if(i==0){
            deleteAtHead();
        }
        else if(i==size-1){
            deleteAtTail();
        }
        else{
            Node *p=head;
            int count=0;
            while(count<i-1){
                p=p->next;
                count++;
            }
            Node *temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            delete temp;
            size--;
        }
};
