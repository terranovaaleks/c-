# Lab 1

This section will focus on the basics of compiling source code. Please use the
literature associated with this course, as well as resources online to acquire
further information about the topics discussed.

If you are not familiar with git do read a git tutorial. There are plenty of 



Pull code from your assigned git repository
_git clone YOURKTH@kth.se:/cprog16/YOURKTH-labbar_. Do not edit any files in the root directory. Change working directory to _01_ and do all your work for this assignment there.

```
> cd 01
```


## How do I compile my implementation?

This course will use _g++_ to compile source code into object files, as
well as linking them to produce a final executable. The current recommended, and
used, version is _4.8.4_

There is a file named [hello_world.cpp](01/hello_world.cpp) in the directory associated with this assignment.

```C++
> cat hello_world.cpp
#include <iostream>
int main () {
    std::cout << "Hello, world!\n";
}
```

To compile the source code, and thereby produce an executable we may
invoke _g++_ in the manner stated below:


```
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
There is a _makefile_ in the current look at its contents by invoking _more makefile_.

```
> more makefile
%.out: %.cpp
       g++ -std=c++11 -g -Wall $*.cpp -o $*.out
```

Instead of messing around with a rather complex invocation of _g++_, you
can now produce an executable named _hello\_world.out_, compiled from a
source file named _hello\_world.cpp_, by simply invoking _make
hello\_world_.

```
    > make hello_world.out
    > ./hello_world.out
    Hello, world!
```

#### Questions

####     What does _\$*_ mean inside the _makefile_?

####     What is the purpose of _-Wall_ and _-g_, when passed as arguments to _g++_?

#### Write down 3 other arguments tp _g++_ that

####     How can you store the previous mentioned flags in a variable in the makefile?

####   What is the difference between an object file, and an executable?

There is a another makefile _makefile2_ with contents
that differ from the one viewed in the previous subsection. Overwrite the current _makefile_

```
> cp makefile2 makefile
```

Check the git status

```
> git status
Ändringar ej i incheckningskön:
(använd "git add <fil>..." för att uppdatera vad som skall checkas in)
(använd "git checkout -- <fil>..." för att förkasta ändringar i arbetskatalogen)

      ändrad:        makefile
```

Commit the new version of the _makefile_ to git. First you need to add it to the commit queue before commiting.

```
> git add makefile
> git commit makefile -m "changed makefile"
[master 3a939d5] changed makefile
 1 file changed, 13 insertions(+), 2 deletions(-)
```

Look at the content of _makefile_ by invoking _more makefile_

```
> more makefile
CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8

FLAGS = -std=c++11 -g -Wall -pedantic

main.out: main.cpp hello.o
	 $(CC) $(FLAGS) main.cpp hello.o -o main.out

hello.o: hello.cpp
	$(CC) $(FLAGS) -c hello.cpp

clean:
	rm -f *.o *.out

```

The old version of the makefile can be viewed with _git show_

```
git show HEAD~:01/makefile
%.out: %.cpp
       g++ -std=c++0x -g -Wall $*.cpp -o $*.out
```

#### Questions
