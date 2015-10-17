//
//  main.cpp
//  reverse
//
//  Created by Siyu Chen on 10/16/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

#include <iostream>
using namespace std;


/*
    1.2 reverse null-terminated string
    In C++, 
    strlen(): returns the length of given byte NOT including null terminator "\0"
    sizeof(): returns the length of given byte including null terminator "\0"
    Moreover,
    strlen() -> unsigned long
    sizeof() -> int
*/


void reverse(char * str);

void reverse(char * str)
{
    // head pointer pointing to the first char of the string
    char *p = str;
    unsigned long length = strlen(str);
    
    // tail pointer pointing to the last char of the string(the char right before null terminator)
    char *t = p + (length - 1);
    
    //Base case
    if (length == 1 || length == 0){return;}
    
    // even case
    if (length % 2 == 0 && length != 2)
    {
        // flag pointer pointing to the middle of the string
        char * f = p + (length/2);
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
        // flag pointer pointing to the middle of the string
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
    char s [] ="123456789001111111000000000";
    str = s;
    reverse(str);
    cout << str << "\n";
    
    
}
