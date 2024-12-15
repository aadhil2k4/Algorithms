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

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp= q.front();
        q.pop();
        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node* root){   //LNR
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node* root){  //NLR
    if(root==NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){ //LRN
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << "Inorder traversal: " << endl;
    inOrder(root);
    cout << "Preorder traversal: " << endl;
    preOrder(root);
    cout << "Postorder traversal: " << endl;
    postOrder(root);
    return 0;
}