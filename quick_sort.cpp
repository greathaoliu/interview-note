#include <bits/stdc++.h>

using namespace std;

int Partition(vector<int> &array, int left, int right, int pivot_index) {
    int mid = array[pivot_index];
    swap(array[pivot_index], array[right]); // 把pivot移动到最右
    int store_index = left;
    for (int i = left; i <= right; i++) {
        if (array[i] < mid) {
            swap(array[i], array[store_index++]);
        }
    }
    swap(array[store_index], array[right]); // 把pivot移动到最后该去的地方
    return store_index;
}

void QuickSelect(vector<int> &array, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot_index = (left + right)/2;
    int part = Partition(array, left, right, pivot_index);
    QuickSelect(array, part + 1, right);
    QuickSelect(array, left, part - 1);
}

void QuickSort(vector<int> &array) {
    int len = array.size();
    QuickSelect(array, 0, len - 1);
}

int main() {
    vector<int> array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    QuickSort(array);
    for (int val:array) {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}