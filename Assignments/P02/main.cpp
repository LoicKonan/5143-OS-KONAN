#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>

using namespace std;

struct processor
{
    int frame_numbers;
    int valid_bit;
    int refbits;
    int modbits;
};

#define BLOCK_SIZE 4096
#define Physical_memory 65536

void swap_positions(struct processor *dup, int i);

int main()
{
    ifstream infile;
    infile.open("spice.txt");

    int num;
    string val;
    char address[8] = {};
    int address_val;
    int code;

    int offset_length = log2(BLOCK_SIZE);
    int frames = Physical_memory / BLOCK_SIZE;
    int pages_length = 20;
    int page_val = 0;
    int i = 0;
    int available = 0;
    int a = 0;
    int faults = 0;

    processor *algo = new processor[16];
    for (i; i < frames; i += 1)
    {
        algo[i].frame_numbers = -1;
        algo[i].valid_bit = 0;
        algo[i].refbits = 0;
        algo[i].modbits = 0;
    }
    while (infile >> num >> val)
    {
        code = num;
        strcpy(address, val.c_str());
        address_val = strtol(address, 0, 16);
        page_val = address_val >> offset_length;

        for (int i = 0; i < frames; i++)
        {
            if (algo[i].frame_numbers == page_val)
            {
                algo[i].refbits = 1;
                algo[i].valid_bit = 1;
                if (code == 1)
                    algo[i].modbits = 1;
                available = 1;
            }
        }
        if (available == 0 && a < frames)
        {

            algo[a].frame_numbers = page_val;
            algo[a].refbits = 1;
            algo[a].valid_bit = 1;
            if (code == 1)
                algo[a].modbits == 1;
            faults++;
            a++;
        }

        else if (available == 0 && (a > frames - 1))
        {

            for (int k = 0; k < frames; k++)
            {

                if (algo[k].refbits == 1)
                {
                    algo[k].refbits = 0;
                    swap_positions(algo, k);
                    for (int z = 0; z < frames; z++)
                    {
                        algo[z].refbits = 0;
                    }
                }
                if (algo[k].refbits == 0 && algo[k].modbits == 1)
                {
                    algo[k].modbits = 0;
                    swap_positions(algo, k);
                    for (int p = 0; p < frames; p++)
                    {
                        algo[p].refbits = 0;
                    }
                }
                else if (algo[k].refbits == 0 && algo[k].modbits == 0)
                {

                    algo[k].frame_numbers = page_val;
                    algo[k].refbits = 1;
                    algo[k].valid_bit = 1;
                    if (code == 1)
                        algo[k].modbits = 1;
                    swap_positions(algo, k);
                    faults++;
                    k = 100;
                }
            }
        }
        available = 0;
    }
    ofstream outfile;
    outfile.open("output.txt");

    outfile << "Number of page Faults: " << faults << endl;

    outfile << "Frame Number \t"
            << "Page Number \t"
            << "Reference Bit\t  "
            << "Modified Bit \t" << endl;
    for (int i = 0; i < frames; i++)
    {
        outfile << i << " \t \t \t \t" << algo[i].frame_numbers << " \t \t \t \t " << algo[i].refbits << " \t \t \t \t" << algo[i].modbits << endl;
    }
    outfile.close();
    infile.close();
    return 0;
}

void swap_positions(struct processor *dup, int i)
{
    processor a;
    for (int l = i; l < 15; l++)
    {
        a = dup[l + 1];
        dup[l + 1] = dup[l];
        dup[l] = a;
    }
}