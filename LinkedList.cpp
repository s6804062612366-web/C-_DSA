#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertLast(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfterPos(Node*& head, int pos, int val) {
    if (!head) return;
    Node* temp = head;
    int count = 1;
    while (temp && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp) {
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteVal(Node*& head, int val) {
    if (!head) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << (temp->next ? " " : "");
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = nullptr;
    char cmd;

    while (cin >> cmd && cmd != '0') {
        if (cmd == 'A') {
            int val;
            cin >> val;
            insertLast(head, val);
        } else if (cmd == 'I') {
            int pos, val;
            cin >> pos >> val;
            insertAfterPos(head, pos, val);
        } else if (cmd == 'D') {
            int val;
            cin >> val;
            deleteVal(head, val);
        } else if (cmd == 'P') {
            printList(head);
        }
    }

    return 0;
}
