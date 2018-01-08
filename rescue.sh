#!/bin/sh

# This rescue script should work literally everywhere.
# If your kit is so broken you need this, I'm going to
#   assume that you need all the help you can get.
#
# Written by Brian Callahan <bcallah@openbsd.org>
# Released into the Public Domain

echo cp rconfig.h config.h
cp rconfig.h config.h

echo cp rconst.h const.h
cp rconst.h const.h

echo cp rerror.h error.h
cp rerror.h error.h

echo cc -c alloc.c
cc -c alloc.c

echo cc -c char.c
cc -c char.c

echo cc -c const.c
cc -c const.c

echo cc -c csh.c
cc -c csh.c

echo cc -c dir.c
cc -c dir.c

echo cc -c dol.c
cc -c dol.c

echo cc -c error.c
cc -c error.c

echo cc -c exec.c
cc -c exec.c

echo cc -c exp.c
cc -c exp.c

echo cc -c file.c
cc -c file.c

echo cc -c func.c
cc -c func.c

echo cc -c glob.c
cc -c glob.c

echo cc -c hist.c
cc -c hist.c

echo cc -c init.c
cc -c init.c

echo cc -c lex.c
cc -c lex.c

echo cc -c misc.c
cc -c misc.c

echo cc -c parse.c
cc -c parse.c

echo cc -c proc.c
cc -c proc.c

echo cc -c sem.c
cc -c sem.c

echo cc -c set.c
cc -c set.c

echo cc -c str.c
cc -c str.c

echo cc -c time.c
cc -c time.c

echo cc -c reallocarray.c
cc -c reallocarray.c

echo cc -c signame.c
cc -c signame.c

echo cc -c strtonum.c
cc -c strtonum.c

echo cc -o ocsh alloc.o char.o const.o csh.o dir.o dol.o error.o exec.o exp.o file.o func.o glob.o hist.o init.o lex.o misc.o parse.o proc.o sem.o set.o str.o time.o reallocarray.o signame.o strtonum.o
cc -o ocsh alloc.o char.o const.o csh.o dir.o dol.o error.o exec.o exp.o file.o func.o glob.o hist.o init.o lex.o misc.o parse.o proc.o sem.o set.o str.o time.o reallocarray.o signame.o strtonum.o
