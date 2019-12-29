#!/bin/bash

export LD_LIBRARY_PATH=`pwd`

gcc test.c -fPIC -shared -o libtest.so

go build -o main main.go cfuns.go