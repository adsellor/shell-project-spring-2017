# -*- makefile -*-
main := main/main.cpp
program := iterate_shell
flags := -std=c++14 -g -Wall -Wextra -I./
lib_name := libshell.a
# Just add another file here when you're done, ending in .o
objs := shell.o
os := $(shell uname -s)

ifeq ($(os),Darwin)
  maybe_static_phrase :=
else
  maybe_static_phrase := -static
endif

# We statically link to avoid shared library hassles.
program:library
	clang++ ${maybe_static_pharse} ${main} -L. \
	-lshell ${flags} -o ${program}

%.o:%.cpp
	clang++ -c ${flags} $<

# Need to have a dependency on things that end with .o to have the
# wildcard pattern go off.
library:${objs}; ar rcs ${lib_name} ${objs}

test_shell:program; PATH='' ./${program}

clean:; @rm -rf ${program} *.dSYM *.o ${lib_name} *.so *.a
