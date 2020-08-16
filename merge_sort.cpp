#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int> &array, int front, int mid, int end) {
    vector<int> left(array.begin() + front, array.begin() + mid + 1);
    vector<int> right(array.begin() + mid + 1, array.begin() + end + 1);
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int left_index = 0, right_index = 0;
    for (int i = front; i <= end; i++) {
        if (left[left_index] < right[right_index]) {
            array[i] = left[left_index++];
        } else {
            array[i] = right[right_index++];
        }
    }
}

void MergeSort(vector<int> &array, int front, int end) {
    if (front >= end) {
        return;
    }
    int mid = front + (end - front) / 2;
    MergeSort(array, front, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, front, mid, end);
}

void MergeSortIteration(vector<int> &array) {
    int len = array.size();
    vector<int> res(len);
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2) {
                res[k++] = array[start1] < array[start2] ? array[start1++] : array[start2++];
            }
            while (start1 < end1) {
                res[k++] = array[start1++];
            }
            while (start2 < end2) {
                res[k++] = array[start2++];
            }
        }
        swap(array, res);
    }
}

int main() {
    vector<int> array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    MergeSortIteration(array);
    for (int val:array) {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}