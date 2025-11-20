template<int V>
struct Fib<int N>
{
   int value = fib<int N - 1>::value + fib<int N - 2>::value;
};

template<>
struct Fib<int 1>
{
   int value = 1;
};

template<>
struct Fib<int 0>
{
   int value = 1;
};



