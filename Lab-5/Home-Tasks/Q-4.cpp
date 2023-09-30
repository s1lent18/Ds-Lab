#include <iostream>
#include <vector>
using namespace std;

int Index = 0;

void print(int ** solution, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Parking Location Avaliable at: (" << solution[i][0] << ", " << solution[i][1] << ")";
        
        cout << endl;
    }
    cout << endl;
}


void parking(int ** arr, int row, int col, int rowsize, int colsize, int ** solution)
{
    if(row == rowsize)
    {
        return;
    }

    if(arr[row][col] == 2)
    {
        solution[Index][0] = row;
        solution[Index][1] = col;

        Index++;
    }

    if(col == colsize - 1)
    {
        parking(arr, row + 1, 0, rowsize, colsize, solution);
    }
    else
    {
        parking(arr, row, col + 1, rowsize, colsize, solution);
    }
}

int main()
{
    int rowsize = 0, colsize = 0;
    
    cout << "Enter row size: ";

    cin >> rowsize;

    cout << "Enter col size: ";

    cin >> colsize;

    int ** array = new int*[rowsize];

    int ** sol = new int*[rowsize * colsize];

    for(int i = 0; i < rowsize; i++)
    {
        array[i] = new int [colsize];
    }

    for(int i = 0; i < rowsize * colsize; i++)
    {
        sol[i] = new int[2];
    }

    for(int i = 0; i < rowsize; i++)
    {
        for(int j = 0; j < colsize; j++)
        {
            cin >> array[i][j];
        }
    }

    parking(array, 0, 0, rowsize, colsize, sol);

    print(sol, Index);

}