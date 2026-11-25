#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& a, int n, int i, bool minHeap) {
    int target = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && (minHeap ? a[l] < a[target] : a[l] > a[target])) target = l;
    if (r < n && (minHeap ? a[r] < a[target] : a[r] > a[target])) target = r;
    if (target != i) {
        swap(a[i], a[target]);
        heapify(a, n, target, minHeap);
    }
}

void heapSort(vector<int>& a, bool descending) {
    int n = a.size();
    bool minHeap = descending; // Min-heap -> descending; max-heap -> ascending
    for (int i = n / 2 - 1; i >= 0; --i) heapify(a, n, i, minHeap);
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        heapify(a, end, 0, minHeap);
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> base(n);
    for (int i = 0; i < n; ++i) cin >> base[i];

    vector<int> descArr = base, ascArr = base;
    heapSort(descArr, true);
    heapSort(ascArr, false);

    for (int i = 0; i < n; ++i) cout << descArr[i] << (i + 1 < n ? ' ' : '\n');
    for (int i = 0; i < n; ++i) cout << ascArr[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
