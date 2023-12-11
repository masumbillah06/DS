#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define all(x) x.begin(), x.end()
typedef vector<int>  vi;
typedef vector<bool> vb;
typedef vector<vi>  vvi;

#define Node struct Node

Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head=NULL;
Node *tail=NULL;
int ct=0;

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
    ct++;
}

int dequeue(){
    if(head==NULL) {
        cout<<"Queue is empty\n";
        return -1;
    }
    int val = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    ct--;
    return val;
}

int main()
{
    for(int i=1; i<=5; i++){
        insertEnd(i);
    }

    Node * trav = head;
    while (trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav=trav->next;
    }cout<<endl;

    int value = dequeue();
    cout << value << endl;

    trav = head;
    while (trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav=trav->next;
    }
    return 0;
}