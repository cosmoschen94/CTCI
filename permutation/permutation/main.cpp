//
//  main.cpp
//  permutation
//
//  Created by Siyu Chen on 10/16/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

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
        p[i] = new int[2];
    }
    
    // count char for each string
    for(int i = 0; i < a.length(); ++i)
    {
        int va = a[i];
        int vb = b[i];
        cout << va << "\t" << vb << "\n";
        p[va][0] += 1;
        p[vb][1] += 1;
    }
    
    
    cout << "Seperation======================" << "\n";
    
    // compare count
    for (int i = 0; i<256; ++i)
    {
        cout << p[i][0] << "\t" << p[i][1];
        cout << "\n";
        if(p[i][0]!=p[i][1]){return false;}
    }
    
    // deallocation
    for (int i=0; i < 256; ++i)
    {
        delete [] p[i];
    }
    delete [] p;
    
    return true;
    
    /*
    int * hash;
    hash = new int[256]{0};
    //hash[256]={false};

    for (int i=0; i < a.length(); i++)
    {
        int value = a[i];
        if (hash[value] == 0)
        {
            hash[value] += 2;
        }
        else if (hash[value] > 0)
        {
            hash[value] += 1;
        }
    }
    
    for (int i=0; i < b.length(); i++)
    {
        int value = b[i];
        
        //cout << hash[value] << "\n";
        
        if (hash[value] == 0)
        {
            return false;
        }
        hash[value] -= 1;
    }
    
    for (int i=0; i < b.length(); i++)
    {
        int value = b[i];
        if(hash[value] > 1)
        {
            return false;
        }
    }
        */
}

int main(int argc, const char * argv[]) {
    
    string a = "abcdad";
    string b = "bddaada";
    bool test = perm(a,b);
    cout << test << "\n";
    
}
