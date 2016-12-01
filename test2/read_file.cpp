#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  std::string token;
  
  ifstream myfile ("data2.txt");
  
  if (myfile.is_open())
  {
    while(std::getline(myfile, token, ','))
    {	
	std::cout << token << '\n';		
    }
	
	myfile.close();
  }

  else 
	cout << "Unable to open file"; 

  return 0;
}


