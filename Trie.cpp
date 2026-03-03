#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
public:
unordered_map<char,Node*>children;
bool endofword;

Node(){
    endofword=false;
}
};

class Trie{
Node*root;
public:
    Trie(){
       root=new Node();
    }

    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
          if(temp->children[key[i]]==0){
            temp->children[key[i]]=new Node();
          }
          temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }
    bool search(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endofword;
    }


};
bool helper(Trie & tire,string key){

    if(key.size()==0){
        return true;
    }
    for(int i=0;i<key.size();i++){
        string first=key.substr(0,i+1);
        string second=key.substr(i+1);

        if(tire.search(first) && helper(tire,second)){
            return true;
        }

    }
    return false;
}

bool wordBreak(vector<string>&dict,string key){
  Trie trie;
  for(int i=0;i<dict.size();i++){
    trie.insert(dict[i]);
    
  }    

  return helper(trie,key);
}

int main(){
    Trie ok;
    vector<string>words={"i","like","sam","samsung","moblie","ice"};
    cout<<wordBreak(words,"lik")<<endl;


    //cout<<ok.search("Prasanna");



    return 0;
}