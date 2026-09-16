#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> st;
    char cmd;

    while (cin >> cmd && cmd != 'X') {
        if (cmd == 'U') {
            int val;
            cin >> val;
            st.push_back(val);
        } else if (cmd == 'O') {
            if (!st.empty()) {
                cout << st.back() << "\n";
                st.pop_back();
            }
        } else if (cmd == 'T') {
            if (!st.empty()) {
                cout << st.back() << "\n";
            }
        } else if (cmd == 'P') {
            for (size_t i = 0; i < st.size(); ++i) {
                cout << st[i] << (i == st.size() - 1 ? "" : " ");
            }
            cout << "\n";
        } else if (cmd == 'N') {
            cout << st.size() << "\n";
        }
    }

    return 0;
}
