// 两个线程轮流打印奇数和偶数
#include <bits/stdc++.h>
using namespace std;

int turn = 1;

void PrintOdd() {
    static int num = 1;
    while(1) {
        if(turn  == 1) {
            cout<<num<<endl;
            num = num + 2;
            turn = 0;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void PrintEven() {
    static int num = 2;
    while(1) {
        if(turn == 0) {
            cout<<num<<endl;
            num = num + 2;
            turn = 1;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() {
    std::thread t1(PrintOdd);
    std::thread t2(PrintEven);
    t1.join();
    t2.join();
    return 0;
}
