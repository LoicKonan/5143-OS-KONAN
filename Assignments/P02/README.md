## Assignment 2 - Repacement Algorithms (FIFO & LRU)

### Loic Konan

#### Description

- This program will will analyze the use of a paged memory system with **32 K-bytes of physical memory**.
- It will read a file containing a sequence of addresses and will determine the number of **Page faults**,
- number of hits and finally it will Report the times for **page size 4096 and 2048**,
- running under **FIFO and LRU page replacements**.
- An important note is that During page replacement, the overhead time **will be increased by 100 cycles**
- due to the disk load operation and if the page has been modified another **500 cycles** should be added to the
- overhead to account for the writing back in disk.

### Files

|   #   | File                         | Description                                |
| :---: | ---------------------------- | ------------------------------------------ |
|   1   | [main.cpp](main.cpp)         | The main cpp with comments and description.|
|   2   | [README.md](README.md)       | The readme file.                           |
|   3   | [spice.txt](spice.txt)       | The main input file.                       |
|   4   | [spice1.txt](spice1.txt)     | The input file 2                           |
|   5   | [spice2.txt](spice2.txt)     | The input file 3                           |
|   6   | [spice3.txt](spice3.txt)     | The input file 4                           |

### Instructions

- This program was written in **C++** and compiled with **GCC**.
- To compile the program, run the following command in the terminal:

```bash

gcc main.cpp -o main

```

- To run the program, run the following command in the terminal:

```bash

./main

```

### Example Command

```bash

./main

```

### Example Output

Page size: **2048**
Page replacement: **FIFO**
Number of page faults:  **4607**
Number of hits:  **995394**
Total time:  **1136700**

Page size: **2048**
Page replacement: **LRU**
Number of page faults:  **3208**
Number of hits:  **996793**
Total time:  **666800**
