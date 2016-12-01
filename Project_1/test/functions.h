#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;
#include<iostream>

//Description:     Generates a random number corresponding to the ascii value of a character or number.    
//Preconditions:   none.
//Postconditions:  Returns a random number.  
char generate_char();

//Description:     Generates a random string.    
//Preconditions:   none.
//Postconditions:  Returns a random string.  
string create_string(int length);

//Description:     Finds the lcs using dynamic programming.    
//Preconditions:   .
//Postconditions:  .  
int dynamic_programming(string str_1, string str_2, int length_1, int length2);

//Description:     Finds the lcs using a greedy algorithm.    
//Preconditions:   .
//Postconditions:  .  
int greedy_algorithm(string str_1, string str_2, int length_1, int length_2);

#endif