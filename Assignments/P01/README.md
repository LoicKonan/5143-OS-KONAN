## Assignment 1 - Basic Concepts

### Loic Konan

#### Description

- **C program** which will run in a **UNIX multiprocessor process**.
- The program will read in two Numbers: **A and B** from the user and compute 3 different results: **A + B**, **A - B** and **A * B**.
- The program will _**Forks 2 other processes in order to do all 3 operations simultaneously**_.
- The program will display the results, The program should print the results in the following format:
- _A+B_ = **Addition**
- _A-B_ = **Subtraction**
- _A*B_ = **Multiplication**
- Check the results with the sequential version of the program.

### Files

|   #   | File                   | Description                                       |
| :---: | ---------------------- | ------------------------------------------------- |
|   1   | [main.c](main.c)       | The main c file with comments and description     |
|   2   | [README.md](README.md) | The README file with description and instructions |
|   3   | [fork.c](fork.c)       | Example of how fork works in c                    |
|   4   | [thread.c](thread.c)   | Example of how threads work in c                  |

### Instructions

- This program was written in **C** and compiled with **GCC**.
- To compile the program, run the following command in the terminal:

```
    bash
    gcc main.c -o main
```

### Example Command

- `gcc main.c -o main`
- `./main`
- `Enter A: 5`
- `Enter B: 10`
- Addition = `5 + 10 = 15`
- Subtraction = `5 - 10 = -5`
- Multiplication ID = `5 * 10 = 50`
- Multiplication process ID (Parent process ID) = `1234`
- Addition process ID (Child process ID) = `1235`
- Subtraction process ID (Child process ID)= `1236`
