#include <iostream>
#include <string>
#include <stdint.h>  // for uint32_t

using namespace std;

bool CheckAllUniqueChars (const string &inStr)
{
    if (inStr.length () == 0)
    {
        return true;
    }

    uint32_t bitmap[8] = {0};   // We need 8 32-bit unsigned integers for the bitmap

    for (int i = 0 ; i < inStr.length () ; i++)
    {
        int byteLoc = (int) inStr[i] / 32;
        int bitLoc = (int) inStr[i] % 32;

        int getbit = bitmap[byteLoc] & (1 << bitLoc);   // Get the bit

        if (getbit)
        {
            return false;
        }

        else
        {
            bitmap[byteLoc] |= (1 << bitLoc);   // Set the bit
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

    return 0;
}

