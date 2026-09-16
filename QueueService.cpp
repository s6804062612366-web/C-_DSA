#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    queue<int> q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "ARRIVE") {
            int x;
            cin >> x;
            q.push(x);
        } else if (cmd == "SERVE") {
            if (q.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (cmd == "FRONT") {
            if (q.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << q.front() << "\n";
            }
        }
    }

    return 0;
}
