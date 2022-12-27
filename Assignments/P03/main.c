/**
 * @file:           main.c
 * @author:         Loic Konan
 * @brief:          This is the main file for the project.
 * @date:           2022-11-12
 *
 * @Description:    This program will read a file and display the information
 *                  based on the keyword.
 *
 * @Note:           Assignment #5
 *
 *
 * @ Example:       Input: intro
 *                  Output: About grades in this
 *
 *                  Input: pass
 *                  Output: You got an A, worked
 *
 *                  Input: fail
 *                  Output: You get an F, failed
 *
 *                  Input: next
 *                  Output: Look for nursing ads
 *
 * @Compiler :      gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 *
 *
 * @OS :            Ubuntu 18.04.5 LTS
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables for the file and the keyword
    FILE *fp;
    char *keyword = malloc(20);
    char *intro = "intro";
    char *pass = "pass";
    char *fail = "fail";
    char *next = "next";
    char *buffer = malloc(20);
    int byte = 0;

    // Ask the user to enter a keyword
    printf("Enter a keyword: ");
    scanf("%s", keyword);

    // Open the file
    fp = fopen("input.txt", "r");

    // Check if the keyword is intro
    if (strcmp(keyword, intro) == 0)
    {
        byte = 20;
    }
    // Check if the keyword is pass
    else if (strcmp(keyword, pass) == 0)
    {
        byte = 40;
    }
    // Check if the keyword is fail
    else if (strcmp(keyword, fail) == 0)
    {
        byte = 60;
    }
    // Check if the keyword is next
    else if (strcmp(keyword, next) == 0)
    {
        byte = 80;
    }
    // If the keyword is not found
    else
    {
        printf("Keyword not found!");

        // Close the file, to avoid printing garbage
        return 0;
    }

    // Move the file pointer to the byte
    fseek(fp, byte, SEEK_SET);

    // Read the file
    fread(buffer, 20, 1, fp);

    //  Null terminate the string, before printing it.
    buffer[20] = '\0';

    // Print the output, clear the buffer and close the file
    printf("%s", buffer);

    // Free the memory allocated to the buffer
    free(buffer);

    // Close the file
    fclose(fp);

    return 0;
}