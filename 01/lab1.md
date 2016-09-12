where can you find the manual to g++? 

$g++ -version

ger att jag har clang :(clang-703.0.31) 

manualen kan hittas med kommandot  
$ man clang


What is the purpose of -Wall and -g, when passed as arguments to g++?

What the -Wall flag will do is show ALL the warning messages you may get that describe possible errors in your source code

$ g++ -Wall source_file.cc


-g   Generate debug information


How can you store the previous mentioned flags in a variable in the makefile?

lägg till i CFLAGS. spara  , se exemplet nedan

CC=/bin/gcc
CFLAGS=-Wall
INSTDIR=/usr/local/bin

${INSTDIR}/program: myfile.c
    ${CC} ${CFLAGS} -o ${INSTDIR}/program myfile.c

In this example, after making the string substitutions, the command that "make" will use to build "program" from "myfile.c" is:

/bin/gcc -Wall -o /usr/local/bin/program myfile.c



Find and write down 3 other arguments to g++ that you think might be useful and write a short motivation why you selected these specific 3 arguments.


What is the difference between an object file, and an executable?
båda är binära filer men object filen kan inte exekveras - kompilatorn har inte länkats till biblioteket .



What does git show HEAD~:01/makefile show?

gå tillbaka 1 commit från den nu gällande versionen


What does git show HEAD:01/makefile show?
current version


What would git show HEAD~~:01/makefile show?
two version before the head (current version)

What does the ~ in the previous git show commands mean?
the version before the current version

Why can you not ommit 01 in the previous commands (i.e. git show HEAD~:makefile instead of git show HEAD~:01/makefile)

because makefile is in directory 01


Sometimes you may need to do a git pull before you can do a git push how can that be?

Use git fetch to retrieve new work done by other people. Fetching from a repository grabs all the new remote-tracking branches and tags without merging those changes into your own branches.

Merging combines your local changes with changes made by others.

Pull = fetch + merge
---------------------
versionen på din lokala rep är inte synkat med de nya versionerna som finns på remote repository.



What is the purpose of the .git_ignore file and why should *.o *.out *.exe be in this file when developing C++?

.git_ignore file är filer som man vill ignorera oavsett om man pushar dem. vi behöver inga binära filer när vi jobbar med ett program vi får dem autmatiskt efter varje gång vi kompilerar programmet


If you invoke touch hello.cpp prior to invoking make, how many files were rebuilt?
main.cpp , main.out  

You can also update a file's timestamp with the touch command, if you need or want to force any output files depending on it to be rebuilt


Why do you think make checks the modification timestamp of the relevant files as part of deciding what to do?
 
????

What is the difference between an implicit rule and an explicit rule in a makefile?

Explicit rules specify the instructions that MAKE must follow when it builds specific targets

An implicit rule specifies a general rule for how MAKE should build files that end with specific file extensions


What does \$* mean inside a makefile?

 If you wish to use the matched text in the target itself, use the special variable $*. For instance, the following example will let you type make <name of .c file> to build an executable file with the given name:

%:
gcc -o $* $*.c

> make test_executable

would run:

gcc -o test_executable test_executable.c

------------

 a translation unit is the ultimate input to a C compiler from which an object file is generated.




Hello world questions:
standard output stream - std::cout

std::cerr

The standard error stream is the default destination for error messages and other diagnostic warnings. Like stdout, it is usually also directed by default to the text console 


std::clog  - use for logging



-----
why does not powerof return expected value (16) when invoking with 2 and 4?
beacuse it is not looping  add: {}

----
Why does not adding_a_decimal output 100000?

step: 0.100000001   

precisionen minskar när "sum" blir större - sum får färre decimaler



----------

jämför olika datatyper float med double 
input är float, 3.1415 är double














