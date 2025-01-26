#!/bin/sh
aclocal &&
autoconf &&
automake --add-missing &&
./configure &&
make
# make dist &&
# make distcheck &&
# make install &&
ls