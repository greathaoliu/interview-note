// 自己实现一个shared_ptr
template<typename T>
class shared_ptr {
private:
    int *count_;
    T *ptr_;
public:
    shared_ptr(T *p) : count_(new int(1)), ptr_(p) {}

    shared_ptr(shared_ptr<T> &other) : count_(&(++*other.count_)), ptr_(other.ptr_) {}

    T *operator->() {
        return ptr_;
    }

    T &operator*() {
        return *ptr_;
    }

    shared_ptr<T> &operator=(shared_ptr<T> const &other) {
        if (&other != this) {
            ++*other.count_;
            if (this->ptr_ && --*this->count_ == 0) {
                delete count_;
                delete ptr_;
            }
            this->ptr_ = other.ptr_;
            this->count_ = other.count_;
        }
        return *this;
    }

    ~shared_ptr() {
        if (--*count_ == 0) {
            delete count_;
            delete ptr_;
        }
    }

    int GetRefCount() {
        return *count_;
    }
};