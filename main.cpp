// deck of 52 cards will be created and displayed//
//  The cards will be shuffled and displayed//
// Cards will be distributed among 4 players and cards will each player displayed
// Card is a class and 52 objects will be created for card//
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class card
{
private:
    int color;
    int value;

public:
    void setdata(int c, int v)
    {
        color = c;
        value = v;
    };
    int getcolor() { return color; };
    int getvalue() { return value; };
    void displaydata()
    {
        if (color == 1)
            cout << "Spades ";
        if (color == 2)
            cout << "Hearts ";
        if (color == 3)
            cout << "Clubs ";
        if (color == 4)
            cout << "Diamonds ";
        if (value < 11)
            cout << value;
        else
        {
            if (value == 11)
                cout << "Jack";
            if (value == 12)
                cout << "Queen";
            if (value == 13)
                cout << "King";
            if (value == 14)
                cout << "Ace";
        };
        cout << endl;
    };
};

int main(int argc, char *argv[])
{
    int i, j, k, m, sum[4] = {0, 0, 0, 0}, k1, k2, k3, k4;
    srand((unsigned)time(NULL));
    card cards[53], temp, player[4][13];
    cout << "CARDS BEFORE SHUFFLING:" << endl;
    for (i = 0; i < 52; i++)
    {
        j = i / 13 + 1;
        k = i % 13 + 2;
        cards[i + 1].setdata(j, k);
        cout << "Card No: " << i + 1 << " ";
        cards[i + 1].displaydata();
    }
    for (i = 0; i < 100; i++)
    {
        int r1 = rand() % 52 + 1;
        int r2 = rand() % 52 + 1;
        temp.setdata(cards[r1].getcolor(), cards[r1].getvalue());
        cards[r1].setdata(cards[r2].getcolor(), cards[r2].getvalue());
        cards[r2].setdata(temp.getcolor(), temp.getvalue());
    }
    cout << "CARDS AFTER SHUFFLING:" << endl;
    for (i = 0; i < 52; i++)
    {
        cout << "Card No:" << i + 1 << " ";
        cards[i + 1].displaydata();
    }
    cout << "Shuffled cards already displayed" << endl;
    // for( i=0;i<4;i++){
    // for(j=0;j<13;j++){ k=i*13+j;
    // player[i][j].setdata(cards[k+1].getcolor(),cards[k+1].getvalue());}} k1=0; k2=0; k3=0; k4=0;
    for (i = 0; i < 52; i++)
    {
        j = i % 4;

        if (j == 0)
        {
            player[j][k1++].setdata(cards[i + 1].getcolor(), cards[i + 1].getvalue());
        }
        if (j == 1)
        {
            player[j][k2++].setdata(cards[i + 1].getcolor(), cards[i + 1].getvalue());
        }
        if (j == 2)
        {
            player[j][k3++].setdata(cards[i + 1].getcolor(), cards[i + 1].getvalue());
        }
        if (j == 3)
        {
            player[j][k4++].setdata(cards[i + 1].getcolor(), cards[i + 1].getvalue());
        }
    }
    cout << "Shuffled cards already distributed " << endl<< endl;
    cout << "Display the cards with each player "<<endl<<endl;cin.get();
    for (i = 0; i < 4; i++)
    {
        cout << "player no:" << i + 1 << "--->" << endl << endl;
        for (j = 0; j < 13; j++)
        {
            player[i][j].displaydata();
            sum[i] = sum[i] + player[i][j].getcolor() + player[i][j].getvalue();
        }
    }
    for (i = 0; i < 4; i++)
    {
        cout << "Total points for player : "<<i+1<<" = "<<sum[i]<<endl;
    }
}