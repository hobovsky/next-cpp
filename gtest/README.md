# GoogleTest

```bash
cmake -S . -B build -G Ninja
cmake --build build && ./build/tests/tests
```

Use `./configure.sh` and `./run-tests.sh`.

We'll configure and build an example project while building the container image so each submission will only build the submitted code.


## Example kata

The `snippets-*` directories contain showcases of kata which could be migrated to Google Test and the proposed organization of snippets:
- `snippets-originalExample` - the original example of Google Test tests prepared by kazk. It uses no CW preprocessor markers, and only `preloaded.h` and `solution.cpp` are relevant. `preloaded.cpp` and `solution.h` are also saved, but are irrelevant, and cause no problems when buiding and testing the kata.
- `snippets-uniqueInOrder` - a kata which requires separate cpp file and header file for solution, because it requires users to implement two functions: one is a template, and one is a "normal" function. It uses CW preprocessor markers to split submitted solution snippet into two files.