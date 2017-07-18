#include <iostream>
#include <string>

using namespace std;

bool CheckAllUniqueChars (const string &inStr)
{
    if (inStr.length () == 0)
    {
        return true;
    }

    bool charFlags[256] = {0};    // Flag is true when character is used

    for (int i = 0 ; i < inStr.length () ; i++)
    {
        if (charFlags[(int) inStr[i]])
        {
            return false;
        }

        else
        {
            charFlags[(int) inStr[i]] = true;
        }
    }

    return true;
}

int main (int argc, char *argv[])
{
    string myStr;

    cout << "Input your string: ";
    getline (cin, myStr);

    cout << "The input string is: " << myStr << endl;

    bool isAllUniqueChars = CheckAllUniqueChars (myStr);

    cout << "Is the input string using all-unique chars? " << isAllUniqueChars << endl;
}
