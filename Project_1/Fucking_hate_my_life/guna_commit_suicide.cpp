#include <dirent.h> // directory header
#include <iostream> // input/output stream
#include <cstdlib> 
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main () // entry point of the program
{
	string str_1[10020];
	
	DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
    pdir = opendir ("./shit"); // "." will refer to the current directory
    struct dirent *pent = NULL;

    // I used the current directory, since this is one which will apply to anyone reading
    // this tutorial~ If I said "C:\\" and you're on Linux, it may get a little confusing!
    if (pdir == NULL) // if pdir wasn't initialised correctly
    { // print an error message and exit the program
        cout << "\nERROR! pdir could not be initialised correctly";
        exit (3);
    } // end if

    while (pent = readdir (pdir)) // while there is still something in the directory to list
    {
        if (pent == NULL) // if pent has not been initialised correctly
        { // print an error message, and exit the program
            cout << "\nERROR! pent could not be initialised correctly";
            exit (3);
        }
        // otherwise, it was initialised correctly. Let's print it on the console:
		
		str_1[i] = pent->d_name;
		
		cout << str_1[i];
		
		i++;
		
		
	  
	}
	
	

/*	ifstream myReadFile;
		myReadFile.open(str_1.c_str());
		char output[100];
		if (myReadFile.is_open()) 
		{
			while (!myReadFile.eof()) 
			{
				myReadFile >> output;
				cout<<output;
			}
		
			cout << endl;
		}
		myReadFile.close();
		return 0;
    }
	 
*/
 //  closedir (pdir);

  //  cin.get (); // pause for input
    return EXIT_SUCCESS; // everything went OK
	
	
}
