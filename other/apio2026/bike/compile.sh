#!/bin/bash

task="bike"
grader_name="grader"

g++ -std=gnu++20 -Wall -O2 -pipe -g -o "${task}" "${grader_name}.cpp" "${task}.cpp" -DDEBUG -fsanitize=address,undefined -g
