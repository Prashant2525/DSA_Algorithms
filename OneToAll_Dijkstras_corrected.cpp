#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#define max 5

using namespace std;

struct node
{
    int val;
    struct node *next;
};
struct node *list2, *temp2, *temp;

int main()
{
    FILE *fnew;

    int M[max][max], i, j, n1, n2, n22, min, total = 0, count = 0;
    // Input the initial Weight matrix
    if ((fnew = fopen("data.txt", "r")) == NULL)
        cout << "Can not open the data file\n";
    else
    {
        for (i = 0; i < max; i++)
        {
            for (j = 0; j < max; j++)
            {
                fscanf(fnew, "%d", &M[i][j]);
            };
        };
    }

    cout << endl;
    cout << "Initial matrix" << endl;
    // Display the initial Coincidence Matrix
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    list2 = NULL;
    n1 = 0;
    // Create the set of node numbers as linked list
    for (i = 1; i < max; i++)
    {
        temp = new node;
        temp->val = i;
        temp->next = NULL;
        if (list2 == NULL)
            list2 = temp;
        else
        {
            temp->next = list2;
            list2 = temp;
        }
    }

    do
    {
        min = 900; // Dummy value
        temp2 = list2;

        // Find the nearest node U to the chosen node
        while (temp2 != NULL)
        {
            n2 = temp2->val;
            if (M[n1][n2] < min)
            {
                min = M[n1][n2];
                n22 = n2;
            };
            temp2 = temp2->next;
        }
        // Remove the node U from the set
        temp = list2;
        if (temp->val == n22)
        {
            list2 = list2->next;
        }
        else
        {
            while (temp->next != NULL)
            {
                if (temp->next->val == n22)
                    temp->next = temp->next->next;
                else
                    temp = temp->next;
            }
        }
        // Improve the distances through U to all other unselected nodes
        for (i = 0; i < max; i++)
        {
            for (j = 0; j < max; j++)
            {
                if (M[i][j] > M[i][n22] + M[n22][j])
                    M[i][j] = M[i][n22] + M[n22][j];
            }
        }
        count++;
    } while (count < max - 1);

    cout << endl;
    cout << "Shortest distance solution matrix" << endl;
    // Show the solution matrix
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
