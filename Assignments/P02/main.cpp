// read the file spice.txt and identify the number of page faults using First In First Out (FIFO) page replacement algorithm
// and also using Least Recently Used (LRU) page replacement algorithm
// Pages accessed should be marked as referenced and those with a writing code
// should be marked as modified. During page replacement, the overhead time will be increased by 100 cycles
// and if the page has been modified another 500 cycles should be added to the overhead 
// The size of a page will be selected during the execution so the user can test two different page sizes. 
// if the first letter of the address is :
// 0 - then address for data read
// 1 - then address for data write
// 2 - then address for instruction fetch

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;

// define the page size
#define PAGE_SIZE 1024

// define the number of frames
#define NUM_FRAMES 16

// define the number of bits for the offset
#define OFFSET_BITS 10

// define the number of bits for the page number
#define PAGE_BITS 4

// define the number of bits for the frame number
#define FRAME_BITS 4

// define the number of bits for the address
#define ADDRESS_BITS 16

// define the number of bits for the page table
#define PAGE_TABLE_BITS 4

// define the number of bits for the page table entry
#define PAGE_TABLE_ENTRY_BITS 4



int main()
{
    
}