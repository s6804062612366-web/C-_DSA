#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    stack<int> s;
    int target_idx = 0;

    for (int i = 1; i <= n; ++i) {
        s.push(i);
        while (!s.empty() && s.top() == p[target_idx]) {
            s.pop();
            target_idx++;
        }
    }

    if (s.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
