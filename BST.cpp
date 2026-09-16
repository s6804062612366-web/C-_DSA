#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) {
        root->left = insertNode(root->left, v);
    } else if (v > root->val) {
        root->right = insertNode(root->right, v);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int v) {
    if (!root) return nullptr;
    if (v < root->val) {
        root->left = deleteNode(root->left, v);
    } else if (v > root->val) {
        root->right = deleteNode(root->right, v);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void printLevelOrder(Node* root) {
    if (!root) {
        cout << "EMPTY\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();
            cout << curr->val << (i == levelSize - 1 ? "" : " ");
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    Node* root = nullptr;

    while (Q--) {
        string cmd;
        int v;
        cin >> cmd >> v;

        if (cmd == "add") {
            root = insertNode(root, v);
        } else if (cmd == "remove") {
            root = deleteNode(root, v);
        }

        printLevelOrder(root);
    }

    return 0;
}
