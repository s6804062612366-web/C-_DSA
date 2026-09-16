#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void siftUp(int i, vector<int>& heap) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void siftDown(int i, vector<int>& heap) {
    int n = heap.size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void addVal(int v, vector<int>& heap) {
    heap.push_back(v);
    siftUp(heap.size() - 1, heap);
}

void deleteVal(vector<int>& heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        siftDown(0, heap);
    }
}

void printHeap(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "EMPTY\n";
        return;
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    vector<int> heap;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int v;
            cin >> v;
            addVal(v, heap);
            printHeap(heap);
        } else if (cmd == "delete") {
            deleteVal(heap);
            printHeap(heap);
        } else if (cmd == "topk") {
            int k;
            cin >> k;
            vector<int> extracted;
            while (k > 0 && !heap.empty()) {
                extracted.push_back(heap[0]);
                deleteVal(heap);
                k--;
            }
            printHeap(extracted);
            printHeap(heap);
        }
    }

    return 0;
}
