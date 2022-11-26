# Assignment 3 - Byte position

## Loic Konan

### Description

- The program should keep a table with **3 entries showing keywords** to access Information in a file.
- The only accepted input will be the **keyword** used to search a file for some information.
- The table will provide the byte location of the requested information, which will be some string with20 characters.
- Your program will access and display the **20 characters**, starting at the position specified in the table.
- Your mission is to **write a program that reads the input, opens the file, skips to the desired location and displays the information**.

**Program Table**
_**Keyword Byte position**_
**intro _20_
pass _40_
fail _60_
next _80_**

**Example:**
**Keyword:** _pass_
**Output:** _You got an A, worked_ 
**Keyword:** _fail_
**Output:** _You got an F, failed_
**Keyword:** _next_
**Output:** _You got an A, worked_


### Files

|   #   | File                         | Description                                |
| :---: | ---------------------------- | ------------------------------------------ |
|   1   | [main.cpp](main.cpp)         | The main cpp with comments and description |
|   2   | [README.md](README.md)       | The readme file                            |
|   3   | [input](input)               | The input file                             |

### Instructions

- This program was written in **C** and compiled with **GCC**.
- To compile the program, run the following command in the terminal:

```
    bash
    gcc main.c -o main
```

### Example Command

- g++ -o main main.cpp
- ./main
