#include<iostream>
#include<vector>
using namespace std;

class SegmentTee{
 
int n;
vector<int>tree;
void buildTree(vector<int>&arr,int st,int end,int node){
        if(st==end){
            tree[node]=arr[st];
            return;
        }
        int mid=st+(end-st)/2;
        buildTree(arr,st,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int rangesum(int qi,int qj,int si,int sj,int node){
        if(qj<si || qi>sj){
            return 0;
        }
        if(si>=qi && sj<=qj){
            return tree[node];
        }
        int mid=si+(sj-si)/2;

        return (rangesum(qi,qj,si,mid,2*node+1) + rangesum(qi,qj,mid+1,sj,2*node+2));
    }
public:
    SegmentTee(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);
    }
    void printTree(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    int range(int qi,int qj){
        return rangesum(qi,qj,0,n-1,0);    
    }

};

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    SegmentTee ch(arr);
    
    
    cout<<ch.range(2,5)<<endl;

    return 0;
}