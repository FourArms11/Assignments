// 4. Write a program to reverse a linked list. 
// Input: 1->2->3->4->NULL 
// Output: 4->3->2->1->NULL


#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
node* head=nullptr;
node* last=nullptr;
void insert(int x){
    node* t=new node;
    t->data=x;
    t->next=nullptr;
    if(head==nullptr){head=t;last=t;}
    else{last->next=t;last=t;}
}
void display(node* p){
    while(p!=nullptr){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}
node* reverse(node* h){
    node* prev=nullptr;
    node* curr=h;
    node* nxt=nullptr;
    while(curr!=nullptr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
int main(){
    int a[]={1,2,3,4};
    for(int i=0;i<4;i++) insert(a[i]);
    head=reverse(head);
    display(head);
}
