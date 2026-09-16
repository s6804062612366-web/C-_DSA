#include <iostream>
#include <string>

using namespace std;

struct Node {
    string text;
    Node* prev;
    Node* next;
    Node(string t) : text(t), prev(nullptr), next(nullptr) {}
};

void clearFuture(Node* curr) {
    Node* temp = curr->next;
    while (temp != nullptr) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    curr->next = nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = new Node("");
    Node* curr = head;
    string input;

    while (cin >> input) {
        if (input == "END") {
            break;
        } else if (input == "<<") {
            if (curr != head) {
                curr = curr->prev;
            }
        } else if (input == ">>") {
            if (curr->next != nullptr) {
                curr = curr->next;
            }
        } else {
            clearFuture(curr);
            Node* newNode = new Node(input);
            curr->next = newNode;
            newNode->prev = curr;
            curr = newNode;
        }
    }

    Node* temp = head->next;
    while (temp != nullptr && temp != curr->next) {
        cout << temp->text << "\n";
        temp = temp->next;
    }

    return 0;
}
