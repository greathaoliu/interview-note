#include <bits/stdc++.h>

using namespace std;

void MaxHeapify(vector<int> &arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            son++;
        }
        if (arr[dad] > arr[son]) {
            return;
        } else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        };
    }
}

void HeapSort(vector<int> &arr) {
    int len = arr.size();
    for (int i = len / 2; i >= 0; i--) {
        MaxHeapify(arr, i, len - 1);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, 0, i - 1);
    }
}

int main() {
    vector<int> array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    HeapSort(array);
    for (int val:array) {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}