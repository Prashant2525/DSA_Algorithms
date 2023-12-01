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

struct node *list1, *list2, *temp1, *temp2, *temp, *t;

int main(int argc, char *argv[])
{
    int M[max][max], i, j, n1, n2, n11, n22, min, total = 0, count = 0;

    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            cout << "Distance from node " << i << " to node " << j << " : ";
            cin >> M[i][j];
        }
    }
    list2 = NULL;
    list1 = new node;
    list1->val = 0;
    list1->next = NULL;

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

    cout << endl;

    do
    {
        temp1 = list1;
        min = 999;

        while (temp1 != NULL)
        {
            n1 = temp1->val;
            temp2 = list2;

            while (temp2 != NULL)
            {
                n2 = temp2->val;
                if (M[n1][n2] < min)
                {
                    min = M[n1][n2];
                    n11 = n1;
                    n22 = n2;
                };
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        cout << n11 << "   to   " << n22 << " , the weight is " << min << endl;

        total += min;

        temp = new node;
        temp->val = n22;
        temp->next = list1;
        list1 = temp;

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
        count++;
    }

    while (count < max - 1);

    cout << endl;
    cout << "The total weight of the MST is " << total << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
