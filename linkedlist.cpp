#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;


Node(int val){
    data=val;
    next=NULL;
}
// ~Node(){
//     cout<<"~ is activeted and deleting ..."<<data<<endl;
//     if(next!=NULL){
//         delete next;
//         next=NULL;
//     }
// }
};
class List{
public:
    Node* head;
    Node* tail;

     List(){
        head=NULL;
        tail=NULL;
    }
    // ~List(){
    //     cout<<"~ is activited for list and deleting "<<endl;
    //     if(head!=NULL){
    //         delete head;
    //         head=NULL;
    //     }
    // }

    void push_back(int val){

    Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void push_front(int val){
     Node* newNode= new Node(val);
     if(head==NULL){
          head=tail=newNode;
     }else{
         newNode->next=head;
         head=newNode;
        }
    }
    void insertval(int val ,int pos){
        Node* curr=head;
        int count=0;

        while(count<pos-1){
            count++;
            if(curr==NULL){
                cout<<"invalid position"<<endl;
                return;
            }
            curr=curr->next;
        }
        Node* newNode= new Node(val);
        newNode->next=curr->next;
        curr->next=newNode;
    
    }
    void pop_front(){
        if(head!=NULL){
            Node* currNode=head;
            head=head->next;
            delete currNode;
        }else{
            cout<<"No linkedlist"<<endl;
        }
    }
    void pop_back(){
        Node* currNode=head;
        while(currNode->next!=tail){
            currNode=currNode->next;
        }
        Node* last=tail;
        tail=currNode;
        delete last;
        tail->next=NULL;
    }
    
    void printList(){
        Node* currNode=head;
        while(currNode!=NULL){
            cout<<currNode->data<<"->";
            currNode=currNode->next;
        }
        cout<<"NULL"<<endl;
    }
    bool searchKey(int val){
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==val){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }
    int  helprecrusive(Node* root,int val){
       if(root==NULL){
        return -1;
       }
       if(root->data==val){
        return 0;
       }
       return helprecrusive(root->next,val) +1;
    }
    int recrusive(int val){
        Node* currNode=head;

     return helprecrusive(currNode,val);

    }
    void reversll(){
        Node* prev=NULL;
        Node* curr=head;
        

        
        while(curr!=NULL){
           Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        head=prev;
    }
    void removeNthNode(int n){

        Node* curr=head;
        int size=0;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        Node* prev=head;
        for(int i=1;i<size-n;i++){
            prev=prev->next;
        }
        Node* del=prev->next;
        cout<<"Going to delet is: "<<del->data<<endl;
        prev->next=prev->next->next;
    }
    void removecycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        bool iscycle=false;
        while(fast!=NULL && fast->next!=NULL){
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast){
                iscycle=true;
                cout<<"Cycle exist..";
                break;
            }
        }
            if(!iscycle){
             cout<<"cycle does not exist"<<endl;
            }
            slow=head;
        
            if(slow==fast){
                while(fast->next!=slow){
                    fast=fast->next;
                }
                fast->next=NULL;
            }else{
                Node* prev=fast;
                while(slow!=fast){
                
                slow=slow->next;
                prev=fast;
                fast=fast->next;
                }
                prev->next=NULL;
        }
    }
    
    
};
Node* merge(Node* left,Node* right){
        List ans;
       Node* i=left;
       Node* j=right;

       while(i!=NULL && j!=NULL){
        if(i->data<j->data){
         ans.push_back(i->data);
         i=i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }
       }
       while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
       }
       while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
       }

      return ans.head;
    }



    Node* splitAtmid(Node* head){
      Node* curr=head;
      Node* fast=head;
      Node* prev=NULL;

      while(fast!=NULL && fast->next!=NULL){
        prev=curr;
        curr=curr->next;
        fast=fast->next->next;
      }
      if(prev!=NULL){
      prev->next=NULL;
      }
      return curr;
    
    }

    Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* righthead=splitAtmid(head);
        Node* left=mergeSort(head);
        Node* right=mergeSort(righthead);
        return merge(left,right);
    }



int main(){
  List ll;
  ll.push_front(7);
  ll.push_front(6);
  ll.push_front(5);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList();
  ll.insertval(4,3);
  ll.printList();
  ll.head=mergeSort(ll.head);
  


    return 0;
}