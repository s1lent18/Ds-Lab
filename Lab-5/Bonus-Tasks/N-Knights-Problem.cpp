#include <iostream>
using namespace std;

void printSolution(int ** arr, int temp)
{
    for(int i = 0; i < temp; i++)
    {
        for(int j = 0 ; j < temp; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int ** array, int row, int col, int numberofsquares)
{
    int row_inc_2 = row + 2;
    int row_inc_1 = row + 1;
    int row_dec_2 = row - 2;
    int row_dec_1 = row - 1;

    int col_inc_2 = col + 2;
    int col_inc_1 = col + 1;
    int col_dec_2 = col - 2;
    int col_dec_1 = col - 1;
    
    if (row_inc_2 < numberofsquares && col_dec_1 >= 0)
    {
        if(array[row_inc_2][col_dec_1] == 1)
        {
            return false;
        }
    }
    else if(row_inc_2 < numberofsquares && col_inc_1 < numberofsquares)
    {
        if(array[row_inc_2][col_inc_1] == 1)
        {
            return false;
        }
    }
    else if(row_dec_2 >= 0 && col_dec_1 >= 0)
    {
        if(array[row_dec_2][col_dec_1] == 1)
        {
            return false;
        }
    }
    else if(row_dec_2 >= 0 && col_inc_1 < numberofsquares)
    {
        if(array[row_dec_2][col_inc_1] == 1)
        {
            return false;
        }
    }
    if (row_inc_1 < numberofsquares && col_dec_2 >= 0)
    {
        if(array[row_inc_1][col_dec_2] == 1)
        {
            return false;
        }
    }
    else if(row_inc_1 < numberofsquares && col_inc_2 < numberofsquares)
    {
        if(array[row_inc_1][col_inc_2] == 1)
        {
            return false;
        }
    }
    else if(row_dec_1 >= 0 && col_dec_2 >= 0)
    {
        if(array[row_dec_1][col_dec_2] == 1)
        {
            return false;
        }
    }
    else if(row_dec_1 >= 0 && col_inc_2 < numberofsquares)
    {
        if(array[row_dec_1][col_inc_2] == 1)
        {
            return false;
        }
    }
    else if(array[0][0] == 1)
    {
        return false;

    }
    return true;
}

bool nKnights(int ** array, int numberofknights, int numberofsquares, int numberofknightstobeplaced)
{
    if(numberofknights == numberofknightstobeplaced)
    {
        printSolution(array, numberofsquares);

        return true;
    }

    for(int row = 0; row < numberofsquares; row++)
    {
        for(int col = 0; col < numberofsquares; col++)
        {
            if(isSafe(array, row, col, numberofsquares))
            {
                array[row][col] = 1;

                if(nKnights(array, numberofknights + 1, numberofsquares, numberofknightstobeplaced))
                {
                    return true;
                }

                array[row][col] = 0;                
            }
        }
    }
    return false;
}

int main()
{
    int temp = 0;

    cin >> temp;

    int ** arr = new int * [temp];

    for(int i = 0; i < temp; i++)
    {
        arr[i] = new int[temp];
    }

    for(int i = 0; i < temp; i++)
    {
        for(int j = 0; j < temp; j++)
        {
            arr[i][j] = 0;
        }
    }

    printSolution(arr, temp);

    cout << endl << endl;
    
    int sq = temp * temp;

    if(sq % 2 == 0)
    {
        sq /= 2;
    }
    else
    {
        sq += 1;

        sq /= 2;
    }

    nKnights(arr, 0, temp, sq);
}