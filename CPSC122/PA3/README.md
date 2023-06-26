# README !!!

## To Setup (One Time Only)
`git clone (your github repo url here)`  
`cd` into your local repo you just cloned into  
`mkdir build`  
`cd build`  
`cmake ..`

## To Compile (Each Time)
In the build directory run `make`

## To Run `main()` in Main.cpp
In the build directory run `./runPA#` where # is this PA's number

## To Run Unit Tests in test/Test.cpp
In the build directory run `./test/runTests`
* Do not make any assumptions about how the unit tests call functions
    * For example: Do not assume an output parameter has been initialized to zero
* You can look at (but not modify) the unit tests in test/Test.cpp to see how the the unit tests call functions

## How to Interpret Unit Test Output
Example:  
```
[----------] 1 test from Test1_Task1
[ RUN      ] Test1_Task1.Computations
test/Test.cpp:9: Failure
Value of: isMultiple
  Actual: false
Expected: true
...
[  FAILED  ] Test1_Task1.Computations (0 ms)
```   
Interpretation:
* `Test1_Task1.Computations` is the name of the test
* You can find its first point of failure in `test/Test.cpp` at line number 9
* Actual: At runtime, the variable `isMultiple` stored `false` (this is the value returned by the code in `answerIntegerQuestions()`)
* Expected: At runtime, the variable `isMultiple` should have stored `true` (this is the correct/solution value)
* You can look at the call to `answerIntegerQuestions()` that produced this value of `isMultiple` to see what the input arguments to `answerIntegerQuestions()` were
    * This will help you debug your own code with the goal of producing the expected value given the input

## What to Modify and What not to Modify
You may modify:
* Main.cpp
* PA#.cpp (do not change existing function headers)
* PA#.h (do not change existing function prototyes)

You may not modify:
* CMakeLists.txt
* Anything in the test/ directory
* Any hidden files
