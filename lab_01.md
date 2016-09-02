# Lab 1

This section will focus on the basics of compiling source code. Please use the
literature associated with this course, as well as resources online to acquire
further information about the topics discussed. 

Pull code from your assigned git repository.

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
> cd 01
> g++ -o say_hello.out hello_world.cpp 
> ./say_hello.out
```
where we first copy the source code, compile it and then run it. 

If there are any problems during compilation, such as trying to
compile an ill-formed program, _g++_ will print diagnostics related to
such, and no executable will be created.

## make

For larger projects it is recommended to use a build system. One such system is
called _make_ which is what we will use throughout this
course.

_make_ will read the contents of a file named _makefile_ in the
current working directory. This file contains rules specifying
how to build parts of your project, or simply put; how to produce an executable.

Look at 
There is a file named _makefile1_ make a copy of it in the current working directory and look at its contents by
invoking _more makefile_.


