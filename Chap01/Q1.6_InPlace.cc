#include <iostream>
#include <stdint.h> // For uint32_t
#include <cstdlib>  // For random
#include <cstdio>   // For printf

using namespace std;

void Rotate90 (uint32_t **matrix, uint32_t m)
{
    if (m <= 1)
    {
        return;     // No need for operation
    }
    
    for (int i = 0 ; i < m / 2 ; i++)
    {
        for (int j = i ; j < m - 1 - i ; j++)
        {
            uint32_t temp = matrix[i][j];
            matrix[i][j] = matrix[m-1-j][i];
            matrix[m-1-j][i] = matrix[m-1-i][m-1-j];
            matrix[m-1-i][m-1-j] = matrix[j][m-1-i];
            matrix[j][m-1-i] = temp;
        }
    }
    
    return;
}

void PrintMatrix (uint32_t **matrix, uint32_t m)
{
    // Print matrix
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            printf ("%d ", matrix[i][j]);
        }
        
        printf ("\n");
    }
}

int main (int argc, char *argv[])
{
    srand (time (NULL));
    
    uint32_t **matrix;
    uint32_t m;
    
    cout << "Input dimensions m: ";
    cin >> m;
    
    // Allocate matrix buffer
    matrix = new uint32_t *[m];
    for (int i = 0 ; i < m ; i++)
    {
        matrix[i] = new uint32_t[m];
    }
    
    // Initialize matrix elements
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            matrix[i][j] = rand () % 10;
        }
    }
    
    cout << endl << "The original matrix:" << endl;
    PrintMatrix (matrix, m);
    cout << endl;
    
    Rotate90 (matrix, m);
    
    cout << endl << "The matrix rotated 90 degrees clockwise:" << endl;
    PrintMatrix (matrix, m);
    cout << endl;
}