#include <iostream>
#include <cstring>

class Vector {
private:
    int* data;
    int size_;
    int capacity_;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        std::memcpy(new_data, data, size_ * sizeof(int));
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector() {
        capacity_ = 16;
        size_ = 0;
        data = new int[capacity_];
    }

    ~Vector() {
        delete[] data;
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    bool is_empty() const {
        return size_ == 0;
    }

    int at(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return *(data + index);
    }

    void push(int item) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        *(data + size_) = item;
        size_++;
    }

    void insert(int index, int item) {
        if (index < 0 || index > size_) {
            throw std::out_of_range("Index out of bounds");
        }
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        std::memmove(data + index + 1, data + index, (size_ - index) * sizeof(int));
        *(data + index) = item;
        size_++;
    }

    void prepend(int item) {
        insert(0, item);
    }

    int pop() {
        if (is_empty()) {
            throw std::out_of_range("Vector is empty");
        }
        int item = *(data + size_ - 1);
        size_--;
        if (size_ <= capacity_ / 4) {
            resize(capacity_ / 2);
        }
        return item;
    }

    void delete_at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        std::memmove(data + index, data + index + 1, (size_ - index - 1) * sizeof(int));
        size_--;
        if (size_ <= capacity_ / 4) {
            resize(capacity_ / 2);
        }
    }

    void remove(int item) {
        for (int i = 0; i < size_; i++) {
            if (*(data + i) == item) {
                delete_at(i);
                i--;
            }
        }
    }

    int find(int item) const {
        for (int i = 0; i < size_; i++) {
            if (*(data + i) == item) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Vector vec;

    vec.push(10);
    vec.push(20);
    vec.push(30);
    vec.push(40);

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Is empty: " << (vec.is_empty() ? "Yes" : "No") << std::endl;

    std::cout << "Element at index 2: " << vec.at(2) << std::endl;

    vec.insert(1, 15);
    vec.prepend(5);

    std::cout << "Elements after insertion: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    int popped = vec.pop();
    std::cout << "Popped element: " << popped << std::endl;

    vec.delete_at(2);
    vec.remove(20);

    std::cout << "Elements after deletion: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    int index = vec.find(15);
    if (index != -1) {
        std::cout << "Element 15 found at index: " << index << std::endl;
    } else {
        std::cout << "Element 15 not found" << std::endl;
    }

    return 0;
}
