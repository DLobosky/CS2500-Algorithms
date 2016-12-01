//#include<iostream>
#include"functions.h"
using namespace std;

#include<cstdlib>
#include<ctime>
#include<string>

char generate_char()
{
	
	//? float similarity;
	//? int lcs_length;
	
	//srand(time(0));
	//srand(time(NULL));
	
	int x = 0;
	//int y = 0;

	x = (rand() % 3);
	
	//cout<< "x from 0 to 2 is " << y <<endl;
	
	if(x == 0)
	{
		return rand() % 26 + 65; // capital letters
		
		//cout<< "x from 64 to 90 is " << y <<endl;
		//cout<< "The random Capital letter is " << (char)y <<endl;
	}
	else if(x == 1)
	{
		return rand() % 26 + 97; // lowercase letters
		
		//cout<< "x from 97 to 122 is " << y <<endl;
		//cout<< "The random lower case letter is " << (char)y <<endl;
	}
	else if(x == 2)
	{
		return rand() % 10 + 48; // numbers
		
		//cout<< "x from 48 to 57 is " << y <<endl;
		//cout<< "The random number is " << (char)y <<endl;
	}
	else
	{
		cout<< "ERROR: x from 0 to 1 is " << x <<endl;
		return 0;
	}

}
		
	//////////////////////////////////////////////////////////////////////
	//String testing.
	//////////////////////////////////////////////////////////////////////
	
	/*string str ("Jason Beard");
	
	char cha = 'Q';
	
	for(int i = 10; i >= 0; i--)
	{
		cout<< str[i];
	}
	
	cout<< str <<endl;
	
	str += cha;
	
	cout<< str <<endl;*/
	
	//////////////////////////////////////////////////////////////////////

string create_string(int length)
{
	string my_str ("");
	char my_char;
	
	for(int i = 0; i < length; i++)
	{
		my_char = (char)generate_char();
		my_str += my_char;
	}
	return my_str;
}

int dynamic_programming(string str_1, string str_2, int length_1, int length_2)
{
	//SOLVE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//int grid[length_1 + 1][lenght_2 + 1];
	
	//int grid[100][100];
	
	//int* grid[length_1 + 1][length_2 + 1];
	
	int lcs_length = 0;
	int** grid = new int*[length_2 + 1];
	
	cout<< "check 1" <<endl;
	
	for(int i = 0; i <= length_2; i++)
	{
		grid[i] = new int[length_1 + 1];
	}
	
	cout<< "check 2" <<endl;
	
	cout<< "length_1 = " << length_1 <<endl;
	
	cout<< "length_2 = " << length_2 <<endl;
	
	//grid[][] = 0;
	
	//Builds the grid used to find the LCS.				//maybe switch length_2 and length_1?
	for(int j = 0; j <= length_2; j++)
   {
     for(int i = 0; i <= length_1; i++)
     {
	   grid[i][j] = 0;
	   //grid[26][97] = 4;
	   
       if(i == 0 || j == 0)
	   {
         grid[i][j] = 0;
	   }
       else if(str_1[i-1] == str_2[j-1])
	   {
         grid[i][j] = grid[i-1][j-1] + 1;
	   }
       else
	   {
         grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
	   }
	   
	   //cout<< /*grid[i][j] <<*/ "i = " << i << " ";
	   cout<< grid[i][j] << " ";
     }
     //cout<< "	j = " << j <<endl << endl;
	 cout<< endl;
   }
     
	cout<< "check 2.25 before set index" <<endl;
	
	cout<< "length_1 = " << length_1 <<endl;
	
	cout<< "length_2 = " << length_2 <<endl;
	
	//grid[26][97] = 4;
	
	//cout<< "grid[26][97] = " << grid[26][97] << endl;
	
   int index = grid[length_1][length_2];
   lcs_length = index;
   
   cout<< "index = " << index << endl;
 
   // Character array to store the lcs.
   //SOLVE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //char lcs[index+1];
   
   //char lcs[100];
   
   
   //int index = 10;///REMOVE THIS-------------------------------------------------------------------------------------------------------------------------///
   char* lcs = new char[index + 1];
   /*
   lcs[index] = '\0';
 
   // Start at bottom right corner and adds common characters to lcs array.
   int i = length_1, j = length_2;
   while (i > 0 && j > 0)
   {
      if(str_1[i-1] == str_2[j-1])
      {
          lcs[index-1] = str_1[i-1]; 
          i--; j--; index--;     
      }
       else if(grid[i-1][j] > grid[i][j-1])
	   {
         i--;
	   }
      else
	  {
         j--;
	  }
   }*/
 
   // Print the lcs
   //cout << "LCS of " << str_1 << " and " << str_2 << " is " << lcs << " and has a length of " << lcs_length <<endl;	
   cout<< "check 2.5" <<endl;
   
   delete [] lcs;
   
   cout<< "check 3" <<endl;
   
   for(int i = 0; i <= length_2; i++)
   //for(int i = length_2; i >= 0; i--)
   {
	   cout<< "check 4" <<endl;
	   delete [] grid[i];
	   cout<< "check 5" <<endl;
   }
   delete [] grid;
   
   cout<< "check 6 " << lcs_length <<endl;
   
   return lcs_length;
}

