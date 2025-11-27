// 3. Write a program to find the middle of a linked list. 
// Input: 1->2->3->4->5 
// Output: 3



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
void display(){
    node* p=head;
    while(p!=nullptr){
        cout<<p->data;
        if(p->next) cout<<"->";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    int a[]={1,2,1,2,1,3,1};
    for(int i=0;i<7;i++) insert(a[i]);
    int key=1,c=0;
    node* p=head;
    node* prev=nullptr;
    while(p!=nullptr){
        if(p->data==key){
            c++;
            if(p==head){
                head=head->next;
                delete p;
                p=head;
            }
            else{
                prev->next=p->next;
                delete p;
                p=prev->next;
            }
        }
        else{
            prev=p;
            p=p->next;
        }
    }
    cout<<"Count: "<<c<<" , Updated Linked List: ";
    display();
}
