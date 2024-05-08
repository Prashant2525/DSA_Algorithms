#include <iostream>
using namespace std;
#include <time.h>
int main()
{
    srand(time(0));
    int n, i, j, k, x, tasks[10][2], sch[10][15], m = 0, flag;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 15; j++)
        {
            sch[i][j] = 0;
        }
    }

    for (i = 0; i < 10; i++)
    {
        tasks[i][0] = rand() % 6 + 2;
        tasks[i][1] = tasks[i][0] + rand() % 6 + 1;
    }

    for (i = 0; i < 10; i++)
    {
        cout << "Start Time: "<< tasks[i][0] << " " <<"End Time: "<<  tasks[i][1] << endl
             << endl;
    }

    int t1;

    for (i = 9; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (tasks[j][0] > tasks[j + 1][0])
            {
                t1 = tasks[j][0];
                tasks[j][0] = tasks[j + 1][0];
                tasks[j + 1][0] = t1;
                t1 = tasks[j][1];
                tasks[j][1] = tasks[j + 1][1];
                tasks[j + 1][1] = t1;
            }
        }
    }
    cout << "schedule aftter sorting is" << endl << endl;

    for (i = 0; i < 10; i++)
    {
        cout << "Start Time: "<< tasks[i][0] << " " <<"End Time: "<<  tasks[i][1] << endl
             << endl;
    }

    for (k = tasks[0][0]; k <= tasks[0][1]; k++)
    {
        sch[0][k] = 1;
    }
        
    for (i = 1; i < 10; i++)
    {

        for (j = 0; j <= m; j++)
        {
            flag = 1;

            for (k = tasks[i][0]; k <= tasks[i][1]; k++)
            {
                if (sch[j][k] == 1)
                    flag = 0;
            }
            if (flag == 1)
            {
                for (k = tasks[i][0]; k <= tasks[i][1]; k++)
                {
                    sch[j][k] = 1;
                }
                break;
            }
        }
        if (flag == 0)
        {
            m = m + 1;

            for (k = tasks[i][0]; k <= tasks[i][1]; k++)
            {
                sch[m][k] = 1;
            }
                
        }
    }
    cout << endl << endl;
    cout << "Minimum number of machines required is: " << m + 1 << endl;

    return 0;
}