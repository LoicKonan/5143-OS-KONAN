// C program which will run in a UNIX multiprocessor process. 
// The program will read in two numbers: A and B from the user and compute 3 different results: A+B, A-B and A*B.
// The program will execute all those 3 operations in parallel, Forks 2 other processes in order to do all 3 operations simultaneously.
// The program will display the results, The program should print the results in the following format:
// A+B = Addition
// A-B = Subtraction
// A*B = Multiplication
// Check the sequence of the three operations in your program and the order of appearance of the results in the screen.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <windows.h>
#include <process.h>

