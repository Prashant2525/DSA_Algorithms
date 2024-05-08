#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthLargest(int arr[], int low, int high, int k)
{
    int partitionIndex = partition(arr, low, high);

    if (partitionIndex == k - 1)
        return arr[partitionIndex];
    else if (partitionIndex > k - 1)
        return kthLargest(arr, low, partitionIndex - 1, k);
    else
        return kthLargest(arr, partitionIndex + 1, high, k);
}

int main()
{
    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k; 

    if (k > 0 && k <= n)
    {
        int kthLargestElement = kthLargest(arr, 0, n - 1, k);
        cout << "The " << k << "th largest element is: " << kthLargestElement << endl;
    }
    else
    {
        cout << "Invalid value of k!" << endl;
    }

    return 0;
}
