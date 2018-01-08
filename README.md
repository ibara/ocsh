ocsh
====
Portable OpenBSD `csh(1)`.

Why?
----
Because I already had a port of OpenBSD `ksh`.
This shell should work on virtually every Unix-like operating system.
Patches to improve portability are much appreciated.

Dependencies
------------
A C compiler that understands the `long long` type. A C99 compiler is the
easiest way to ensure that ocsh will build correctly.

A `configure` script that produces a POSIX `Makefile` is available to ease
building and installation and can be run by:
```
$ ./configure
$ make && sudo make install
```

In case of emergency
--------------------
If you cannot execute make for whatever reason, a rescue script,
`rescue.sh`, is available. This script contains nothing more than a
hand-written list of compiler invocations which will build `ocsh` in the
most basic and portable way possible. This rescue shell is perfectly
usable (as it is just an unoptimized build).

License
-------
All files are BSD or ISC licensed.

Get a tarball
-------------
http://devio.us/~bcallah/ocsh/ocsh-20180108.tar.gz
