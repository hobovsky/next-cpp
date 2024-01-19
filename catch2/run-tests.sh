#!/bin/bash

cmake --build build && ./build/tests/tests --reporter=codewars
