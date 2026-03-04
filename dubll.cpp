#include<iostream>
#//include<list>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        prev=next=NULL;
    }

};

class DoublyList{
public:
Node* head;
Node* tail;
DoublyList(){
    head=tail=NULL;
}


void push_front(int val){
 Node* newNode= new Node(val);
    if(head==NULL){
        head=tail=newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void pop_front(){
    Node* temp=head;
    if(temp==NULL){
        cout<<"List is empty"<<endl;
    }
    head=head->next;
    temp->next=NULL;
    delete temp;
}


void printList(){
    Node*curr=head;
    while(curr!=NULL){
        cout<<curr->data<<"<=>";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

};




int main(){
DoublyList dll;
dll.push_front(1);
dll.push_front(2);
dll.push_front(3);
dll.push_front(4);
dll.printList();
dll.pop_front();
dll.printList();
    return 0;
}
