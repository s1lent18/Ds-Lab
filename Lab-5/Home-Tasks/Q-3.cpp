#include <iostream>
using namespace std;

void print(int ** arr, int rowsize, int colsize)
{
    cout << endl;

    for(int i = 0; i < rowsize; i++)
    {
        for(int j = 0; j < colsize; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

bool isSafe(int ** arr, int row, int col, int rowsize, int colsize)
{
    if(row >= 0 && col >= 0 && row < rowsize && col < colsize && arr[row][col] == 1)
    {
        return true;
    }
    return false;
}

bool q3(int ** arr, int row, int col, int rowsize, int colsize, int ** solution)
{
    if(row == (0) && (col == (colsize - 1)))
    {
        solution[row][col] = 1;

        print(solution, rowsize, colsize);

        return 1;
    }

    if(isSafe(arr, row, col, rowsize, colsize) && solution[row][col] != 1)
    {
        solution[row][col] = 1;

        if(q3(arr, row, col + 1, rowsize, colsize, solution))
        {
            return 1;
        }
        if(q3(arr, row + 1, col, rowsize, colsize, solution))
        {
            return 1;
        }
        if(q3(arr, row - 1, col, rowsize, colsize, solution))
        {
            return 1;
        }
        if(q3(arr, row, col - 1, rowsize, colsize, solution))
        {
            return 1;
        }

        solution[row][col] = 0;

        return false;
    }
    return false;
}

int main()
{
    int rowsize = 0, colsize = 0;
    
    cout << "Enter the size for you want for rows: ";

    cin >> rowsize;

    cout << "Enter the size for you want for column: ";

    cin >> colsize;

    int ** array = new int* [rowsize];

    int ** sol = new int* [rowsize];

    for(int i = 0; i < rowsize; i++)
    {
        array[i] = new int[colsize];

        sol[i] = new int[colsize];
    }

    for(int i = 0; i < rowsize; i++)
    {
        for(int j = 0; j < colsize; j++)
        {
            cin >> array[i][j];
        }
    }

    if(!q3(array, 0, 0, rowsize, colsize, sol))
    {
        cout << "No Solution" << endl;
    }

}
    