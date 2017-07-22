#include <iostream>
#include <cstring>

using namespace std;

void DeDup (char *inStr)
{
    int slen = strlen (inStr);
    
    if (slen <= 1)
    {
        // String too short. No need to dedup.
        return;
    }
    
    int tail = 1;   // Tail of the string
    
    for (int i = 1 ; i < slen ; i++)
    {
        bool isDup = false;
        
        for (int j = 0 ; j < tail ; j++)
        {
            if (inStr[i] == inStr[j])
            {
                isDup = true;
                break;
            }
        }
        
        if (!isDup)
        {
            inStr[tail] = inStr[i];
            tail++;
        }
    }
    
    inStr[tail] = 0;    // Don't forget to write '\0' at the end!
    
    return;
}


int main (int argc, char *argv[])
{
    char *myStr = new char[1000];
    
    cout << "Input your string: ";
    cin.getline (myStr, 1000);   // getline to a C-style string.
    
    cout << "The original string: " << myStr << endl;
    
    DeDup (myStr);
    
    cout << "The deduped string: " << myStr << endl;
    
    return 0;
}