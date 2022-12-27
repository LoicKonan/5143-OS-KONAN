/**************************************************************************************
 * @file:           main.c++
 * @author:         Loic Konan
 * @brief:          This is the main file for the project.
 * @date:           2022-11-26
 *
 *
 * @Description:
 *                  This program will will analyze the use of a paged
 *                  memory system with 32 K-bytes of physical memory.
 *                  The program will read a file containing a sequence
 *                  of addresses and will determine the number of Page faults,
 *                  number of hits and finally it will
 *                  Report the times for page size 4096 and 2048,
 *                  running under FIFO and LRU page replacements.
 *
 *                  An important note is that During page replacement,
 *                  the overhead time will be increased by 100 cycles
 *                  due to the disk load operation and if the page has been
 *                  modified another 500 cycles should be added to the
 *                  overhead to account for the writing back in disk.
 *
 *
 *
 * @Report:         The FIFO Algorithm was really bad compared to the LRU algorithm.
 *                  The LRU algorithm beat the FIFO algorithm in all the cases.
 *                  Depending on table size the cycles time and the page fault count
 *                  increased dramatically on both algorithms.
 *
 * ************************************************************************************
 *
 * @Results:
 *                   if page size: 2048
 *
 *                   LRU Page Faults: 3208
 *                   LRU Hits: 996793
 *                   LRU Overhead Time: 666800
 *                   LRU Pages Referenced: 1000001
 *
 *                   FIFO Page Faults: 4607
 *                   FIFO Hits: 995394
 *                   FIFO Overhead Time: 1136700
 *                   FIFO Pages Referenced: 1000001
 *
 * *************************************************************************************
 *
 * @Results:
 *                   if page size: 4096
 *
 *                   LRU Page Faults: 11317
 *                   LRU Hits: 988684
 *                   LRU Overhead Time: 2659700
 *                   LRU Pages Referenced: 1000001
 *
 *                   FIFO Page Faults: 16840
 *                   FIFO Hits: 983161
 *                   FIFO Overhead Time: 4719500
 *                   FIFO Pages Referenced: 1000001
 *
 *
 ***************************************************************************************/
#include <iostream>
#include <fstream>
#include <list>
#include <deque>
#include <unordered_map>
#include <iomanip>
#include <cmath>



using namespace std;

// Using this to store elements by the combination of a key value and a mapped value,
// for fast retrieval of individual elements based on their keys.
unordered_map<unsigned int, bool> Table;

// Using this struct to store page number, the code and wether if the code is modified or not.
struct page
{
    bool modified;
    int page_number;
    int code;

    // Constructor
    page(int page_number, int code)
    {
        this->page_number = page_number;

        // If the code is 0 then the page is not modified.
        if (code == 1)
            this->modified = true;
        else
            this->modified = false;
    }
};


/*****************************************
 *                                       *
 *  FIFO replacement algorithm Below     *
 *                                       *
 *****************************************/
void FIFO(deque<page *> &Data, int page_number, int code, long long int &total_time, int &page_faults, int &hits, int &referenced, int &frame_number)
{
    // If the page is not present in the Table.
    if (!Table[page_number])
    {
        // If the size of the Data is greater than or equal to the frame number.
        if (Data.size() >= frame_number)
        {
            // If the code is 1, then the page is modified.
            if (Data[0]->modified)
            {
                // If the page is modified, then the total time is incremented by 500.
                total_time += 500;
            }
            
            Table[Data[0]->page_number] = false;

            // delete the first element of the Data.
            delete Data[0];

            // pop the first element of the Data.
            Data.pop_front();

            // push the new page to the Data.
            Data.push_back(new page(page_number, code));

            // set the page number to true in the Table.
            Table[Data[Data.size() - 1]->page_number] = true;
        }

        // If the size of the Data is less than the frame number.
        else
        {
            // push the new page to the Data.
            Data.push_back(new page(page_number, code));

            // set the page number to true in the Table.
            Table[page_number] = true;
        }

        // Increment the page faults.
        page_faults++;

        // Increment the total time by 100.
        total_time += 100;
    }

    // If the page is present in the Table.
    else
    {
        // Increment the hits.
        hits++;

        // check if the code is 1.
        if (code == 1)
        {
            int index;

            // Find the index of the page number in the Data.
            for (int i = 0; i < Data.size(); i++)
            {
                // check if the page number is equal to the page number in the Data.
                if (Data[i]->page_number == page_number)
                {
                    // set the index to i.
                    index = i;
                }
            }

            // set the modified to true.
            Data[index]->modified = true;
        }
    }

    // Increment the referenced.
    referenced++;
}

/*****************************************
 *                                       *
 *  LRU replacement algorithm Below      *
 *                                       *
 *****************************************/
