#include <iostream>
using namespace std;

int count = 0;
int ** best;
int beststeps = 1000;

void printsolution(int ** arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int ** arr, int r, int c, int size)
{
    if(r >= 0 && c >= 0 && r < size && c < size && arr[r][c] == 1)
    {
        return true;
    }
    return false;
}

bool ratinamaze(int ** arr, int row, int col, int size, int ** solution, int steps)
{
    if(row == (size - 1) && (col == (size - 1)))
    {   
        count++; 

        solution[row][col] = 1;

        if(beststeps > steps)
        {
            beststeps = steps;

            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    best[i][j] = solution[i][j];
                }
            }
        }

        cout << "Solution Number: " << count << endl;

        printsolution(solution, size);

        solution[row][col] = 0;

        return 1;
    }

    if(isSafe(arr, row, col, size))
    {
        solution[row][col] = 1;

        if(ratinamaze(arr, row + 1, col, size, solution, steps + 1))
        {

        }

        if(ratinamaze(arr, row, col + 1, size, solution, steps + 1))
        {

        }

        solution[row][col] = 0;

        return false;
    }
    return false;
}

int main()
{
    cout << "Enter the size of the maze: ";

    int size = 0; 

    cin >> size;

    int ** array = new int * [size];

    int ** solution = new int * [size];

    best = new int * [size];

    for(int i = 0; i < size; i++)
    {
        array[i] = new int [size];

        solution[i] = new int [size];

        best[i] = new int [size];

    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> array[i][j];
        }
    }

    ratinamaze(array, 0, 0, size, solution, 0);

    cout << "The optimal path in all of the above is: " << endl;
    
    printsolution(best, size);
}