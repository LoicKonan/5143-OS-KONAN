//#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <string.h>

#define myPID getpid()
#define parentID getppid()

void *read_chars(int pid, char array[]) 
{
  int readptr;
  // FILE *writeptr;

  // char buff[10];//10 characters
  readptr = open("input.txt", O_RDWR);
  // writeptr = fopen("output.txt", "w");
  int start = pid * 10;

  lseek(readptr, start, SEEK_SET);
  read(readptr, array, 5);
  
  // using lseek to skip 5 and that is current placeholder to start from
  lseek(readptr, start, 5);

  // read(readptr, array, 5);
  write(1, array, 5);
  // writing the next 5

  for (int p = 0; p < 5; p++) {
    printf("From process %d, element %d has %c\n", pid, p, array[p]);
  }
}

int main(int argc, char *argv[]) {

  int pid;
  int i = 1;

  // Create the two child processes
  fork();
  if (parentID == 1) {
    fork();
  }

  // Assign process ids
  if (parentID == 1) {
    pid = 0;
  } else {
    // Will give a process ID of 1 and 2
    pid = myPID - parentID;
  }

  char charArray[5];

  read_chars(pid, charArray);

  waitpid(-1, NULL, 0);

  // printf("My ID is %d, my parent is %d. My Process ID is %d\n", myPID, parentID, pid);
}