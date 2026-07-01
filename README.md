# EECE-2560-mastermind

## Building the Project

[CMakeLists.txt](CMakeLists.txt) tells CMake how to compile the project.

Run:
```
cmake -S . -B build # Configure
cmake --build build # Compile
```

## Playing Mastermind

Run:
```
./build/mastermind
```

The user is prompted for two numbers `n`, the length of the code, and `m` which determines which digits are allowed in the code (0:m-1). The program randomly generates a code within these parameters and the user is given 10 tries to guess the code. After each guess, the program responds with a pair of numbers X, Y where the first number is the number of correct digits in the correct positions, and the second number is the number of correct digits in incorrect positions.