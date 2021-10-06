#include<bits/stdc++.h>
using namespace std;
//Contributer : Isha Bansal
struct Node{
    int val;
    int hd;
    Node*left,*right;
    Node(int v){
        val=v;
        left=right=NULL;
    }
};

void topView(Node*root){
    if(!root)return;
    int hd=0;
    root->hd=hd;
    queue<Node*>q;
    map<int ,int>m;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*temp=q.front();
            hd=temp->hd;
            if(m.find(hd)==m.end()){
                m[hd]=temp->val;
            }
            q.pop();
            if(temp->left){
                temp->left->hd=hd-1;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->hd=hd+1;
                q.push(temp->right);
            }
        }
    }
    map<int,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl;
}


void bottomView(Node*root){
    if(!root)return;
    int hd=0;
    root->hd=hd;
    queue<Node*>q;
    map<int ,int>m;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*temp=q.front();
            hd=temp->hd;

            m[hd]=temp->val;

            q.pop();
            if(temp->left){
                temp->left->hd=hd-1;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->hd=hd+1;
                q.push(temp->right);
            }
        }
    }
    map<int,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl;
}

void leftView(Node*root){
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*temp=q.front();
            q.pop();
            if(i==0){
                cout<<temp->val<<" ";
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

void rightView(Node*root){
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*temp=q.front();
            q.pop();
            if(i==n-1){
                cout<<temp->val<<" ";
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}


int main(){
    /*
            5
           / \
          7   9
         /\   /\
        1 2  4  3
                /
                6
    */
    Node*root=new Node(5);
    root->left=new Node(7);
    root->right=new Node(9);
    root->left->left=new Node(1);
    root->left->right=new Node(2);
    root->right->left=new Node(4);
    root->right->right=new Node(3);
    root->right->right->left=new Node(6);
    leftView(root);
    cout<<endl;
    rightView(root);
    cout<<endl;
    topView(root);
    bottomView(root);
    return 1;
}
