#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node* arr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"x";
}
Node* reverse(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* reverseBetween(Node* head, int l, int r)
{
    Node* dNode=new Node(-1);
    dNode->next=head;
    Node* left=dNode;
    Node* right=dNode;
    Node* prev=dNode;
    Node* front;
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    if(l==r)return head;
    for(int i=1;i<l;i++)
    {
        prev=prev->next;
    }
    left=prev->next;
    for(int j=1;j<r;j++)
    {
        right=right->next;
    }
    front=right->next;
    right->next=NULL;
    reverse(left);
    prev->next=right;
    left->next=front;

    return head;
}

int main()
{
    vector<int> arr={3,5};
    Node* head=arr2LL(arr);
    head=reverseBetween(head,1,2);
    print(head);
}