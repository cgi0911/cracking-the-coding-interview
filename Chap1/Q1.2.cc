#include <iostream>
#include <cstring>

using namespace std;

void ReverseCStr (char *cstr)
{
    int slen = strlen (cstr);

    if (slen <= 1)
    {
        return;
    }

    for (int i = 0 ; i < slen / 2 ; i++)
    {
        char temp;
        temp = cstr[i];
        cstr[i] = cstr[slen - i - 1];
        cstr[slen - i - 1] = temp;
    }

    return;
}



int main (int argc, char *argv[])
{
    char myStr[100];
    cout << "Input your string (max 100 chars): ";
    cin.getline (myStr, 100);

    cout << "Original string: " << myStr << endl;

    ReverseCStr (myStr);

    cout << "Reversed string: " << myStr << endl;

    return 0;
}
