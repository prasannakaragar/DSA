#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

class Queue{
Node* head;
Node* tail;
public:
Queue(){
    head=tail=NULL;
}

void push(int val){
    Node* newNode= new Node(val);
    if(head==NULL){
        head=tail=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    }

}
void pop(){
    if(empty()){
        cout<<"Queue is empty "<<endl;
        return ;
    }
Node* temp=head;

head=head->next;
delete temp;
}

int  front(){
    if(empty()){
        cout<<"Queue is empty "<<endl;
        return -1;
    }
return head->data;
}
bool empty(){
 return head==NULL;
}
};
class Queuer{
int* arr;
int capacity;
int currSize;

int f,r;
public:
Queuer(int capacity){
    this->capacity=capacity;
    arr=new int[capacity];
    currSize=0;
    r=-1;
    f=0;
}

void pop(){
    if(empty()){
        cout<<"Queue is Empty: "<<endl;
        return ;
    }
    f=(f+1)%capacity;
    currSize--;
}

void push(int data){
    if(currSize==capacity){
        cout<<"Queue is Not empty: "<<endl;
    }
    r=(r+1)%capacity;
    arr[r]=data;
    currSize++;
}
int front(){
if(empty()){
    cout<<"Queue is Empty"<<endl;
    return -1;
}
return arr[f];
}
bool empty(){
return currSize==0;
}



};

int main(){
Queuer q(4);


q.push(1);
q.push(2);
q.push(3);
q.push(4);

cout<<q.front()<<endl;
q.pop();
cout<<q.front()<<endl;


  return 0;
}