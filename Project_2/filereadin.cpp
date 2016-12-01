// Reading in the provided file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  std::string token;
 // char sources[1000],targets[1000];
 // int weights[1000];
  string sources[10000], targets[10000], weights[10000];
  int numLines = 0;
  int i = 0;
  int x = 0, y = 0, z = 0;
  
  ifstream myfile ("data.txt");
  
  if (myfile.is_open())
  {
   /* while ( getline (myfile,line) )
    {
      //cout << line << '\n';
	  numLines++;
    }*/

    while(std::getline(myfile, token, ','))
    {
	//	for(int i = 0; i <= (numLines*3); i++)
	//	{
			switch(i%2)
			{
				case 2: // source
				{
					sources[i] = token;
					x++;
					cout << sources[i] << endl;
				}
				
				case 1: // target
				{
					//targets[i] = token;
					y++;
				}
				
				case 0: // weight
				{
					//weights[i] = token;
					z++;
				}
				
			}
	//	}
		//std::cout << token << '\n';
		i++;		
    }
	
	myfile.close();
		
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	
	for(int j = 0; j <= ((numLines/3)+1); j++)
	{
	//	cout << sources[j] << ", " << endl;
	}
	
	cout << "Number of Lines: " << numLines << endl;
  }

  else 
	cout << "Unable to open file"; 

  return 0;
}


