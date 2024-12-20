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

void solve(node* root, vector<int>&ans, int level){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(node* root){
    vector<int>ans;
    solve(root, ans,0);
    return ans;
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    cout << "Left View: " <<endl;
    vector<int>ans;
    ans = leftView(root);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}