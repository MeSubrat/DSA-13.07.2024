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

Node* mergeTwoLists(Node* h1, Node* h2)
{
    Node* dNode=new Node(-1);
    Node* res=dNode;
    Node* t1=h1;
    Node* t2=h2;
    // if(h1==nullptr && h2==nullptr)return nullptr;
    if(h1==NULL)return h2;
    else return h1; 
    while(t1 && t2)
    {
        if(t1->data==t2->data)
        {
            res->next=t1;
            t1=t1->next;
            res=res->next;
        }
        else if(t1->data<t2->data)
        {
            res->next=t1;
            t1=t1->next;
            res=res->next;
        }
        else{
            res->next=t2;
            t2=t2->next;
            res=res->next;
        }
        if(t1) res->next=t1;
        else res->next=t2;
    }
    return dNode->next;
}

int main()
{
    vector<int> arr1={1,2,3};
    vector<int> arr2={1,2,3};
    Node* head1=arr2LL(arr1);
    Node* head2=arr2LL(arr2);
    Node* head=mergeTwoLists(head1,head2);
    print(head);
}