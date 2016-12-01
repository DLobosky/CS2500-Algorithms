#include <dirent.h> // directory header
#include <iostream> // input/output stream
#include <cstdlib> 
#include <fstream>
#include <string>
#include"functions.h"
#include<cstring>

// use a few things from the std namespace for console I/O
using std::cout;
using std::cin;
using std::endl;
using namespace std;



int main()
{
	//int index_length = 100; 
	int lcs_length = 0;  ///CHECK TO MAKE SURE WE DO NOT DIVIDE BY ZERO!
	float similarity = 0.0;
	
	string index_array_0[10000] = "";	
	string index_array_201[10000] = "";
	string index_array_301[10000] = "";
	string index_array_601[10000] = "";
	string index_array_1001[10000] = "";
	string index_array_1501[10000] = "";
	string index_array_2501[10000] = "";
	
	int length_array_0[100];	
	int length_array_201[100];
	int length_array_301[100];
	int length_array_601[100];
	int length_array_1001[100];
	int length_array_1501[100];
	int length_array_2501[100];
	
	int location_0 = 0;
	int location_201 = 0;
	int location_301 = 0;
	int location_601 = 0;
	int location_1001 = 0;
	int location_1501 = 0;
	int location_2501 = 0;
	
	int duplicates_0 = 0;
	int duplicates_201 = 0;
	int duplicates_301 = 0;
	int duplicates_601 = 0;
	int duplicates_1001 = 0;
	int duplicates_1501 = 0;
	int duplicates_2501 = 0;
	
	string readin = "";
	string readin_new = "";
	int readin_length = 0;
	
//-----------------------------------------------------read in files--------------------------------------------------------------		
	for(int z = 0; z<10000; z++)
	{
		string array_1[10020];
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
			//exit (3);
		} 

		while (pent = readdir (pdir)) // while there is still something in the directory to list
		{
			if (pent == NULL) // if pent has not been initialised correctly
			{ // print an error message, and exit the program
				cout << "\nERROR! pent could not be initialised correctly";
				//exit (3);
			}
			// otherwise, it was initialised correctly. Let's print it on the console:
			
			array_1[z] = pent->d_name;				
		}
		
		file_name = array_1[2];
		//cout << file_name << endl;
		file = "./data/" + file_name;
		ifstream in;    // Create an input file stream.
		in.open(file.c_str());  // Use it to read from a file named data.txt.
		if (in.is_open())
		{
			while(!in.eof())
			{
				getline(in, STRING);
			//	cout << STRING << endl << endl << endl << endl << "The length of the string is: " << STRING.length() << endl;
			}
		}
		in.close();
		
		//cout << "stop";
		
		readin_length = readin.length();
	
//----------------------------------------------------------------end of read in files--------------------------------------------------------------		
		//read in string from file and store in readin.
		//readin_length = getlength(readin);
		int k = 0;		
		for(int j = 0; j < readin_length; j++)
		{
			if(((readin[j] >= 48) && (readin[j] <= 57)) || ((readin[j] >= 65) && (readin[j] <= 90)) || ((readin[j] >= 97) && (readin[j] <= 122)))
			{
				readin_new += readin[j];
				k++;
			}
			
			if((k >= 0) && (k <= 200))
			{
				//cout<< "k is between 0 and 200." <<endl;
				index_array_0[location_0] = readin_new;
				length_array_0[location_0] = k;
				location_0++;
			}
			else if((k >= 201) && (k <= 300))
			{
				//cout<< "k is between 201 and 300." <<endl;
				index_array_201[location_201] = readin_new;
				length_array_201[location_201] = k;
				location_201++;
			}
			else if((k >= 301) && (k <= 600))
			{
				//cout<< "k is between 301 and 600." <<endl;
				index_array_301[location_301] = readin_new;
				length_array_301[location_301] = k;
				location_301++;
			}
			else if((k >= 601) && (k <= 1000))
			{
				//cout<< "k is between 601 and 1000." <<endl;
				index_array_601[location_601] = readin_new;
				length_array_601[location_601] = k;
				location_601++;
			}
			else if((k >= 1001) && (k <= 1500))
			{
				//cout<< "k is between 1001 and 1500." <<endl;
				index_array_1001[location_1001] = readin_new;
				length_array_1001[location_1001] = k;
				location_1001++;
			}
			else if((k >= 1501) && (k <= 2500))
			{
				//cout<< "k is between 1501 and 2500." <<endl;
				index_array_1501[location_1501] = readin_new;
				length_array_1501[location_1501] = k;
				location_1501++;
			}
			else if((k >= 2501) && (k <= 5000))
			{
				//cout<< "k is between 2501 and 5000." <<endl;
				index_array_2501[location_2501] = readin_new;
				length_array_2501[location_2501] = k;
				location_2501++;
			}
			
		}
	}
		
