#include<iostream>
#include<queue>

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

void traverseRight(node* root, vector<int>&ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)) return;
    if(root->right) traverseRight(root->right, ans);
    else traverseRight(root->left, ans);
    ans.push_back(root->data);
}

void traverseLeaf(node* root, vector<int>&ans){
    //Base Case
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseLeft(node* root, vector<int>&ans){
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left, ans);
    }else{
        traverseLeft(root->right, ans);
    }
}

vector<int> boundaryTraversal(node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);
    return ans;
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    cout << "Bounndary Traversal: " <<endl;
    vector<int>ans;
    ans = boundaryTraversal(root);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}