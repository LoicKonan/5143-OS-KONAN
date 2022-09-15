/**
 * @file:           main.c
 * @author:         Loic Konan
 * @brief:          This is the main file for the project.
 * @date:           2022-09-15
 * 
 * @Description:    This is the main file for the project.
 *                  C program which will run in a UNIX multiprocessor process. 
                    The program will read in two Numbers: A and B from the user 
                    and compute 3 different results: A+B, A-B and A*B.
                    The program will Forks 2 other processes in order to do all 3 operations simultaneously.
                    The program will display the results, The program should print the results in the following format:
                    A+B = Addition
                    A-B = Subtraction
                    A*B = Multiplication
                    Check the sequence of the three operations in your program 
                    and the order of appearance of the results in the screen.
                    Check the results with the sequential version of the program.


* @Comments:        It seems like the sometimes the addition is done first and other time the subtraction is done first,
                    but the multiplication is always done last.
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    // Declare variables
    int A;
    int B;
    int Addition;
    int Subtraction;
    int Multiplication;
    int status;
    pid_t pid;

    // This read in A from the user
    printf("Enter A: ");
    scanf("%d", &A);

    // This read in B from the user
    printf("Enter B: ");
    scanf("%d", &B);

    // This forks the first child
    pid = fork();

    // This checks if the fork failed
    if (pid < 0)
    {
        // This prints an error message
        printf("Fork failed!\n");
        exit(1);
    }

    // This checks if this is the first child
    if (pid == 0)
    {
        // This computes the addition
        Addition = A + B;

        
        // This prints the addition process id 
        printf("Addition process id: %d \n", getpid());

        // This prints the addition
        printf("Addition: A + B = %d \r \n", Addition);

        // This exits the first child
        exit(0);
    }

    // This forks the second child
    pid = fork();

    // This checks if the fork failed
    if (pid < 0)
    {
        // This prints an error message
        printf("Fork failed!\n");
        exit(1);
    }

    // This checks if this is the second child
    if (pid == 0)
    {
        // This computes the subtraction
        Subtraction = A - B;

        
        // This prints the subtraction process id
        printf("Subtraction process id: %d \n", getpid());

        // This prints the subtraction
        printf("Subtraction: A - B = %d \r \n", Subtraction);

        // This exits the second child
        exit(0);
    }

   else
    {
        // This computes the multiplication
        Multiplication = A * B;

        // This prints the multiplication
        printf("Multiplication: A * B = %d \r \n", Multiplication);

        // This waits for the first child to finish
        waitpid(-1, &status, 0);

        // This waits for the second child to finish
        waitpid(-1, &status, 0);
    }


    // This exits the parent
    exit(0);
}
