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
    if(head == nullptr){
        head = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

void display(){
    node* temp = head;
    if (!temp) { cout << "(empty)"; return; }
    while(temp != nullptr){
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
}

int delete_all_occurrences(int key){
    int count = 0;
    while (head && head->data == key){
        node* t = head;
        head = head->next;
        delete t;
        ++count;
    }

    if (!head){
        last = nullptr;
        return count;
    }
    node* prev = head;
    node* cur  = head->next;
    while (cur){
        if (cur->data == key){
            node* t = cur;
            prev->next = cur->next;
            if (cur == last) last = prev; 
            cur = prev->next;
            delete t;
            count++;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }return count;
}
int main(){
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insert(x);
    int key = 1;
    int cnt = delete_all_occurrences(key);
    cout << "Count: " << cnt << " ,  Updated Linked List: ";
    display();
    cout << "\n";
    while (head){
        node* t = head;
        head = head->next;
        delete t;
    }
    last = nullptr;
}
