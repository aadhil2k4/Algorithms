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

pair<int,int> solve(node* root){
    if(root==NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftAns = solve(root->left);
    pair<int,int> rightAns = solve(root->right);
    pair<int,int>res;
    res.first = root->data + leftAns.first + rightAns.first;
    res.second = max(leftAns.second,leftAns.first) + max(rightAns.first, rightAns.second);
    return res;
}

int getMaxSum(node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}


int main(){
    node* root = NULL;
    root = buildtree(root);
    cout << "Max Sum: " <<endl;
    int ans;
    ans = getMaxSum(root);
    cout << ans << endl;
    return 0;
}