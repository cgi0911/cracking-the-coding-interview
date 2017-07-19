#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool CheckAnagrams (const string &str1, const string &str2)
{
    if (str1.length () != str2.length ())
    {
        return false;   // Anagrams must be the same length
    }
    
    string cpstr1 = str1;
    string cpstr2 = str2;
    
    sort (cpstr1.begin (), cpstr1.end ());
    sort (cpstr2.begin (), cpstr2.end ());
    
    if (cpstr1 == cpstr2)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}



int main (int argc, char *argv[])
{
    string str1, str2;
    
    cout << "Input string #1: ";
    getline (cin, str1);
    cout << "Input string #2: ";
    getline (cin, str2);
    
    bool isAnagrams = CheckAnagrams (str1, str2);
    
    cout << "The two strings are anagrams? " << isAnagrams <<endl;
    
    return 0;
}