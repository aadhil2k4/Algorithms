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

void solve(node* root, int sum, int&maxSum, int len, int maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len==maxLen){
            maxSum = max(maxSum,sum);
        }
        return;
    }
    sum = sum+root->data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongestPath(node* root){
    int len=0;
    int maxLen=0;
    int sum=0;
    int maxSum=0;
    solve(root, sum, maxSum, len,maxLen);
    return maxSum;
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    cout << "Left View: " <<endl;
    int ans;
    ans = sumOfLongestPath(root);
    cout << ans;
    return 0;
}