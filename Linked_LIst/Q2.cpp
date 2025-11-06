// Write a program to count the number of occurrences of a given key in a singly linked 
// list and then delete all the occurrences.  
// Input: Linked List :  1->2->1->2->1->3->1 , key:  1                                                                    
// Output: Count: 4 ,  Updated Linked List: 2->2->3.



#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};

node* head = nullptr;
node* last = nullptr;

void insert(int e){
    node* temp = new node;
    temp->data = e;
    temp->next = nullptr;
    if(head == nullptr){head = temp; last = temp;}
    else{
        last->next = temp;
        last = temp;
    }
}

void display(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

    node* temp = head;
    if(N == head){
        head = N->next;
        delete(N);
        return;
    }
    while(temp->data != ){

    }
}

void delete_dup(int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key && temp == head){
            head = head->next;
            last = last->next;
            delete(temp);
        }else{
            last->next = temp->next;
            last = temp;
            temp = temp->next;
        }
    }
}


int main(){
insert(10);
insert(11);
insert(12);
insert(13);
display();
}