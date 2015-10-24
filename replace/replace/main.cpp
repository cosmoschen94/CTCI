//
//  main.cpp
//  replace
//
//  Created by Siyu Chen on 10/23/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

#include <iostream>
//#include <stdio.h>
//#include <string.h>

using namespace std;

string replace(string str, int n);

string replace(string str, int n)
{
    //string temp = str;
    string value =""; //empty string
    if (n == 0 || str.length() == 0)
    {return value;}
    
    for (int i=0; i < n; ++i)
    {
        char temp = str[i];
        if (isspace(temp)) //space
        {
            value += "%20";
        }
        else{
            value += temp;
        }
    }
    
    return value;
}



int main(int argc, const char * argv[]) {
    
    string a = "Mr  John Smith n     ";
    string b = replace(a,16);
    cout << b << "\n";
    cout << b.length() << "\n";
    
}
