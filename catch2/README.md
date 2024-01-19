# Catch2

> `CodewarsReporter` is unfinished.

```bash
cmake -S . -B build -G Ninja
cmake --build build && ./build/tests/tests --reporter=codewars
```

Use `./configure.sh` and `./run-tests.sh`.


We'll configure and build an example project while building the container image so each submission will only build the submitted code.

---

I haven't figured out the timings of the test events used in the custom reporter yet.
The tests can be written more naturally, but it might be difficult to get the output we want.
