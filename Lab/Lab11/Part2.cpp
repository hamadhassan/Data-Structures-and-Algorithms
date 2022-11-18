#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Node
{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
};
class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    };
    Node *getRoot()
    {
        return root;
    }
    Node *Insert_recursion(Node *root, int data)
    {
        if (root == NULL)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->left = temp->right = NULL;
            return temp;
        }
        if (data < root->data)
        {
            root->left = Insert_recursion(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = Insert_recursion(root->right, data);
        }
        return root;
    }
};
class goosetree
{
private:
    Node *root;

public:
    goosetree()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void goose_insert(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->left = temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            Node *current = root;
            Node *parent = NULL;
            while (true)
            {
                parent = current;
                if (data < current->data)
                {
                    current = current->left;
                    if (current == NULL)
                    {
                        parent->left = temp;
                        return;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == NULL)
                    {
                        parent->right = temp;
                        return;
                    }
                }
            }
        }
    }
    bool gooseDelete(int x)
    {
        Node *temp = gooseSearch(x);
        if (temp == NULL)
        {
            return false;
        }
        if (temp->left == NULL && temp->right == NULL)
        {
            if (temp->parent->left == temp)
            {
                temp->parent->left = NULL;
            }
            else
            {
                temp->parent->right = NULL;
            }
            delete temp;
            return true;
        }
        else if (temp->left == NULL)
        {
            if (temp->parent->left == temp)
            {
                temp->parent->left = temp->right;
            }
            else
            {
                temp->parent->right = temp->right;
            }
            delete temp;
            return true;
        }
        else if (temp->right == NULL)
        {
            if (temp->parent->left == temp)
            {
                temp->parent->left = temp->left;
            }
            else
            {
                temp->parent->right = temp->left;
            }
            delete temp;
            return true;
        }
        else
        {
            Node *temp2 = temp->right;
            while (temp2->left != NULL)
            {
                temp2 = temp2->left;
            }
            temp->data = temp2->data;
            if (temp2->parent->left == temp2)
            {
                temp2->parent->left = temp2->right;
            }
            else
            {
                temp2->parent->right = temp2->right;
            }
            delete temp2;
            return true;
        }
    } // delete a node with data

    Node *gooseSearch(int x)
    {
        Node *root;
        Node *temp = getRoot();
        while (temp != NULL)
        {
            if (x == temp->data)
            {
                return temp;
            }
            else if (x < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return NULL;
    }
    void visualizeTree(Node *T,int space){
        if(T==NULL){
            return;
        }
        space+=10;
        visualizeTree(T->right,space);
        cout<<endl;
        for(int i=10;i<space;i++){
            cout<<" ";
        }
        cout<<T->data<<endl;
        visualizeTree(T->left,space);
    }  
};
int main()
{
    goosetree check;
    check.goose_insert(5);
    check.goose_insert(3);
    check.goose_insert(7);
    check.goose_insert(12);
    check.visualizeTree(check.getRoot(),0);
    bool check1 = check.gooseDelete(5);
    if (check1 == true)
    {
        cout<<" Deletion is successful"<<endl;
    }
    else
    {
        cout << "Deletion failed " << endl;
    }
}