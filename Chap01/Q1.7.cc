#include <iostream>
#include <stdint.h> // For uint32_t
#include <cstdlib>  // For random
#include <cstdio>   // For printf

using namespace std;

void ZeroRowCol (uint32_t **matrix, uint32_t m, uint32_t n)
{
    bool *rowZero = new bool[m];
    bool *colZero = new bool[n];
    
    for (int i = 0 ; i < m ; i++) {rowZero[i] = false;}
    for (int i = 0 ; i < n ; i++) {colZero[i] = false;}
    
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowZero[i] = true;
                colZero[j] = true;
            }
        }
    }
    
    for (int i = 0 ; i < m ; i++)
    {
        if (rowZero[i])
        {
            for (int j = 0 ; j < n ; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int i = 0 ; i < n ; i++)
    {
        if (colZero[i])
        {
            for (int j = 0 ; j < m ; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    
    return;
}

void PrintMatrix (uint32_t **matrix, uint32_t m, uint32_t n)
{
    // Print matrix
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            printf ("%2d ", matrix[i][j]);
        }
        
        printf ("\n");
    }
}

int main (int argc, char *argv[])
{
    srand (time (NULL));
    
    uint32_t **matrix;
    uint32_t m, n;
    
    cout << "Input dimensions m: ";
    cin >> m;
    cout << "Input dimensions n: ";
    cin >> n;
    
    // Allocate matrix buffer
    matrix = new uint32_t *[m];
    for (int i = 0 ; i < m ; i++)
    {
        matrix[i] = new uint32_t[n];
    }
    
    // Initialize matrix elements
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            matrix[i][j] = rand () % 10;
        }
    }
    
    cout << endl << "The original matrix:" << endl;
    PrintMatrix (matrix, m, n);
    cout << endl;
    
    ZeroRowCol (matrix, m, n);
    
    cout << endl << "The processed matrix:" << endl;
    PrintMatrix (matrix, m, n);
    cout << endl;
}