#include <cstdlib>
#include <iostream>
#define max 5

using namespace std;

int main()
{
	int M[max][max], i, j, k;
	FILE *fnew;

	// Input the data from datafile named data.txt.
	// It is important to learn the usage of datafiles.
	//  Draw a graph ,enter it's weight matrix on notepad and save it
	//  as data in the same directory as your program.
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
	} // else

	cout << "Initial matrix" << endl;
	// Show the initial weight matrix
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}

	// Improve the distances through vertex k to all other unselected nodes
	for (k = 0; k < max; k++)
	{ // Through all vertices
		for (i = 0; i < max; i++)
		{ // from all vertices
			for (j = 0; j < max; j++)
			{ // To all vertices improve the distances
				if (M[i][j] > M[i][k] + M[k][j])
					M[i][j] = M[i][k] + M[k][j];
			}
		}
	}

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
	cout << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}
