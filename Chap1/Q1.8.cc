#include <iostream>
#include <string>

using namespace std;

bool CheckRotation (const string &str1, const string &str2)
{
    if (str1.length () != str2.length ())
    {
        return false;   // Two rotation strings must be equal length!
    }
    
    string concat = str2 + str2;    // Concatenate str2 twice
    
    size_t found = concat.find (str1);
    
    if (found != string::npos)
    {
        return true;    // str1 found in the concatenated string
    }
    
    else
    {
        return false;
    }
}



int main (int argc, char *argv[])
{
    string str1, str2;
    
    cout << "Input string 1: ";
    getline (cin, str1);
    cout << "Input string 2: ";
    getline (cin, str2);
    
    bool isRotation = CheckRotation (str1, str2);
    
    cout << "Two strings are rotation? " << isRotation << endl;
    
    return 0;
}