iterate shell
-------------

This is iterate project for `C/C++` experience; we are making a `UNIX`
shell, this will NOT work on Windows but it will work on `OS X` and
any other `UNIX` aka any `Linux`.

Your code should be implemented in the `.cpp` files with an
appropriate API exposed in the respective `.h` file.

requirements per platforms
--------------------------

# OS X

Congrats, on `OS X` you don't need to do anything other than have
`XCode` installed.

# Linux 

The project uses `clang` and the `fsanitize` so you'll need to have
these installed on your machine, use `aptitude`

```shell
$ aptitude install libc++1 clang lldb make libasan1 libasan1-dbg libasan0
```

# Windows

Your options are: 

1. Get rid of Windows, install Linux (Debian or Ubuntu is good)
2. Dual boot Linux and Windows
3. Get a Virtual Machine on Windows, can use VMWare or Virtual Box.

Development Roadmap (Always check for updates as this is always updating)
-------------------------------------------------------------------------

# First steps, getting input, parsing

A shell is a REPL, which stands for: `READ EVALUATE PRINT LOOP`. It
takes a line of input, evaluates it, prints the results and loops
again. So the first step is to write code that takes a line of input
from the user. Once you get that line of input, you need to parse
it, that is turn it into something understand about. Take for example:

```shell
$ git status
```

What will your shell really read in? 

```
*HINT: How much should you keep reading? When do you stop reading from `stdin`?*
```

You shell will get:

```
"git status"
```

And this isn't useful yet. You need to split the string into different
parts. Remember that many programs have short flags and long flags,
aka `-` and `--`.

```
*HINT: Read about shell redirection, you will need to handle the
special symbols |, <, and >
```

Once you have that all together, you need to think about process management.

# Process management

Unix process management is a hierarchieral relationship. When we start
a prorgram, say `git`, we have this relationship.

```
bash
  |--git
```

That is, `bash` is the parent of `git`. You can see the entire process
tree with

```
$ pstree
```

If you don't have `pstree` then use `aptitude` to install it,
`$ aptitude install pstree`.

# Testing the shell

You should be invoking `iterate_shell` as so:

```shell
$ make test_shell
```
