#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> inventory;
    string cmd;

    while (cin >> cmd && cmd != "End") {
        if (cmd == "ADD") {
            string item;
            cin >> item;
            inventory[item]++;
        } else if (cmd == "CHECK") {
            string item;
            cin >> item;
            cout << inventory[item] << "\n";
        }
    }

    return 0;
}
