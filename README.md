# next-cpp

Experiments for the next C++ support.

## Test Frameworks

- [GoogleTest](https://github.com/google/googletest)
  - used at Qualified
  - test name must be identifiers
  - built-in mocking
  - supports custom reporter
- [Catch2](https://github.com/catchorg/Catch2)
  - simple / light weight
  - test name is a string
  - tests can be split into sections
  - supports custom reporter (not implemented yet)
- [bandit](https://github.com/banditcpp/bandit)
  - "human-friendly" / BDD style
  - not as popular
  - uses [`snowhouse`](https://github.com/banditcpp/snowhouse) assertion library which is used in Igloo
  - no custom reporting
- [Igloo](https://github.com/codewars/igloo)
  - abandoned and we've been maintaining a fork
  - BDD style
- [Criterion](https://github.com/Snaipe/Criterion)
  - C++20 requires Criterion 2.4+ which includes breaking changes affecting us
