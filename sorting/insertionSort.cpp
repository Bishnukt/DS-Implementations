#include <iostream>
using namespace std;
void insertionSort(int *arr, int n)
{
    int i, j;
    for (j = 1; j < n; j++)
    {
        int val = arr[j];
        i = j - 1;
        while (arr[i] > val && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
    }
    return;
}
int main()
{
    int n;
    cout << "Enter no. of elemens: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort(arr, n);
    cout << "Sorted elements are: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
