#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    if (!getline(cin, input)) return 0;

    stack<char> s;
    bool valid = true;

    for (char c : input) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty()) {
                valid = false;
                break;
            }
            s.pop();
        }
    }

    if (!s.empty()) {
        valid = false;
    }

    if (valid) {
        cout << "Pass\n";
    } else {
        cout << "Error\n";
    }

    return 0;
}
