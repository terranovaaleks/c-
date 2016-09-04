# Lab 1

This section will focus on the basics of compiling source code. Please use the
literature associated with this course, as well as resources online to acquire
further information about the topics discussed.


If you are not familiar with git you may need to read up on git. There is KTH-specific guide (in swedish [here](https://www.kth.se/social/files/55f1b20ef276547bf8af78fc/git_draft.pdf). There are plenty of other resources on the internet on git, some can be found <a [https://help.github.com/articles/good-resources-for-learning-git-and-github/](here)

https://gits-14.sys.kth.se/
If you have not done so already, [follow these steps to generate ssh-keys](https://help.github.com/articles/generating-an-ssh-key/) but use _gits-15.sys.kth.se_ instead of _github.com_ and perhaps do use ordinary copy/paste instead of _clip < ~/.ssh/id_rsa.pub_

Pull code from your assigned git repository. If you have generated ssh-keys you should be able to run something similar to this on your command line:
```
git clone git@gits-15.sys.kth.se:cprog16/YOURKTHLOGIN-labbar.git
```

Change your working directory to the root of your cloned git repository. Do not edit any files in the root directory. Change working directory to _01_ and do all your work for this assignment in _01_.

```
> cd path/to/cloned-repository
> cd 01
```


## How do I compile my implementation?

This course will use _g++_ to compile source code into object files, as
well as linking them to produce a final executable. The current recommended, and
used, version is _4.8.4_

There is a file named [hello_world.cpp](01/hello_world.cpp) in _01_

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
where we first compile the source code and then run it.

If there are any problems during compilation, such as trying to
compile an ill-formed program, _g++_ will print diagnostics related to
such, and no executable will be created.

## make and git

For larger projects it is recommended to use a build system. One such system is
called _make_ which is what we will use throughout this
course.

_make_ will read the contents of a file named _makefile_ in the
current working directory. This file contains rules specifying
how to build parts of your project, or simply put; how to produce an executable.

Look at
There is a _makefile_ in _01_ look at its contents by invoking _more makefile_.

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

#### g++ compiler questions

#### Where can you find the manual to g++?

####     What is the purpose of _-Wall_ and _-g_, when passed as arguments to _g++_?

####     How can you store the previous mentioned flags in a variable in the makefile?

#### Find and write down 3 other arguments tp _g++_ that you think might be useful and write a short motivation why you selected these specific 3 arguments.

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

#### Git Questions

#### What does _git show HEAD~:01/makefile_ show?

#### What does _git show HEAD:01/makefile_ show?

#### What would _git show HEAD~~:01/makefile_ show?

#### What does the _~_ in the previous _git show_ commands mean?

#### Why can you not ommit _01_ in the previous commands (i.e. _git show HEAD~:makefile_ instead of  _git show HEAD~:01/makefile_)

#### What is the purpose of the .git_ignore file and why should \*.o \*.out \*.exe be in this file when developing C++?

## How _make_ works

invoke _make_ to see the
resulting behavior. Try to build the executable two times without making any
changes to the dependent files.

```
    > make
    g++ -std=c++11 -g -Wall -pedantic -c hello.cpp
    g++ -std=c++11 -g -Wall -pedantic main.cpp hello.o -o main.out
    > make
    make: `main.out' is up to date.
```

Upon invoking _make_, the program will look for _dependencies_ that
are more recently modified than the _target file_. If there are no such
file, and a target file is already present, _make_ will decide that
there is nothing to do; why work for something that has already been done?


_touch_ can be used to change the modification timestamp of a file to
the current time (effectively making it look _as if_ the file has been
modified).

Change the modification timestamp of _main.cpp_ by invoking _touch_.

```
    > touch main.cpp
```

Now invoke _make_, and notice that _hello.cpp_ will not be recompiled.

```
    > make
    g++ -std=c++11 -g -Wall -pedantic main.cpp hello.o -o main.out
```

#### makefile questions

#### If you invoke _touch hello.cpp_ prior to invoking _make_, how many files were rebuilt?

#### Why?

#### Why do you think _make_ checks the modification timestamp of the relevant files as part of deciding what to do?

#### What is the difference between an implicit rule and an explicit rule in a makefile?

#### What does _\$*_ mean inside a _makefile_?

## clang compiler

There is an alternative compiler (_clang_) installed on the ubuntu
systems. To switch from using _gcc_ to _clang_, modify the
_makefile_ and uncomment the following line (by removing _\#_).

```C++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8
```

Using a different compiler can often allow you to view potential errors from a
different angle (mostly because different compilers present errors in different
ways), making it easier to realize what went wrong, and more importantly; why.

Build and run the program using _clang_.

## Assignment an improved (hello) world

_hello, world_ is a classic program that dates back to 1974, first published
in a paper titled _Programming in C: A tutorial_. The program has one
simple purpose; to print "_hello, world_".

Since the typical implementation is trivial, your task is to write a more
versatile alternative, having the following semantics:

```
> ./hello
Hello, world!
> ./hello "DD1387"
Hello, DD1387!
> ./hello "KTH" 3
Hello, KTH KTH KTH!
> ./hello "KTH" 0
> ./hello "KTH" 2
Hello, KTH KTH!
> ./hello "Malcom X" NaN
error: 2nd argument must be an integral greater than zero!
> ./hello kth dd1387 3
```

_This assignment is not an exercise in object oriented programming (OOP), but
a mere introduction to the fundamental parts of C/C++_

### Requirements

* _main.cpp_ contains the definition of the applications _main_-function.
There is no need for you to modify this file, but please make sure that
you understand what is written in it.

* _hello.cpp_ has a corresponding _.h_-header that contains
_forward-declarations_ for the functions you are to implement.

* This header, _hello.h_, is included (_#include_) by
_main.cpp_, and should be included by _hello.cpp_.

* _hello.cpp_ shall be compiled separately, resulting in an
object file that is to be linked into the resulting executable.

* You shall implement a function named _parse\_args_ in a separate
_translation unit_ named _hello.cpp_.
This function is responsible for parsing/interpreting the command line
arguments passed to the application, and shall return a
[_std::pair_](http://en.cppreference.com/w/cpp/utility/pair)
with what to print, and how many times to print it.

* _parse\_args_ shall handle all input errors by returning _-1_
as the second value of the returned _std::pair_, as well as printing
a suitable error message on _stderr_.

* You shall implement a function named _hello_ in a separate
_translation unit_ named _hello.cpp_ (i.e. the same file that
shall contain the implementation of _parse_args_).

_hello_ is responsible for printing the _hello world_-string on
_stdout_ with the following semantics;

**     If the value _zero_ is passed as the second parameter,
    nothing shall be printed.

** If a value greater than _zero_ is passed as the second argument
(_count_), _"Hello, "_ shall be printed followed by
_count_ space-delimited occurrences of the first argument.
The output shall end with an exclamation mark, followed by a new-line.
*Note_: hello ("KTH", 3)* shall print _Hello, KTH KTH KTH!_ (see the
  previous example invocations of the program for more information).

* Correct output from your program shall be printed through
_std::cout_, whereas potential error diagnostics (detected by
_parse_args_) shall be printed through _std::cerr_.



### Hints

* The argument named _argc_ to _main_ will contain the number of
arguments passed to your application. Remember that the name of the
executable counts to this number.

* The second argument, _argv_, will provide access to the individual
arguments passed to your application.

* _std::atoi_ from _<cstdlib>_ can be used to convert a
_char const *_ to an integer. If the function is unable to interpret
the data as an integer, it will return _0_.




#### Hello world questions

#### What is the purpose of _std::cout_, _std::cerr_, and
_std::clog_, respectively?

#### How does #include work?

## Train Spotting (debugging)

There is a source file named _weird.cpp_. Read through its source code and try
to reason about the runtime behavior of the program without running it.


```
int powerof (int x, int y) {
  int res = 1;

  for (int i = 0; i < y; ++i);
    res *= x;

  return res;
}

int main () {
  int const a = 2;
  int const b = 4;

  int   x = powerof(a, b);
  float y = 3.1415;

  std::cout << a << "^" << b << " = " << x << ";\n";

  if (y == 3.1415)
    std::cout << y << " is equal to 3.1415!\n";
  else
    std::cout << y << " is not equal to 3.1415!\n";
}
```

Compile and execute the program. Hopefully you notice how the behavior differs
from what one might expect. Your task is to figure out why that is with the
help of a debugger.
