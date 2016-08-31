# Lab 1

This section will focus on the basics of compiling source code. Please use the
literature associated with this course, as well as resources online to acquire
further information about the topics discussed.

## How do I compile my implementation?

This course will use _g++_ to compile source code into object files, as
well as linking them to produce a final executable. The current recommended, and
used, version is _4.8.4_

There is a file named [hello_world.cpp](01/hello_world.cpp) in the directory associated with this assignment.

```C++
> cat 01/1_make_it_happen/hello_world.cpp
#include <iostream>
int main () {
    std::cout << "Hello, world!\n";
}
```

To compile the source code, and thereby produce an executable we may
invoke _g++ in the manner stated below:


```
> cp /info/DD2387/labs/lab1/0.1_make_it_happen/hello_world.cpp .
> g++ -o say_hello.out hello_world.cpp 
> ./say_hello.out
```

