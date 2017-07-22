#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
    int k;
    cout << "How many lines at the end of file do you want to print? ";
    cin >> k;
    
    ifstream inFile ("./Q13.1.txt");
    int numlines = 0;
    string temp;
    
    // Count lines
    while (getline (inFile, temp)) {
        numlines++;
    }
    
    if (k > numlines) {
        cout << "The file is insufficiently long!" << endl;
        k = numlines;
    }
    
    // Reset the ifstream
    inFile.clear ();    // Clear eof flag
    inFile.seekg (0);
    
    int skiplines = numlines - k;
    
    for (int i = 0 ; i < skiplines ; i++) {
        getline (inFile, temp);
    }
    
    cout << "Printing..." << endl;
    
    while (getline (inFile, temp)) {
        cout << temp << endl;
    }
    
    return 0;
}