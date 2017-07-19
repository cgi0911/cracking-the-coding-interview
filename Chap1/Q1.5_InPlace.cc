#include <iostream>
#include <cstring>

using namespace std;

void ReplaceSpaces (char *inStr, int buflen)
{
    int oldlen = strlen (inStr);
    int newlen = oldlen;
    
    for (int i = 0 ; i < oldlen ; i++)
    {
        if (inStr[i] == ' ')
        {
            newlen += 2;
        }
    }
    
    if (newlen > buflen)
    {
        return;     // Not enough buffer
    }
    
    inStr[newlen] = 0;  // New null char position
    int writer = newlen - 1;
    
    for (int i = oldlen - 1 ; i >= 0 ; i--)
    {
        if (inStr[i] == ' ')
        {
            inStr[writer] = '0';
            inStr[writer - 1] = '2';
            inStr[writer - 2] = '%';
            writer -= 3;
        }
        else
        {
            inStr[writer] = inStr[i];
            writer --;
        }
    }
    
    return;
}


int main (int argc, char *argv[])
{
    char *myStr = new char[1000];
    cout << "Input your string: ";
    cin.getline (myStr, 1000);
    
    cout << "The original string:  " << myStr << endl;
    
    ReplaceSpaces (myStr, 1000);
    
    cout << "The processed string: " << myStr << endl;
    
    return 0;
}