/*		//----------------dynamic_programming--------------------------------------------------------------------
	
	cout<< endl << "Dynamic Programming Output:" <<endl <<endl;
	
	for(int j = 0; j<length_array_0[j] ; j++)
	{
		for(int k = j+1; k<=length_array_0[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_0[j], index_array_0[k], length_array_0[j], length_array_0[k]);
			similarity = lcs_length / length_array_0[j];
			
			if(similarity >= 0.7)
			{
				duplicates_0++;
			}
		}
	}
	cout<< duplicates_0 << " pairs of too similar reviews were found in the bin of length 0 to length 200 reviews." <<endl;
	
	for(int j = 0; j<length_array_201[j] ; j++)
	{
		for(int k = j+1; k<=length_array_201[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_201[j], index_array_201[k], length_array_201[j], length_array_201[k]);
			similarity = lcs_length / length_array_201[j];
			
			if(similarity >= 0.7)
			{
				duplicates_201++;
			}
		}
	}
	cout<< duplicates_201 << " pairs of too similar reviews were found in the bin of length 201 to length 300 reviews." <<endl;
	
	for(int j = 0; j<length_array_301[j] ; j++)
	{
		for(int k = j+1; k<=length_array_301[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_301[j], index_array_301[k], length_array_301[j], length_array_301[k]);
			similarity = lcs_length / length_array_301[j];
			
			if(similarity >= 0.7)
			{
				duplicates_301++;
			}
		}
	}
	cout<< duplicates_301 << " pairs of too similar reviews were found in the bin of length 301 to length 600 reviews." <<endl;
	
	for(int j = 0; j<length_array_601[j] ; j++)
	{
		for(int k = j+1; k<=length_array_601[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_601[j], index_array_601[k], length_array_601[j], length_array_601[k]);
			similarity = lcs_length / length_array_601[j];
			
			if(similarity >= 0.7)
			{
				duplicates_601++;
			}
		}
	}
	cout<< duplicates_601 << " pairs of too similar reviews were found in the bin of length 601 to length 1000 reviews." <<endl;
	
	for(int j = 0; j<length_array_1001[j] ; j++)
	{
		for(int k = j+1; k<=length_array_1001[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_1001[j], index_array_1001[k], length_array_1001[j], length_array_1001[k]);
			similarity = lcs_length / length_array_1001[j];
			
			if(similarity >= 0.7)
			{
				duplicates_1001++;
			}
		}
	}
	cout<< duplicates_1001 << " pairs of too similar reviews were found in the bin of length 1001 to length 1500 reviews." <<endl;
	
	for(int j = 0; j<length_array_1501[j] ; j++)
	{
		for(int k = j+1; k<=length_array_1501[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_1501[j], index_array_1501[k], length_array_1501[j], length_array_1501[k]);
			similarity = lcs_length / length_array_1501[j];
			
			if(similarity >= 0.7)
			{
				duplicates_1501++;
			}
		}
	}
	cout<< duplicates_1501 << " pairs of too similar reviews were found in the bin of length 1501 to length 2500 reviews." <<endl;
	
	for(int j = 0; j<length_array_2501[j] ; j++)
	{
		for(int k = j+1; k<=length_array_2501[k]; k++)
		{
			lcs_length = dynamic_programming(index_array_2501[j], index_array_2501[k], length_array_2501[j], length_array_2501[k]);
			similarity = lcs_length / length_array_2501[j];
			
			if(similarity >= 0.7)
			{
				duplicates_2501++;
			}
		}
	}	
	cout<< duplicates_2501 << " pairs of too similar reviews were found in the bin of length 2501 to length 5000 reviews." <<endl;
	
*/	
	//---------------------------------------------- greedy_algorithm--------------------------------------------------------
	
	cout<< endl << "Greedy Algorithm Output:" <<endl <<endl;
	
	location_0 = 0;
	location_201 = 0;
	location_301 = 0;
	location_601 = 0;
	location_1001 = 0;
	location_1501 = 0;
	location_2501 = 0;
	
	duplicates_0 = 0;
	duplicates_201 = 0;
	duplicates_301 = 0;
	duplicates_601 = 0;
	duplicates_1001 = 0;
	duplicates_1501 = 0;
	duplicates_2501 = 0;
	
	for(int j = 0; j<length_array_0[j] ; j++)
	{
		for(int k = j+1; k<=length_array_0[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_0[j], index_array_0[k], length_array_0[j], length_array_0[k]);
			similarity = lcs_length / length_array_0[j];
			
			if(similarity >= 0.7)
			{
				duplicates_0++;
			}
		}
	}
	cout<< duplicates_0 << " pairs of too similar reviews were found in the bin of length 0 to length 200 reviews." <<endl;
	
	for(int j = 0; j<length_array_201[j] ; j++)
	{
		for(int k = j+1; k<=length_array_201[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_201[j], index_array_201[k], length_array_201[j], length_array_201[k]);
			similarity = lcs_length / length_array_201[j];
			
			if(similarity >= 0.7)
			{
				duplicates_201++;
			}
		}
	}
	cout<< duplicates_201 << " pairs of too similar reviews were found in the bin of length 201 to length 300 reviews." <<endl;
	
	for(int j = 0; j<length_array_301[j] ; j++)
	{
		for(int k = j+1; k<=length_array_301[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_301[j], index_array_301[k], length_array_301[j], length_array_301[k]);
			similarity = lcs_length / length_array_301[j];
			
			if(similarity >= 0.7)
			{
				duplicates_301++;
			}
		}
	}
	cout<< duplicates_301 << " pairs of too similar reviews were found in the bin of length 301 to length 600 reviews." <<endl;
	
	for(int j = 0; j<length_array_601[j] ; j++)
	{
		for(int k = j+1; k<=length_array_601[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_601[j], index_array_601[k], length_array_601[j], length_array_601[k]);
			similarity = lcs_length / length_array_601[j];
			
			if(similarity >= 0.7)
			{
				duplicates_601++;
			}
		}
	}
	cout<< duplicates_601 << " pairs of too similar reviews were found in the bin of length 601 to length 1000 reviews." <<endl;
	
	for(int j = 0; j<length_array_1001[j] ; j++)
	{
		for(int k = j+1; k<=length_array_1001[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_1001[j], index_array_1001[k], length_array_1001[j], length_array_1001[k]);
			similarity = lcs_length / length_array_1001[j];
			
			if(similarity >= 0.7)
			{
				duplicates_1001++;
			}
		}
	}
	cout<< duplicates_1001 << " pairs of too similar reviews were found in the bin of length 1001 to length 1500 reviews." <<endl;
	
	for(int j = 0; j<length_array_1501[j] ; j++)
	{
		for(int k = j+1; k<=length_array_1501[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_1501[j], index_array_1501[k], length_array_1501[j], length_array_1501[k]);
			similarity = lcs_length / length_array_1501[j];
			
			if(similarity >= 0.7)
			{
				duplicates_1501++;
			}
		}
	}
	cout<< duplicates_1501 << " pairs of too similar reviews were found in the bin of length 1501 to length 2500 reviews." <<endl;
	
	for(int j = 0; j<length_array_2501[j] ; j++)
	{
		for(int k = j+1; k<=length_array_2501[k]; k++)
		{
			lcs_length = greedy_algorithm(index_array_2501[j], index_array_2501[k], length_array_2501[j], length_array_2501[k]);
			similarity = lcs_length / length_array_2501[j];
			
			if(similarity >= 0.7)
			{
				duplicates_2501++;
			}
		}
	}
	cout<< duplicates_2501 << " pairs of too similar reviews were found in the bin of length 2501 to length 5000 reviews." <<endl;
		
		/*cout<< "readin = " << readin <<endl;
		cout<< "readin_new = " << readin_new <<endl;
		cout<< "k = " << k <<endl;*/
	return 0;
}