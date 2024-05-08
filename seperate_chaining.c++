//Also known as Closed Addressing or seperate chaining or open hashing
#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
    int n;
    struct node *next;
};
typedef struct node node;
node *AOP[10], *temp;

int main()
{
    int num, k;
    int s;
    node *new_node;
    cout<<"\nEnter the size: ";
    cin>>s;

    for (int i = 0 ; i < 10 ; i++)
    {
        AOP[i] = NULL;
    }

    for (int i = 0 ; i < s ; i++)
    {
        cout<<"\nEnter number: ";
        cin>>num;

        k = num%10;

        new_node = new(node);

        new_node->n = num;
        new_node->next = NULL;

        if(AOP[k] == NULL)
        {
            AOP[k] = new_node;
        }
        else
        {
            new_node->next = AOP[k];
            AOP[k] = new_node;
        }
    }

    cout<<"Hash Table: \n";
    for (int i = 0 ; i < 10 ; i++)
    {
        temp = AOP[i];
        cout<<"List number: "<<i + 1<<" == ";
        while(temp != NULL)
        {
            cout<<temp->n<<" --> ";
            temp = temp->next;
        }
        cout<<"null";
        cout<<endl;    
    }
}