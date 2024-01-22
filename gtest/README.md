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
- `snippets-Cafeteria` - a kata with no preprocessing markers, with a complex preloaded, where both solution and preloaded are treated as headers, and the cpp part of both gets (apparently) ignored. It also defines custom `operator <<` for the preloaded types, which is used by GTest to present instances in failure messages. To be honest, I am ot sure why this example works because I expected it to fail with linker errors caused by standalone definitions of `operator<<`. I need to take a better look.
