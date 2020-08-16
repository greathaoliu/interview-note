#include <bits/stdc++.h>
using namespace std;
class Singleton{
private:
    static Singleton *instance;
    static mutex mutex_;
public:
    static Singleton *getInstance() {
        if(instance == nullptr) {
            lock_guard<mutex> lock(mutex_);
            if(instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};