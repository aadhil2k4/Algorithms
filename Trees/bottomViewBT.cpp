#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root){
    cout << "Enter data: " <<endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data==-1){
        return NULL;
    }
    cout << "Enter for left: " << data <<endl;
    root->left = buildtree(root->left);
    cout << "Enter for right: " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

vector<int> bottomView(node* root){
    vector<int>ans;
    if(root==NULL)return ans;
    map<int,int>topNode;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*, int>temp = q.front();
        node* frontNode = temp.first;
        int hd = temp.second;
        topNode[hd] = frontNode->data;
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto a : topNode){
        ans.push_back(a.second);
    }
    return ans;
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    cout << "Bottom View: " <<endl;
    vector<int>ans;
    ans = bottomView(root);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}