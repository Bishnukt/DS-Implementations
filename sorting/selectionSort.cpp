#include <iostream>
using namespace std;

void selection_sort(int *arr, int n)
{
    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements to be sorted: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selection_sort(arr, n);
    cout << "Sorted elements are: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}