void LRU(deque<page *> &Data, int page_number, int code, long long int &total_time, int &page_faults, int &hits, int &referenced, int &frame_number)
{
    // If the page is not present in the Table.
    if (!Table[page_number])
    {
        // If the size of the Data is greater than or equal to the frame number.
        if (Data.size() >= frame_number)
        {
            // If the code is 1, then the page is modified.
            if (Data[0]->modified)
            {
                // If the page is modified, then the total time is incremented by 500.
                total_time += 500;
            }

            // set the page number to false in the Table.
            Table[Data[0]->page_number] = false;

            // delete the first element of the Data.
            delete Data[0];

            // pop the first element of the Data.
            Data.pop_front();

            // push the new page to the Data.
            Data.push_back(new page(page_number, code));

            // set the page number to true in the Table.
            Table[Data[Data.size() - 1]->page_number] = true;
        }

        // If the size of the Data is less than the frame number.
        else
        {
            // push the new page to the Data.
            Data.push_back(new page(page_number, code));

            // set the page number to true in the Table.
            Table[page_number] = true;
        }

        // Increment the page faults.
        page_faults++;

        // Increment the total time by 100.
        total_time += 100;
    }

    // if the page is present in the Table.
    else
    {
        // Increment the hits.
        hits++;

        // check if the code is 1.
        if (code == 1)
        {
            int index;

            // Find the index of the page number in the Data.
            for (int i = 0; i < Data.size(); i++)
            {
                // check if the page number is equal to the page number in the Data.
                if (Data[i]->page_number == page_number)
                {
                    // set the index to i.
                    index = i;
                }
            }

            // set the modified to true.
            Data[index]->modified = true;
        }

        int index;

        // Find the index of the page number in the Data.
        for (int i = 0; i < Data.size(); i++)
        {
            // check if the page number is equal to the page number in the Data.
            if (Data[i]->page_number == page_number)
            {
                // set the index to i.
                index = i;
            }
        }

        // delete the page number from the Data.
        page *temp = Data[index];

        // pop the page number from the Data.
        Data.erase(Data.begin() + index);

        // push the page number to the Data.
        Data.push_back(temp);
    }

    // Increment the referenced.
    referenced++;
}

/*****************************************
 *                                       *
 *          Driver Program               *
 *                                       *
 *****************************************/
int main()
{
    // Declare and open the file.
    ifstream infile("spice.txt");

    // initialize variables
    unsigned int hex_address;
    int page_number;
    int code;
    int frame_number;
    int offset;
    int tableSize;
    int algorithm;
    int page_faults = 0;
    int hits = 0;
    long long int total_time = 0;
    int referenced = 0;

    // deque to store pages
    deque<page *> Data;

    // Ask user for which algorithm to use.
    cout << "\nChoose 1 for (FIFO) or 2 for (LRU): ";
    cin >> algorithm;

    // if statement to pick algorithm to use.
    if (algorithm == 1)
    {
        // This for loop run twice to 2048 and 4096
        for (int i = 0; i < 2; i++)
        {
            // this if statement set the table size to either 2048 or 4096
            if (i == 0)
                tableSize = 2048;
            else
                tableSize = 4096;

            // Calculate the frame number
            frame_number = (pow(2, 15)) / tableSize;

            // Calculate the offset
            offset = log2(tableSize);

            // This while loop read the file and store the data in the deque
            while (infile >> code >> hex >> hex_address)
            {
                // Calculate the page number
                page_number = hex_address >> offset;

                // Call the FIFO function
                FIFO(Data, page_number, code, total_time, page_faults, hits, referenced, frame_number);
            }

            // Print the results for FIFO
            cout << "\nTablesize:  "       << setw(11) << tableSize    << endl;
            cout << "FIFO Frame number: "  << setw(1)  << frame_number << endl;
            cout << "FIFO Offset: "        << setw(8)  << offset       << endl;
            cout << "FIFO Hits: "          << setw(14) << hits         << endl;
            cout << "FIFO Referenced: "    << setw(9)  << referenced   << endl;
            cout << "FIFO Page faults:  "  << setw(4)  << page_faults  << endl;
            cout << "FIFO Total time:   "  << setw(6)  << total_time   << endl
                 << endl;

            // Reset the variables FIFO
            page_faults = 0;
            hits = 0;
            total_time = 0;
            referenced = 0;

            // Reset for the next table size
            Data.clear();
            infile.clear();
            infile.seekg(0, ios::beg);
        }
    }

    // This else statement is for the LRU
    else
    {
        // This for loop run twice to 2048 and 4096
        for (int i = 0; i < 2; i++)
        {
            // this if statement set the table size to either 2048 or 4096
            if (i == 0)
                tableSize = 2048;
            else
                tableSize = 4096;

            // Calculate the frame number
            frame_number = (pow(2, 15)) / tableSize;

            // Calculate the offset
            offset = log2(tableSize);

            // This while loop read the file and store the data in the deque
            while (infile >> code >> hex >> hex_address)
            {
                // Calculate the page number
                page_number = hex_address >> offset;

                // Call the LRU function
                LRU(Data, page_number, code, total_time, page_faults, hits, referenced, frame_number);
            }

            // Print the results for LRU
            cout << "\nTablesize: "       << setw(11) << tableSize    << endl;
            cout << "LRU Frame number: "  << setw(1)  << frame_number << endl;
            cout << "LRU Offset: "        << setw(8)  << offset       << endl;
            cout << "LRU Hits: "          << setw(14) << hits         << endl;
            cout << "LRU Referenced: "    << setw(9)  << referenced   << endl;
            cout << "LRU Page faults:  "  << setw(4)  << page_faults  << endl;
            cout << "LRU Total time:   "  << setw(6)  << total_time   << endl
                 << endl;

            // Reset the variables LRU
            page_faults = 0;
            hits = 0;
            total_time = 0;
            referenced = 0;

            // Reset for the next table size
            Data.clear();
            infile.clear();
            infile.seekg(0, ios::beg);
        }
    }
    return 0;
}
