#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

#define Node struct Node

Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head=NULL;
Node *tail=NULL;

void insertBegin(int val){
    Node * newNode = (Node*) malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAfterNode(int val, int position){
    Node * newNode = (Node*) malloc(sizeof(Node));
    Node * back = head;
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    if(position==0){
        insertBegin(val);
        return;
    }
    while(position>0 && back->next!=NULL){
        back = back->next;
        position--;
    }
    if(back==NULL){
        cout<<"Invalid Position\n";
        return;
    }Node *frnt = back->next;
    
    newNode->next = frnt;
    frnt->prev = newNode;
    back->next = newNode;
    newNode->prev = back; 
}

void insertEnd(int val){
    Node * newNode = (Node*) malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int deleteBegin(){
    if(head==NULL){
        cout<<"List is empty.\n";
        return -1;
    }
    int val = head->data;
    Node *temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    free(temp);
    return val;
}

int deleteEnd(){
    if(tail==NULL){
        cout<<"List is empty.\n";
        return -1;
    }
    int val = tail->data;
    Node *temp = tail;
    tail = tail->prev;
    if(tail != NULL) tail->next = NULL;
    free(temp);
    return val;
}

int deleteAfterNode(int position){
    Node *back = head;
    while (position>0 && back!=NULL)
    {
        back = back->next;
        position--;
    }
    if(back==NULL){
        cout<<"Invalid Position\n";
        return -1;
    }
    Node * temp = back->next;
    Node * frnt = temp->next;

    int val = temp->data;

    back->next = frnt;
    if(frnt != NULL) frnt->prev = back;

    free(temp);
    return val;
}

int main()
{
    for(int i=1; i<=5; i++){
        insertBegin(i);
    }
    Node * trav = head;
    while (trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav=trav->next;
    }cout<<endl;
    for(int i=7, j=2; i<=8; i++, j=j+2){
        insertAfterNode(i,j);
    }
    trav = head;
    while (trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav=trav->next;
    }cout<<endl;
    return 0;
}