## Lab 1 answers

The file format is [markdown](https://en.wikipedia.org/wiki/Markdown) a tutorial on markdown can be found [here](http://www.markdowntutorial.com/). Write your answers here. Copy relevant code to put questions and answers in context.
Commit and push _inquiry.md_ each day you work with the file.

#### g++ compiler questions

#### Where can you find the manual to g++?

_TODO: your answer here_

####     What is the purpose of _-Wall_ and _-g_, when passed as arguments to _g++_?

####     How can you store the previous mentioned flags in a variable in the makefile?

#### Find and write down 3 other arguments tp _g++_ that you think might be useful and write a short motivation why you selected these specific 3 arguments.

####   What is the difference between an object file, and an executable?


#### Git Questions

#### What does _git show HEAD~:01/makefile_ show?

#### What does _git show HEAD:01/makefile_ show?

#### What would _git show HEAD~~:01/makefile_ show?

#### What does the _~_ in the previous _git show_ commands mean?

#### Why can you not ommit _01_ in the previous commands (i.e. _git show HEAD~:makefile_ instead of  _git show HEAD~:01/makefile_)

#### Sometimes you may need to do a _git pull_ before you can do a _git push_ how can that be?

#### What is the purpose of the .git_ignore file and why should \*.o \*.out \*.exe be in this file when developing C++?


#### makefile questions

#### If you invoke _touch hello.cpp_ prior to invoking _make_, how many files were rebuilt?

#### Why?

#### Why do you think _make_ checks the modification timestamp of the relevant files as part of deciding what to do?

#### What is the difference between an implicit rule and an explicit rule in a makefile?

#### What does _\$*_ mean inside a _makefile_?


#### Hello world questions

#### What is the purpose of _std::cout_, _std::cerr_, and _std::clog_, respectively?

#### How does #include work?


#### debugging questions

#### Why does not _powerof_ return the expected value (_16_), when invoked with _2_ and _4_?

#### Why does not _adding_a_decimal_ output 100000?

#### Describe how _weird.out_ is invoked by _echo '3.1415' | ./weird.out_  

#### Why does not _y_ compare equal to _3.1415_?

#### Is there any difference in behavior if we compare _y_ to _3.1415f_, if so; why?

#### Describe and motivate the recommended method to use when trying to determine if two floating-point values are equal.


#### unit test questions

#### Why is it important to test the boundary conditions of an implementation, especially in the case of _count_if_followed_by_?

#### Describe how the testcase tests if a pointer is accessing an element outside the range specified


#### class construction questions

#### What constructors are invoked, and when? List the corresponding lines and name the invoked constructor

#### Will there be any temporaries created, if so; when?

#### What will happen if we try to free a dynamically allocated array through _delete p_, instead of _delete [] p_?


#### valgrind

#### _valgrind_ indicates that there is something wrong with _complex.cpp_; what, and why?


#### _valgrind_ indicates that the program suffers from a few problems, which and why?

#### If you comment out the entire if-block in _foo_, is there any difference in how much memory that is leaked?


#### Why is it that valgrind still issue diagnostics related to memory management?

#### Add code that fixes the memory management
