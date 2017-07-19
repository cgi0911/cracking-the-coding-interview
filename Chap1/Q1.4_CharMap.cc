#include <iostream>
#include <string>

using namespace std;

bool CheckAnagrams (const string &str1, const string &str2)
{
    if (str1.length () != str2.length ())
    {
        return false;   // Anagrams must be the same length
    }
    
    // Set up two char maps
    int map1[256] = {0};
    int map2[256] = {0};
    
    for (int i = 0 ; i < str1.length () ; i++)
    {
        map1[str1[i]] ++;
        map2[str2[i]] ++;
    }
    
    for (int i = 0 ; i < 256 ; i++)
    {
        if (map1[i] != map2[i])
        {
            return false;
        }
    }
    
    return true;
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