# Reference
[cppreference.com](https://en.cppreference.com/w/cpp/utility/functional/function)
[What is std::function in C++, and why do we need them?](https://lesleylai.info/en/std-function/)
https://stackoverflow.com/questions/20353210/what-is-the-purpose-of-stdfunction-and-how-to-use-it


The signature it supports goes inside the angle brackets: 

std::function<void()> takes zero arguments and returns nothing. 
std::function< double( int, int ) > takes two int arguments and returns double. 



In general, std::function supports storing any function-like object whose arguments can be converted-from its argument list, and whose return value can be converted-to its return value.

# Inline function Advantages, Disadvantages, Performance and User Guidelines ?
https://cplusplus.com/articles/G3wTURfi/


## Demo2.cpp
```c++ 
#include <functional>
#include <iostream>

struct Foo {
   Foo(int num) : num_(num) {}
   void print_add(int i) const { std::cout << num_+i << '\n'; }
   int num_;
};
 
void print_num(int i) {
   std::cout << i << '\n';
}

struct PrintNum {
   void operator()(int i) const {
      std::cout << i << '\n';
   }
};

int main() {
   std::function<void(int)> f_display = print_num;
   f_display(-9);

   std::function<void()> f_display_42 = []() { print_num(42); };
   f_display_42();

   std::function<void()> f_display_31337 = std::bind(print_num, 31337);
   f_display_31337();

   std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
   const Foo foo(314159);
   f_add_display(foo, 1);

   std::function<int(Foo const&)> f_num = &Foo::num_;
   std::cout << "num_: " << f_num(foo) << '\n';

   using std::placeholders::_1;
   std::function<void(int)> f_add_display2= std::bind( &Foo::print_add, foo, _1 );
   f_add_display2(2);
 
   std::function<void(int)> f_add_display3= std::bind( &Foo::print_add, &foo, _1 );
   f_add_display3(3);

   std::function<void(int)> f_display_obj = PrintNum();
   f_display_obj(18);
}
``` 
```
Output:
-9
42
31337
314160
num_: 314159
314161
314162
18
```

### sorting
## sorting_1.cpp
```c++
#include <algorithm>
#include <iostream>
#include <functional>

int main()
{
    int arr[] = { 5,2,1,4,3};

    std::function<void()> print_array = [&](){
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    };
    std::function<int(int&, int &)> cmp = [](int& a, int& b){
        return a > b;
    };

    print_array();
    std::sort(
        arr, 
        arr + sizeof(arr)/sizeof(arr[0]), 
        cmp
    );
    print_array();
   
    return 0;
}
```
```
Output: 
5 2 1 4 3 
5 4 3 2 1 
```