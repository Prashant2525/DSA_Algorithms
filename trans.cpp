// Transtivity Closure

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of rows and column (n, n): ";
    cin >> n;

    int graph[n][n] = {0};

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout<<"Enter element for graph["<<i<<"]["<<j<<"]: ";
            cin>>graph[i][j];
        }
    }

    int result[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    result[i][j] = result[i][j] || (result[i][k] && result[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}