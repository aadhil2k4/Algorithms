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

node* solve(node* root, int&k, int n){
    if(root==NULL) return NULL;
    if(root->data==n) return root;
    node* leftAns = solve(root->left, k, n);
    node* rightAns = solve(root->right, k, n);
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
}

int kthAncestor(node* root, int k,int n){
    node* ans = solve(root, k, n);
    if(ans==NULL) return -1;
    else return ans->data;
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    int k;
    int n;
    cin >> k;
    cin >> n;
    cout << "Kth Ancestor: " <<endl;
    int ans;
    ans = kthAncestor(root,k, n);
    cout << ans;
    return 0;
}