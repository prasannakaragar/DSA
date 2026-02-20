#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;
Node(int data){
    this->data=data;
    left=right=NULL;
}
};
static int idx=-1;

Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]== -1){
        return NULL;
    }
    Node* currNode= new Node(nodes[idx]);
     currNode->left=buildTree(nodes);
     currNode->right=buildTree(nodes);

     return currNode;
};

void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* curr=Q.front();
        Q.pop();
        if(curr==NULL){
            cout<<endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);
        }else{
            cout<<curr->data<<" ";
        if(curr->left!=NULL){
            Q.push(curr->left);
        }
        if(curr->right!=NULL){
            Q.push(curr->right);
        }
        
        }
        
        

    }
  

}
int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int lefthig=height(root->left);
    int righthig=height(root->right);

    return max(lefthig,righthig)+1;
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }

    int rightc=count(root->right);
    int leftc=count(root->left);

    return (rightc+leftc+1);
}
int sumNode(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftc=sumNode(root->left);
    int rightc=sumNode(root->right);
    

    return leftc+rightc+root->data;

}
int diameter(Node* root){
    if(root==NULL){
        return 0;
        
        int currdia=height(root->left)+height(root->right);
        int leftd=diameter(root->left);
        int rightd=diameter(root->right);

        return max(currdia,max(leftd,rightd));
    }
}
pair<int,int>dia2(Node* root){

    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int>leftInfo=dia2(root->left);
    pair<int,int>rightInfo=dia2(root->right);
    
    int currdia=leftInfo.second+rightInfo.second+1;
    int fdia=max(currdia,max(leftInfo.first,rightInfo.first));
    int fhig=max(leftInfo.second,rightInfo.second)+1;
    return make_pair(fdia,fhig);
}
bool isIdentical(Node* root1,Node* root2){
  if(root1==NULL && root2==NULL){
    return true;
  }else if(root1==NULL || root2==NULL){
    return false;
  }
  if(root1->data!=root2->data){
      return false;
  }

  return isIdentical(root1->left,root2->left) 
        && isIdentical(root1->right,root2->right);

}

bool subRoot(Node* root,Node* subroot){

    if(root==NULL && subroot==NULL){
        return true;
    }else if(root==NULL || subroot==NULL){
        return false;
    }

    if(root->data == subroot->data){
        if( isIdentical(root,subroot)){
            return true;
        }
    }

    int issubroot=subRoot(root->left,subroot);

    if(!issubroot){
       return subRoot(root->right,subroot);
        
    }

   return true;
}
void topView(Node* root){
    queue<pair<Node*,int>>Q;
    map<int,int>m;
    Q.push(make_pair(root,0));
    while(!Q.empty()){
        pair<Node*,int>curr=Q.front();
        Q.pop();
        Node* currNode=curr.first;
        int currHD=curr.second;
        if(m.count(currHD)==0){
            m[currHD]=currNode->data;
        }
        if(currNode->left!=NULL){
            pair<Node*,int>left=make_pair(currNode->left,currHD-1);
            Q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int>right=make_pair(currNode->right,currHD+1);
            Q.push(right);
        }
    }

    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;

}
void bottomView(Node* root){
    queue<pair<Node*,int>>Q;
    map<int,int>m;
    Q.push(make_pair(root,0));
    while(!Q.empty()){
        pair<Node*,int>curr=Q.front();
        Q.pop();
        Node* currNode=curr.first;
        int currHD=curr.second;
        
            m[currHD]=currNode->data;
        
        if(currNode->left!=NULL){
            pair<Node*,int>left=make_pair(currNode->left,currHD-1);
            Q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int>right=make_pair(currNode->right,currHD+1);
            Q.push(right);
        }
    }

    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;

}
void kthHelper(Node* root,int K,int currlevel){
 if(root==NULL){
    return ;
 }
 if(currlevel==K){
    cout<<root->data<<" ";
 }
 kthHelper(root->left,K,currlevel+1);
 kthHelper(root->right,K,currlevel+1);

}
void kthLevel(Node* root,int K){
 kthHelper(root,K,1);

}

  


bool roottoNode(Node* root,int n,vector<int>& path){
   if(root==NULL){
    return false;
   }
   path.push_back(root->data);
   if(root->data==n){
    return true;
   }
   int isLeft=roottoNode(root->left,n,path);
   int isRight=roottoNode(root->right,n,path);
   if(isLeft||isRight){
    return true;
   }
   path.pop_back();
   return false;

}

int LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;

    roottoNode(root,n1,path1);
    roottoNode(root,n2,path2);
   int idx=-1;
   for(int i=0,j=0; i<path1.size() && j<path2.size();i++,j++){
    if(path1[i]!=path2[j]){
        return idx;
    }
    idx=path1[i];
   }

    return -1;
}
Node* LCA2(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* left=LCA2(root->left,n1,n2);
    Node* right=LCA2(root->right,n1,n2);
    
    if(left!=NULL && right!=NULL){
        return root;
    }
    return left==NULL? right:left;
      
}
int hig(Node* root,int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftDist=hig(root->left,n);
     

    if(leftDist!=-1){
        return leftDist+1;
    }
    int rightDist=hig(root->right,n);
    if(rightDist!=-1){
        return rightDist+1;
    }

return -1;
    
}

int mindist(Node* root,int n1,int n2){

    Node* lca=LCA2(root,n1,n2);

    int dist1=hig(lca,n1);
    int dist2=hig(lca,n2);
    return dist1+dist2;
}


int kthAncestor(Node* root,int node,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return 0;
    }
    int leftDist=kthAncestor(root->left,node,k);
    int rightDist=kthAncestor(root->right,node,k);
    if(leftDist==-1 && rightDist==-1){
        return -1;
    }

    int vaildVal= leftDist==-1 ? rightDist:leftDist;
    if(vaildVal+1==k){
        cout<<"Kth ancestor is :"<<root->data<<endl;
    }
 return vaildVal+1;

}
int transform(Node* root){

    if(root==NULL){
        return 0;
    }
    
    int leftold=transform(root->left);
    int rightold=transform(root->right);
    int currold=root->data;

    root->data=leftold+rightold;
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    return currold;
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
   
    return 0;
}