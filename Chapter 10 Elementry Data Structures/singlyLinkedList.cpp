#include <iostream>

using namespace std;

class Node {
    public:
        int data; //store the data of node in the list
        Node *next; //store the address of next node in the list
        /*The pointer next type of node beacuse it will store the address of next node of type Node 
        like Int pointer store int address
        char pointer store char address
        */
        Node(int data) {
            this->data = data;// defrence of pointer and store the value of 10 in node1
            this->next = NULL;// defrence of pointer and store the value of NULL in node1
        }
        ~Node() {
            
            delete next;
            this->next=NULL;
        }


};

void insertAtHead(Node *&head,int d)
{
    //new node ceate
    Node *temp = new Node(d);
    temp->next = head; // same temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail,int d)
{
    //new node ceate
    Node *temp = new Node(d);
    tail->next=temp;//same tail->next=temp->next;
    tail=temp;//tail->next 
    
}
void insertAtMiddle(Node *&head,Node *&tail,int positon,int d)
{
    //new node ceate
    Node *temp = new Node(d);
    if(positon==0)
    {
        insertAtHead(head,d);
    }
    else if(positon>long(head))
    {
        insertAttail(tail,d);
    }
    else
    {
        Node *temp1=head;
        cout<<"Position"<<positon<<endl;
        for(int i=0;i<positon-1;i++)
        {
            temp1=temp1->next;
            cout<<"temp1 data "<<temp1->data<<endl;

        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
}
void deleteNode(Node *&head,int poistion)
{
    if(poistion==1)
    {
        Node* temp=head;
        head=head->next;
        //free memory
        temp->next=NULL;
        delete temp;
    }
    else{
        Node *curr=head;
        Node *prev=NULL;
        int count=1;
        while(count<poistion)
        {
            prev=curr;/*In case 1: the prev and curr will be same
                    In case 2: the prev will link the node to after the delete node like 1,2,3
                    we want to delete the 2 then prev will link 1 to 3*/
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node *&head)
{

    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;  
    }
    cout<<endl;
}


int main()
{
    //Node *node1=new Node(10);  
    // cout<< node1->data << endl; // defrence the node1 and display the data of node1 # cout<< (*node1).data<<endl;
    // cout<< node1->next << endl; // defrence the node1 and display the address of next node of node1
    //head pointed to node1
    //Node *head = node1;
    // // //insert at head
    // insertAtHead(head,12);
    // insertAtHead(head,15);
    // print(head);
    //New LinkedList
    Node *node2=new Node(10);  
    Node *head2= node2;
    Node *tail = node2;
    //insert at tail
    insertAttail(tail,12);
    insertAttail(tail,15);
    insertAtMiddle(head2,tail,3,20);
   
    deleteNode(head2,1);
    print(head2);
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
