#include <bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int> &arr) {
    int len = arr.size();
    for(int i = 0; i < len - 1; i ++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j ++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
            swap(arr[i], arr[min]);
        }
    }
}

int main() {
    vector<int> array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    SelectionSort(array);
    for (int val:array) {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}