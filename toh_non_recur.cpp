#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int st[20][4], top, o = 1, m = 2, d = 3, n, i, j, k;
    top = 0;
    cout << "How many disks? ";
    cin >> n;
    st[top][0] = o;
    st[top][1] = d;
    st[top][2] = m;
    st[top][3] = n;
    while (top >= 0)
    {
        i = st[top][0];
        j = st[top][1];
        k = st[top][2];
        n = st[top][3];
        top = top - 1; // pop from the stack
        if (n <= 1)
            cout << "Move " << i << " to " << j << endl;
        else if (n > 1)
        {
            // swap the 1st and 3rd
            top = top + 1;
            st[top][0] = k;
            st[top][1] = j;
            st[top][2] = i;
            st[top][3] = n - 1;
            top = top + 1; // push to the stack
            // movement from 1st to 2nd
            //  put some garbage parameter to st[top][2] and st[top][3]
            st[top][0] = i;
            st[top][1] = j;
            st[top][2] = 0;
            st[top][3] = 0;
            top = top + 1;
            // swap 2nd and 3rd
            st[top][0] = i;
            st[top][1] = k;
            st[top][2] = j;
            st[top][3] = n - 1;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}