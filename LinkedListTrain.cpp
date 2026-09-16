#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n == 0) {
        cout << "EMPTY\n";
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* curr = head;
    while (curr) {
        if (curr->data % 2 == 0) {
            if (!evenHead) {
                evenHead = curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (!oddHead) {
                oddHead = curr;
                oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }

    if (evenTail) evenTail->next = oddHead;
    if (oddTail) oddTail->next = nullptr;

    Node* newHead = evenHead ? evenHead : oddHead;

    curr = newHead;
    while (curr) {
        cout << curr->data << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << "\n";

    return 0;
}
