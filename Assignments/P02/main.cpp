// Your assignment consists of designing and implementing a program that will analyze the use of a paged
// memory system with 32 Kbytes of physical memory. Your program will read the file and identify the number of page faults and the simulated overhead time as specified below.
// The size of a page will be selected during the execution so the user can test two different page sizes. The
// data file has 1 million addresses. Your program will accept several records of input data, according to the
// following format:
// Code Address (in hexadecimal)
// Where code is identified by a single digit with the following meaning:
// 0 - address for data read
// 1 - address for data write
// 2 - address for instruction fetch
// An example of the data file contents could be
// 2 415130
// 0 1010acac
// 2 415134

// During the execution of this file, pages will be stored in the physical memory and later replaced following
// a First In First Out algorithm. Pages accessed should be marked as referenced and those with a writing code
// should be marked as modified. During page replacement, the overhead time will be increased by 100 cycles
// due to the disk load operation and if the page has been modified another 500 cycles should be added to the
// overhead to account for the writing back in disk. The experiment should be repeated with a Least Recently
// Used algorithm (hint: a linked list or a queue may help you to track the LRU information)
// Report your times for page size 4096 and 2048, running under FIFO and LRU page replacements.
// You must turn in the source code of your program and a short report. This report must contain the
// comparison of the two possible line sizes.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct page
{
    int page_number;
    int valid_bit;
    int ref_bit;
    int mod_bit;
    int time_stamp;
};

int main()
{
    
}


