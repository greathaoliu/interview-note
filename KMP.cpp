#include <bits/stdc++.h>

using namespace std;

vector<int> BuildNext(string pattern) {
    int n = pattern.length();
    vector<int> next(n);
    next[0] = -1;
    int t = -1;
    int j = 0;
    while(j < n - 1) {
        if(t < 0||pattern[t] == pattern[j]) {
            t ++;
            j ++;
            next[j] = t;
        } else {
            t = next[t];
        }
    }
    return next;
}

int MatchKMP(string text, string pattern) {
    int m = text.length();
    int n = pattern.length();
    int i = 0, j = 0;
    vector<int> next = BuildNext(pattern);
    while (i < m && j < n) {
        if (j < 0||text[i] == pattern[j]) {
            i ++;
            j ++;
        } else {
            j = next[j];
        }
    }
    return i - j;
}

int main() {
    string text = "abcdefg";
    string pattern = "efg";
    cout<<MatchKMP(text, pattern);
    return 0;
}