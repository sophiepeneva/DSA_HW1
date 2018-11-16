# DSA_HW1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string removeChar(string myString, char a) 
{
    bool removed = false;
    string newString;
    for (int i = 0;i < myString.length();i++) 
    {
        if (removed == true || myString[i] != a)newString += myString[i];
        if (myString[i] == a)removed = true;
    }
    return newString;
}

string LongestSubstrign(string a, string b) 
{
    string substring;
    int length = (a.length() > b.length() ? a.length() : b.length());
    if (length == a.length())
    {
        for (int i = 0;i < a.length();i++)
        {
            if (b.find(a[i]) != string::npos) 
            {
                substring += a[i];
                b = removeChar(b, a[i]);
            }
        }
    }
    else 
    {
        for (int i = 0;i < b.length();i++)
        {
            if (a.find(b[i]) != string::npos)
            {
                substring += b[i];
                a = removeChar(a, b[i]);
            }
        }
    }
    return substring;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string a, b;
    cin >> a >> b;
    string substr = LongestSubstrign(a, b);
    sort(substr.begin(), substr.end());
    cout << substr;
    
    return 0;
}
