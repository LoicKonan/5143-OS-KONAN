#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Program #3 

using namespace std;

int main() 
{
  string address = "";
  string code = "";
  bool newAddress;
  int numAddresses;
  double average;
  int j = 0;
  int num_of_zeros;

  vector<string> Address;

  ifstream infile;

  infile.open("spice.txt");

  while(infile >> code)
  {
    infile >> address;
    newAddress = true;
    if(address.length() != 8){
      if (address.length() < 8){
        num_of_zeros = 8 - address.length();
        address = string(num_of_zeros, '0').append(address);
      }
    }
    
    // taking off the offset
    address = address.substr(0, address.size()-3);
    
    for (int i = 0; i < Address.size(); i++)
    {
      if (Address[i] == address)
      {
        newAddress = false;
        i = Address.size();
      }
    }

    if (newAddress == true)
    {
      Address.push_back(address);
    }
  }
  average = 1000000.0 / (double)Address.size();

  cout << "Total Pages Used: " << Address.size() << "\n";
  cout << "Average number of accesses: " << average << "\n";

  //system("pause");
  return 0;
}