//--------------------------------------------greedy_algorithm------------------------------------------------------------

int greedy_algorithm(string str_1, string str_2, int length_1, int length_2)
{
		int incr = 0;
		int c[62][2];
		string str_2_prime = "";
		string str_1_prime = "";
		int length_2_prime = 0;
		int length_1_prime = 0;
		string lcs_1 = "";
		string lcs_2 = "";
		int lcs_1_length = 0;
		int lcs_2_length = 0;
		int j = 0;
		int i = 0;
		
		for(int i = 0; i < 62; i++)
		{
			c[i][1] = 0;
		}
		
		for(int i = 0; i < 10; i++) // numbers first in c (0-9)
		{
			incr = 48 + i;
			c[i][0] = incr;
		}
		
		for(int i = 0; i < 26; i++) // Capital Letters next in c (10-35)
		{
			incr = 65 + i;
			c[10+i][0] = incr;
		}
		
		for(int i = 0; i < 26; i++) // Lower case letters next in c (36-62)
		{
			incr = 97 + i;
			c[36+i][0] = incr;
		}
		
		/*for(int i = 0; i < 62; i++) // Practice print c (0-62)
		{
			cout << (char)c[i][0] << " " << c[i][1] << endl;
		}*/
		
		
		for(int i = 0; i < length_1; i++) // fill c with values from str_1
		{			
			for(int j = 0; j < 62; j++)
			{
				if(str_1[i] == (char)c[j][0])
				{
					//cout<< "HERE. j = " << j << " " << (char)c[j][0] <<endl;
					c[j][1] = 1;
					break;
				}
			}
		}		
		
		//verafied c array was filled correctly
		/*for(int j = 0; j < 62; j++)
		{
			cout<< "j = " << j << " " << c[j][1] <<endl;
		}*/
		
		for(int i = 0; i < length_2; i++) // makes str_2_prime
		{			
			for(int j = 0; j < 62; j++)
			{
				if((str_2[i] == (char)c[j][0]) && (c[j][1] == 1))
				{
					str_2_prime += str_2[i];
					length_2_prime++;
				}
			}
		}
		
		/*//verafied that str_2_prime was made correctly
		for(int j = 0; j < length_2_prime; j++)
		{
			cout<< str_2_prime[j] <<endl;
		}*/

		for(int i = 0; i < 62; i++) // reset c to all zeros
		{
			c[i][1] = 0;
		}		
		
		for(int i = 0; i < length_2_prime; i++) // fills new c with values from str_2_prime
		{			
			for(int j = 0; j < 62; j++)
			{
				if(str_2_prime[i] == (char)c[j][0])
				{
					c[j][1] = 1;
					break;
				}
			}
		}

		/*//verafied c array was filled correctly
		for(int j = 0; j < 62; j++)
		{
			cout<< "j = " << j << " " << c[j][1] <<endl;
		}*/	
		
		for(int i = 0; i < length_1; i++) // makes str_1_prime
		{			
			for(int j = 0; j < 62; j++)
			{
				if((str_1[i] == c[j][0]) && (c[j][1]) == 1)
				{
					str_1_prime += str_1[i];
					length_1_prime++;
				}
			}
		}
		
		/*//verafied that str_1_prime was made correctly
		for(int j = 0; j < length_1_prime; j++)
		{
			cout<< str_1_prime[j] <<endl;
		}*/
		
		j = 0;
		i = 0;
		
		while(i < length_1_prime && j < length_2_prime) //finds one possible lcs
		{
			//if(j < length_2_prime)
			//{
				if(str_1_prime[i] == str_2_prime[j])
				{
					lcs_1 += str_1_prime[i];
					lcs_1_length++;
					i++;
				}
				j++;
			//}
		}
		
		j = 0;
		i = 0;
		
		while(i < length_1_prime && j < length_2_prime) //finds another possible lcs
		{
			//if(j < length_2_prime)
			//{
				if(str_1_prime[i] == str_2_prime[j])
				{
					lcs_2 += str_2_prime[j];
					lcs_2_length++;
					j++;
				}
				i++;
			//}
		}
		
		/*cout<< "string one is " << str_1 <<endl;
		cout<< "string two is " << str_2 <<endl <<endl;
		
		cout<< "string one prime is " << str_1_prime <<endl;
		cout<< "string two prime is " << str_2_prime <<endl <<endl;*/
		
		if(lcs_1_length >= lcs_2_length)
		{
			//cout<< "The lcs is " << lcs_1 << " and has a length of " <<lcs_1_length <<endl;
			return lcs_1_length;
		}
		else
		{
			//cout<< "The lcs is " << lcs_2 << " and has a length of " <<lcs_2_length <<endl;
			return lcs_2_length;
		}
		
		//cout<< "The lcs is " << lcs_1 << " and has a length of " <<lcs_1_length <<endl;
		//cout<< "The lcs is " << lcs_2 << " and has a length of " <<lcs_2_length <<endl;
}






















