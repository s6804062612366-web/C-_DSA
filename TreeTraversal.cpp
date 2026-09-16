#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(Node* node, vector<int>& res) {
    if (!node) return;
    res.push_back(node->data);
    preorder(node->left, res);
    preorder(node->right, res);
}

void inorder(Node* node, vector<int>& res) {
    if (!node) return;
    inorder(node->left, res);
    res.push_back(node->data);
    inorder(node->right, res);
}

void postorder(Node* node, vector<int>& res) {
    if (!node) return;
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->data);
}

void printTraversal(const vector<int>& res) {
    if (res.empty()) {
        cout << "EMPTY\n";
        return;
    }
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    int K;
    if (!(cin >> K)) return 0;
    
    vector<int> arr(K);
    for (int i = 0; i < K; ++i) {
        cin >> arr[i];
    }
    
    Node* root = nullptr;
    if (K > 0 && arr[0] != -1) {
        root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int idx = 1;
        
        while (!q.empty() && idx < K) {
            Node* curr = q.front();
            q.pop();
            
            if (idx < K) {
                if (arr[idx] != -1) {
                    curr->left = new Node(arr[idx]);
                    q.push(curr->left);
                }
                idx++;
            }
            
            if (idx < K) {
                if (arr[idx] != -1) {
                    curr->right = new Node(arr[idx]);
                    q.push(curr->right);
                }
                idx++;
            }
        }
    }
    
    int Q;
    if (!(cin >> Q)) return 0;
    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;
        vector<int> res;
        
        if (root == nullptr) {
            cout << "EMPTY\n";
            continue;
        }
        
        if (query == "preorder") preorder(root, res);
        else if (query == "inorder") inorder(root, res);
        else if (query == "postorder") postorder(root, res);
        
        printTraversal(res);
    }
    
    return 0;
}
