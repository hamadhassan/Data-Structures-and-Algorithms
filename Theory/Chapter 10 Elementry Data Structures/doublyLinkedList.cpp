#include <iostream>

using namespace std;

class Node {
    public:
        int data; //store the data of node in the list
        Node *next; //store the address of next node in the list
        Node *prev; //store the address of prev node in the list
        /*The pointer next type of node beacuse it will store the address of next node of type Node 
        like Int pointer store int address
        char pointer store char address
        */
        Node(int data) {
            this->data = data;// defrence of pointer and store the value of 10 in node1
            this->next = NULL;// defrence of pointer and store the value of NULL in node1
            this->prev = NULL;
        }
        ~Node() {
            
            delete next;
            this->next=NULL;
            this->prev=NULL;
        }


};

void print(Node *head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int getLength(Node *head)
{
    int len=0;
    while (head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
void insertAtHead(Node *&head,int d)
{
    if(head==NULL)
    {
        Node *temp=new Node(d);
        head=temp;
    }
    else
    {
        //new node ceate
        Node *temp = new Node(d);
        temp->next = head; 
        head->prev=temp;
        head=temp;
    }
   
}
void insertAtTail(Node *&tail,int d)
{
    //new node ceate
    Node *temp = new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtMiddle(Node *&head,Node *&tail,int position,int d)
{
    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
    
}
void deleteNode(int position, Node* & head) 
{ 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(20);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,10);
    insertAtTail(tail,30);
    //insertAtMiddle(head,tail,3,50);
     deleteNode(2, head);
    print(head);


}