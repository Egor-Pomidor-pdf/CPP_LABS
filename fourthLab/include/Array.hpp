#pragma once

#include <utility>
#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
public:
    Array();
    ~Array() noexcept = default;
    Array(Array &&other) noexcept;
    void pushBack(const T &t);
    void remove(int index);
    Array(const Array &other);
    T &operator[](int index);
    const T &operator[](int index) const;
    size_t size() const;
    Array<T> &operator=(Array &&other) noexcept;

private:
    std::shared_ptr<T[]> _data;
    size_t _capacity = 1;
    size_t _size = 0;
    void resize(size_t newCapacity);
    static constexpr auto deleter = [](T* ptr) { delete[] ptr; };
};

#include "Array.ipp"
