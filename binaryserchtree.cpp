#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
};
Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(Node* root){
 if(root==NULL){
    return;
 }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
bool search(Node* root,int key){

    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data>key){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
Node* getInorderSearch(Node* root){
     while(root->left!=NULL){
        root=root->left;
     }
     return root;

}

Node* delNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left=delNode(root->left,val);
    }else if(val>root->data){
        root->right=delNode(root->right,val);
    }else{
       //root->data==val
       //root with 0 children
       if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
       }
       //root with 1 child
       if(root->left==NULL || root->right==NULL){
        return root->left==NULL ? root->right:root->left;
       }
       // root with 2 children
       Node* IS=getInorderSearch(root->right);

       root->data=IS->data;
       root->right=delNode(root->right,IS->data);
       return root;
    }
    return root;
}
void printInRange(Node* root,int start,int end){
    if(root==NULL){
        return;
    }

    if(root->data>=start && root->data<=end){
        cout<<root->data<<" ";
        printInRange(root->left,start,end);
        printInRange(root->right,start,end);
    }else if(root->data<start){
        printInRange(root->right,start,end);
    }else{
        printInRange(root->left,start,end);
    }
}
void printpath(vector<int>path){
for(int i=0;i<path.size();i++){
    cout<<path[i]<<" ";
}
cout<<endl;
}
void rootToleafhelp(Node* root,vector<int>& path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
  if(root->left==NULL && root->right==NULL){
    printpath(path);
    path.pop_back();
    return;
  }
  rootToleafhelp(root->left,path);
  rootToleafhelp(root->right,path);
  path.pop_back();
} 
void rootToLeaf(Node* root){
    vector<int>path;
    rootToleafhelp(root,path);
}
bool vaildHelp(Node* root,Node* min,Node* max){
if(root==NULL){
    return true;
}
if(min!=NULL && root->data<min->data){
    return false;
}
if(max!=NULL && root->data>max->data){
    return false;
}

return vaildHelp(root->left,min,root)
    && vaildHelp(root->right,root,max);
}
bool vaildBST(Node* root){
      return vaildHelp(root,NULL,NULL);
}
Node* buildBSTsorted(int arr[],int st,int ei){
    if(st>ei){
        return NULL;
    }
    int mid=st+(ei-st)/2;
    Node* curr=new Node(arr[mid]);
     
    curr->left=buildBSTsorted(arr,st,mid-1);
    curr->right=buildBSTsorted(arr,mid+1,ei);
    return curr;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
class Info{
public:
bool isBST;
int Max;
int Min;
int Sz;
 Info(bool isBST,int Max,int Min,int Sz){
    this->isBST=isBST;
    this->Max=Max;
    this->Min=Min;
    this->Sz=Sz;
 }
};
static int maxSize;
Info* largestBST(Node* root){
    if(root==NULL){
        return new Info(true,INT_MIN,INT_MAX,0);
    }
    Info* leftInfo=largestBST(root->left);
    Info* rightInfo=largestBST(root->right);
   
    int currMax=max(root->data,max(leftInfo->Max,rightInfo->Max));
    int currMin=min(root->data,min(leftInfo->Min,rightInfo->Min));
    int currSz=leftInfo->Sz+rightInfo->Sz+1;
    if(leftInfo->isBST && rightInfo->isBST && root->data>leftInfo->Max && root->data<rightInfo->Min){
        maxSize=max(maxSize,currSz);
        return new Info(true,currMax,currMin,currSz);
    }
    
    return new Info(false,currMax,currMin,currSz);

}

int main(){

Node* root=new Node(50);
root->left=new Node(30);
root->left->left=new Node(5);
root->left->right=new Node(20);

root->right=new Node(60);
root->right->left=new Node(45);
root->right->right=new Node(70);
root->right->right->left=new Node(65);
root->right->right->right=new Node(80);
largestBST(root);

cout<<"largestBST IS : "<<maxSize<<endl;

}