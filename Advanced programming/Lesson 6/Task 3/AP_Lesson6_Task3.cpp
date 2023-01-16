#include <iostream>

template<typename T>
class MyVector {
public:
    MyVector()
    {
        arr = new T[1];
        v_capacity = 1;
        v_size = 0;
    }

    unsigned int size() const
    {
        return v_size;
    }

    unsigned int capacity()
    {
        return v_capacity;
    }

    void addCapacity()
    {
        v_capacity *= 2;
        T* tmp = arr;
        arr = new T[v_capacity];
        for (unsigned int i = 0; i < v_size; ++i)
        {
            arr[i] = tmp[i];
        }
        delete[] tmp;
    }

    void push_back(T value) {
        if (v_size == v_capacity) { addCapacity(); }
        arr[v_size++] = value;
    }

    T& operator[](int index) {
        return arr[index];
    }

    const T& operator[](unsigned int index) const {
        return arr[index];
    }

    T at(unsigned int index)
    {
        if (index < v_size)
            return arr[index];
    }

    ~MyVector() 
    {
        delete[] arr;
    }

private:
    T* arr;
    unsigned int v_size;
    unsigned int v_capacity;
};

int main()
{
    MyVector<int> v;
    std::cout << v.capacity() << ", " << v.size() << std::endl;
    v.push_back(5);
    std::cout << v.at(0) << ", " << v.capacity() << ", " << v.size() << std::endl;
    v.push_back(89);
    std::cout << v.at(1) << ", " << v.capacity() << ", " << v.size() << std::endl;
    v.push_back(34);
    v.push_back(8);
    v.push_back(0);
    std::cout << v.at(4) << ", " << v.capacity() << ", " << v.size() << std::endl;

    return 0;
}
