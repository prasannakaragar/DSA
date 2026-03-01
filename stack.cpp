#include<iostream>
using namespace std;

//Implimantaion of stacks using linkelist 

template<class T>
class Node{
public:
T data;
Node* next;
Node(int val){
    data=val;
    next=NULL;
}
};
template<class T>
class stack{
public:
    Node<T>* head;


 stack(){
    head=NULL;
 }
     
    void push(T val){
        Node<T>* newNode=new Node<T>(val);

        if(head==NULL){
         head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void pop(){
        Node<T>* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void printLL(){
       Node<T>* temp=head;
       while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
       }
       cout<<"NULL"<<endl;
    }
    T top(){
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
};


int main(){
    stack<int>s1;
    s1.push(2);
    s1.push(6);
    s1.push(9);
    s1.push(6);
    s1.printLL();

    return 0;
}