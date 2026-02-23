#include<iostream>
#include<string>
using namespace std;

class Node{
public:
string key;
int val;
Node* next;

Node(string key,int val){
    this->key=key;
    this->val=val;
    next=NULL;
}
~Node(){
    if(next!=NULL){
        delete next;
    }
}
};
class Hash{
    int totalSz;
    int currSz;
    Node** table;

    int hashFunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx=idx+(key[i]*key[i])%totalSz;
        }
        return idx%totalSz;
    }
    void rehash(){
        Node** oldtable=table;
        int oldSz=totalSz;
        totalSz=totalSz*2;
        currSz=0;
        Node** table=new Node*[totalSz];
        for(int i=0;i<totalSz;i++){
            table[i]=NULL;
        }
        //copying old table into new Table;
        for(int i=0;i<oldSz;i++){
            Node* temp=oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }
public: 

  Hash(int size){
    totalSz=size;
    currSz=0;
    table= new Node*[totalSz];

    for(int i=0;i<size;i++){
        table[i]=NULL;
    }
  }

  void insert(string key,int val){
       int idx=hashFunction(key);
       Node* newNode= new Node(key,val);
       newNode->next=table[idx];
       table[idx]=newNode;
       currSz++;
       double lamda = currSz/(double)totalSz;
       if(lamda>1){
           rehash();
        }
    }
    bool exist(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    int search(string key){
        int idx=hashFunction(key);
        Node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
    void print(){
       
        for(int i=0;i<totalSz;i++){
        Node* temp=table[i];
        while(temp!=NULL){
            cout<<"("<<temp->key<<","<<temp->val<<")";
            temp=temp->next;
        }
        cout<<endl;
        }
        
    }
    void remove(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        Node* prev=temp;

        while(temp!=NULL){
            if(temp->key==key){
                if(temp==prev){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }

};


int main(){
    
Hash h(10);
h.insert("india",150);
h.insert("pak",2);
h.insert("russia",10);
h.insert("pair",33);
h.insert("qw",88);
h.insert("irir",8);
h.insert("jksdfj",12);
h.print();

//cout<<"india population is :"<<h.search("india")<<endl;

    return 0;
}