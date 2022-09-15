// Read two integer values A and B and compute 3 different results: A+B, A-B and A*B. 
// Execute all those 3  operations in parallel using fork() and wait().
// Display the results, The program should print the results in the following format:
// A+B = Addition
// A-B = Subtraction
// A*B = Multiplication
// Check the results with the sequential version of the program.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>

// Declare variables
int A, B, Addition, Subtraction, Multiplication;

// This function is used to add two numbers
void AdditionThread(void *data)
{
    Addition = A + B;
    _endthread();
}

// This function is used to subtract two numbers
void SubtractionThread(void *data)
{
    Subtraction = A - B;
    _endthread();
}

// This function is used to multiply two numbers
void MultiplicationThread(void *data)
{
    Multiplication = A * B;
    _endthread();
}

// This is the main function
int main()
{
    // This read in A from the user
    printf("Enter A: ");
    scanf("%d", &A);

    // This read in B from the user
    printf("Enter B: ");
    scanf("%d", &B);

    // This creates the Addition thread
    _beginthread(AdditionThread, 0, NULL);

    // This creates the Subtraction thread
    _beginthread(SubtractionThread, 0, NULL);

    // This creates the Multiplication thread
    _beginthread(MultiplicationThread, 0, NULL);

    // This is a hack to wait for the threads to finish
    while (Addition == 0 || Subtraction == 0 || Multiplication == 0)
    {
        Sleep(100);
    }    


    // This Display the results
    printf("A+B = %d \r \n", Addition);
    printf("A-B = %d \r \n", Subtraction);
    printf("A*B = %d \r \n", Multiplication);

    return 0;
}
