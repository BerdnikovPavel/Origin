#include <iostream>

template <class T>
class My_unique_ptr
{
private:
    T* ptr;
public:
    My_unique_ptr() : ptr(nullptr) {}

    ~My_unique_ptr() { delete ptr; }

    My_unique_ptr(const My_unique_ptr& value) = delete;

    My_unique_ptr& operator=(const My_unique_ptr& value) = delete;

    T& operator* () { return *ptr; }

    T* release()
    {
        T* raw_ptr = ptr;
        ptr = nullptr;
        return raw_ptr;
    }
};

int main()
{
    return 0;
}