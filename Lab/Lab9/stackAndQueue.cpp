#include <iostream>
using namespace std;
//stack using linked list
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
class Stack{
    private:
        Node *head;
    public:
    Stack(){
        head=NULL;
    }
    void push(int data){
        Node *temp=new Node(data);
        if(head!=NULL){
            temp->next=head;
        }
        head=temp;
    }
    void pop(){
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    int top(){
        return head->data;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    void print(){
        Node *p=head;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
//stack using array
class StackArray{
    private:
        int *data;
        int nextIndex;
        int capacity;
    public:
    StackArray(int totalSize){
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int element){
        if(nextIndex==capacity){
            cout<<"Stack Full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return;
        }
        nextIndex--;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};
int main(){  
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    s.pop();
    s.print();
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
    StackArray s1(4);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.isEmpty()<<endl;
    cout<<s1.size()<<endl;
    return 0;
}