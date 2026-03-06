#!/bin/bash
g++ -std=c++20 -O2 -Wall crumbs.cpp grader.cpp -o crumbs -DLOCAL -fsanitize=address,undefined -g
