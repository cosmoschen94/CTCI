//
//  main.cpp
//  reverse
//
//  Created by Siyu Chen on 10/16/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

#include <iostream>
using namespace std;

void reverse(char * str);

void reverse(char * str)
{
    char *p = str;
    unsigned long length = strlen(str);
    char *t = p + (length - 1);
    
    //Base case
    if (length == 1 || length == 0){return;}
    
    // even case
    if (length % 2 == 0 && length != 2)
    {
        char * f = p + (length/2 + 1);
        while (p != f)
        {
            char temp = *p;
            *p = *t;
            *t = temp;
            p++;
            t--;
        }
        return;
    }
    
    // odd case
    else
    {
        char * f = p + (length - 1)/2;
        while (p != f)
        {
            char temp = *p;
            *p = *t;
            *t = temp;
            p++;
            t--;
        }
        return;
    }
    
    
}



int main(int argc, const char * argv[]) {
    
    char * str;
    char s [] ="soccer";
    str = s;
    reverse(str);
    cout << str << "\n";
    
    
}
