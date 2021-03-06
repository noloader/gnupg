#!/usr/bin/env bash

TOP_DIR=$(pwd)

cd "${HOME}" || exit 1

if ! git clone --depth=1 \
     git://git.gnupg.org/libassuan.git;
then
    echo "Failed to clone libassuan"
    exit 1
fi

cd libassuan || exit 1

if ! ./autogen.sh;
then
    echo "Failed to bootstrap libassuan"
    exit 1
fi

# Required per README.git
if ! ./configure --enable-maintainer-mode;
then
    echo "Failed to configure libassuan"
    cat config.log
    exit 1
fi

if ! make -j 3;
then
    echo "Failed to build libassuan"
    exit 1
fi

if ! make check;
then
    echo "Failed to test libassuan"
    exit 1
fi

if ! sudo make install;
then
    echo "Failed to install libassuan"
    exit 1
fi

cd "${TOP_DIR}" || exit 1

exit 0
