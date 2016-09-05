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





















