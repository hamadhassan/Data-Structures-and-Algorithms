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
    }
    void displayList(){
        Node *p=head;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
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
    Node* reverseList(){
        Node *p=head;
        Node *q=NULL;
        Node *r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
            q->prev=p;
        }
        head=q;
        return head;
    }
    Node* sortList(Node *list){
        Node *p=list;
        Node *q=NULL;
        Node *r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        list=q;
        return list;
    }
    Node* removeDuplicates(Node* list){
        Node *p=list;
        Node *q=NULL;
        while(p!=NULL){
            q=p->next;
            while(q!=NULL && q->data==p->data){
                q=q->next;
            }
            p->next=q;
            p=q;
        }
        return list;
    }
    Node* mergeList(Node *list1,Node *list2){
        Node *p=list1;
        Node *q=list2;
        Node *r=NULL;
        Node *s=NULL;
        if(p->data<q->data){
            r=p;
            s=p;
            p=p->next;
            s->next=NULL;
        }
        else{
            r=q;
            s=q;
            q=q->next;
            s->next=NULL;
        }
        while(p!=NULL && q!=NULL){
            if(p->data<q->data){
                s->next=p;
                p->prev=s;
                s=p;
                p=p->next;
                s->next=NULL;
            }
            else{
                s->next=q;
                q->prev=s;
                s=q;
                q=q->next;
                s->next=NULL;
            }
        }
        if(p!=NULL){
            s->next=p;
            p->prev=s;
        }
        if(q!=NULL){
            s->next=q;
            q->prev=s;
        }
        return r;
    }
    Node* interestLists(Node* list1, Node* list2){
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
                    s=p;
                    p=p->next;
                    q=q->next;
                    s->next=NULL;
                }
                else{
                    s->next=p;
                    p->prev=s;
                    s=p;
                    p=p->next;
                    q=q->next;
                    s->next=NULL;
                }
            }
        }
        return r;
    }
};
int main(){
    DoublyLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.displayList();
}
