#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long max_sum = -1e18;
    int best_l = 1;
    int best_r = 1;
    int best_len = 2e9;

    long long current_sum = 0;
    int current_l = 1;

    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;

        if (current_sum <= 0) {
            current_sum = val;
            current_l = i;
        } else {
            current_sum += val;
        }

        int current_len = i - current_l + 1;

        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_l = current_l;
            best_r = i;
            best_len = current_len;
        } else if (current_sum == max_sum) {
            if (current_len < best_len) {
                best_l = current_l;
                best_r = i;
                best_len = current_len;
            } else if (current_len == best_len) {
                if (current_l < best_l) {
                    best_l = current_l;
                    best_r = i;
                }
            }
        }
    }

    cout << max_sum << " " << best_l << " " << best_r << "\n";

    return 0;
}
