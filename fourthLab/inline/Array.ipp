template <typename T>
Array<T>::Array() : _size(0), _capacity(1)
{
    _data = std::shared_ptr<T[]>(new T[_capacity], deleter);
}

template <typename T>
void Array<T>::resize(size_t newCapacity)
{
    auto new_data = std::shared_ptr<T[]>(new T[new_capacity], deleter);

    for (size_t i = 0; i < _size; ++i)
    {
        new_data[i] = _data[i];
    }

    _data = std::move(new_data);
    _capacity = newCapacity;
}

SFINE
template <typename T>
Array<T>::Array(const Array &other) : _size(other._size), _capacity(other._capacity), _data(std::shared_ptr<T[]>(new T[_capacity], deleter))
{

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array &&other) noexcept
{
    if (this != &other)
    {
        _data = std::move(other._data);
        _capacity = other._capacity;
        _size = other._size;

        other._size = 0;
        other._capacity = 0;
    }
    return *this;
}

template <typename T>
void Array<T>::pushBack(const T &t)
{
    if (_size >= _capacity)
    {
        resize(_capacity * 2);
    }

    _data[_size++] = t;
}

template <typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0)
        index += static_cast<int>(_size);
    if (index < 0 || index >= static_cast<int>(_size))
        throw std::out_of_range("Index is out of range");
    return _data[index];
}

template <typename T>
const T &Array<T>::operator[](int index) const
{
    if (index < 0)
        index += static_cast<int>(_size);
    if (index < 0 || index >= static_cast<int>(_size))
        throw std::out_of_range("Index is out of range");
    return _data[index];
}

template <typename T>
void Array<T>::remove(int index)
{
    if (index < 0)
    {
        index += _size;
    }

    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index is out of range");
    }

    for (size_t i = index; i < _size - 1; ++i)
    {
        _data[i] = std::move(_data[i + 1]);
    }

    --_size;
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
};

template <typename T>
Array<T>::Array(Array &&other) noexcept
    : _data(std::move(other._data)), _capacity(other._capacity), _size(other._size)
{
    other._size = 0;
    other._capacity = 0;
}