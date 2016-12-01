#include <dirent.h> // directory header
#include <iostream> // input/output stream
#include <cstdlib> 
#include <fstream>
#include <string>

// use a few things from the std namespace for console I/O
using std::cout;
using std::cin;
using std::endl;
using namespace std;

int read () // entry point of the program
{
	string array_1[10020];
	int i = 0;
	string str;
	string file_name, file;
	string STRING;
	
    // first off, we need to create a pointer to a directory
    DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
    pdir = opendir ("./data"); // "." will refer to the current directory
    struct dirent *pent = NULL;

    // I used the current directory, since this is one which will apply to anyone reading
    // this tutorial~ If I said "C:\\" and you're on Linux, it may get a little confusing!
    if (pdir == NULL) // if pdir wasn't initialised correctly
    { // print an error message and exit the program
        cout << "\nERROR! pdir could not be initialised correctly";
        exit (3);
    } 

    while (pent = readdir (pdir)) // while there is still something in the directory to list
    {
        if (pent == NULL) // if pent has not been initialised correctly
        { // print an error message, and exit the program
            cout << "\nERROR! pent could not be initialised correctly";
            exit (3);
        }
        // otherwise, it was initialised correctly. Let's print it on the console:
		
		array_1[i] = pent->d_name;		
		i++;			
    }
	
	file_name = array_1[2];
	cout << file_name << endl;
	file = "./data/" + file_name;
	
	ifstream in;    // Create an input file stream.
    in.open(file.c_str());  // Use it to read from a file named data.txt.
	if (in.is_open())
	{
		while(!in.eof())
		{
			getline(in, STRING);
			cout << STRING << endl;
		}
	}
	in.close();
    return EXIT_SUCCESS; // everything went OK
}