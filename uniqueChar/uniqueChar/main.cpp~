//
//  main.cpp
//  uniqueChar
//
//  Created by Siyu Chen on 10/16/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

#include <iostream>
using namespace std;


/*
 This problem test our knowledge of ASCII code and Unicode,
 array and bit manipulation. The solution that uses least space
 is to do bit manipulation.
 */


bool unique(string str);


/*
 1. initialize array of size n with all 0s
 int array[n] = {0};
 2. initialize dynamically allocated array
 type *array;
 array = new type[];
 3. free allocated memory
 delete [] array;
 
 */



bool unique(string str)
{
    //base cases
    if (str.length() > 128) return false;
    if (str.length() == 0 || str.length() == 1)
    {
        return true;
    }
    
    //allocate array dynamically
    bool *hash;
    hash = new bool[256];
    
    for (int i = 0; i<str.length();i++)
    {
        int value = str[i];
        
        //this char already found
        if(hash[value]){
            return false;
        }
        
        //raise flag
        hash[value] = true;
    }
    
    //free allocated memory
    delete [] hash;
    
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    if (unique("abcdefghijklmnopqr[")==true)
    {
        cout << "The string has all unique characters\n";
    }
    else{
        cout << "The string has repeated characters\n";
    }
}
