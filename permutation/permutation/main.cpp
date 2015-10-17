//
//  main.cpp
//  permutation
//
//  Created by Siyu Chen on 10/16/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

/*
    1.3 check permutation between two strings
    
    Key question: whether the permutation comparison
    is case sensitive and if white space is significant.
    
    Key point:

    1. pre-increment is prefered comparing to post-increment 
    when i is a instance of a C++ class.
    2. dynamic 2D array is essantially an array of pointers 
    to arrays
    3. deallocation to prevent memory leak
 
*/


#include <iostream>
using namespace std;

bool perm(string a, string b);

bool perm(string a, string b)
{
    // test
    //cout << a.length() << "\n";
    //cout << b.length() << "\n";

    
    // base cases
    if (a.length() != b.length()){return false;}
    if (a == b){return true;}
    
    // allocate dynamic 2D array
    int ** p;
    p = new int*[256];
    for (int i=0; i<256; ++i)
    {
        p[i] = new int[2]();
    }
    
    // count char for each string
    for(int i = 0; i < a.length(); ++i)
    {
        int va = a[i];
        int vb = b[i];
        //cout << va << "\t" << vb << "\n";
        p[va][0] += 1;
        p[vb][1] += 1;
    }
    
    
    //cout << "Seperation======================" << "\n";
    
    // compare count
    for (int i = 0; i<256; ++i)
    {
        //cout << p[i][0] << "\t" << p[i][1];
        //cout << "\n";
        if(p[i][0]!=p[i][1]){return false;}
    }
    
    // deallocation
    for (int i=0; i < 256; ++i)
    {
        delete [] p[i];
    }
    delete [] p;
    
    return true;
    
}

int main(int argc, const char * argv[]) {
    
    string a = "abcDa  d";
    string b = "abcdad  ";
    bool test = perm(a,b);
    cout << test << "\n";
    
}
