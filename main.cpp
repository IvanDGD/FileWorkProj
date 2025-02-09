#include <iostream>

template <typename T>
class UniquePtr {
private:
    T* ptr;
public:
    UniquePtr(T* ptr = nullptr) : ptr(ptr) {}
    ~UniquePtr() { delete ptr; }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* ref_count;
public:
    SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}

    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        (*ref_count)++;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            ClearPtr();
            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    ~SharedPtr() {
        ClearPtr();
    }

    void ClearPtr() {
        if (ref_count) {
            (*ref_count)--;
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
        }
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
};

int main() {

    UniquePtr<int> uptr(new int(10));
    std::cout << *uptr << std::endl;

    SharedPtr<int> shptr(new int(20));
    std::cout << *shptr << std::endl;

    return 0;
}
