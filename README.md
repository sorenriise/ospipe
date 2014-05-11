ospipe
======


Presenting pipe `man 2 pipe`

This interface simply give the ability to call the Linux `pipe` system call.  It will return a pair of file descriptors, like;

```node
>  require('ospipe').ospipe();
[ 10, 11 ]
```

This is generally not useful for most node program, as the pipe has a limited size imposed by the os, and if you exceed that your program will block until it is read -- and since node is single threaded by nature, you will not be able to read from the pipe and you end up deadlocked.

However where this extension is useful, is if you have a native threaded extension which requires data to be read from a FD, then is a handy way of passing data from the node envirionment to the extension.


Github: https://github.com/sorenriise/ospipe


Install
=======

```bash
$ npm install ospipe
```