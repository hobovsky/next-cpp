#!/bin/sh
cp snippets/test_solution.snippet tests/test_solution.cpp

clang++ -o preprocessor/cwpp -O2 preprocessor/cwpp.cpp
./preprocessor/cwpp SOLUTION snippets/solution.snippet
./preprocessor/cwpp PRELOADED snippets/preloaded.snippet
