#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLeftView(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    int sum = 0;
    
    while(!q.empty()) {
        int n = q.size();
        
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();
            if(i == 0){
                cout << curr->data << " ";
                sum += curr->data;
            }
            
            if(curr->left != NULL){
                q.push(curr->left);
            }
            
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    
    cout << endl << sum;
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    printLeftView(root);

    return 0;
}
