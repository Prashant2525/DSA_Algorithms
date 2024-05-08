
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5, index, max = 5, i, j;
    FILE *fnew;
    int a[5][5];
    if ((fnew = fopen("data6.txt", "r")) == NULL)
        cout << "Can not open the data file\n";
    else
    {
        for (i = 0; i < max; i++)
        {
            for (j = 0; j < max; j++)
            {
                fscanf(fnew, "%d", &a[i][j]);
            };
        };
    } // else
    cout << "Initial matrix" << endl;
    // Show the initial weight matrix
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Topological order:\n";
    int indegree[10] = {0}; // at first all index values are 0
    // in degree holds the indegree value of each nodes
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
                indegree[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (indegree[j] == 0)
            {
                cout << j << " "; // Update in-degrees after removing this node
                for (int k = 0; k < n; k++)
                {
                    if (a[j][k] == 1)
                        indegree[k]--;
                }
                indegree[j] = -1; // Mark this node as visited
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
