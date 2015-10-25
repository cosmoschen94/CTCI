//
//  main.cpp
//  compress
//
//  Created by Siyu Chen on 10/25/15.
//  Copyright © 2015 Siyu Chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

bool isEmpty(node *head);
void insertAsFirstElement(node *&head, node *&last);
void insert(node *&head, node *&last);
void remove(node *&head);
void incre(node *&current);
node *tail(node *&head);
string compress(string str);



bool isEmpty(node *head)
{
    if (head == NULL)
        return true;
    return false;
}

void insertAsFirstElement(node *&head, node *&last)
{
    node *temp = new node;
    temp->data = 1;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert(node *&head, node *&last)
{
    if (isEmpty(head))
        insertAsFirstElement(head, last);
    else{
        node *temp = new node;
        temp->data = 1;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void remove(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void incre(node *&current)
{
    current->data += 1;
}

node *tail(node *&head)
{
    node *temp = new node;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

string compress(string str)
{
    node **p;
    p = new node*[58];
    for (int i=0; i < 58; ++i)
    {
        p[i]->next = NULL;
    }
    
    unsigned long size = str.length();
    
    for (int i=0; i < size; ++i)
    {
        int temp = str[i] - 65;
        node * t = new node;
        t = p[temp];
        node *last = new node;
        last = tail(p[temp]);
        if (i==0)
        {
            insert(p[temp],last);
            continue;
        }
        if(temp == str[i-1]-65)
        {
            incre(last);
        }
        if(temp != str[i-1]-65)
        {
            insert(p[temp],last);
        }
    }
    
    string newstr = "";
    for (int i=0; i < size; ++i)
    {
        int temp = str[i]-65;
        char t = str[i];
        node *s = new node;
        s = p[temp];
        if (i==0)
        {
            newstr += t;
            newstr += s->data;
            remove(s);
            continue;
        }
        
        if (temp == str[i-1]-65)
        {
            continue;
        }
        
        if (temp != str[i-1]-65)
        {
            newstr += t;
            newstr += s->data;
            remove(s);
            continue;
        }
    }
    
    if (newstr.length() > size)
    {
        return str;
    }
    else{
        return newstr;
    }
        

}


int main(int argc, const char * argv[]) {
    
    string a = "aabcccccaaa";
    string b = compress(a);
    cout << b << endl;
}
