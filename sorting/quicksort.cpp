#include <iostream>
using namespace std;

int partition(int *arr, int low, int up)
{
    // Taking the element at the low index of the array/subarray as pivot
    int pivot = arr[low];
    int i = low + 1, j = up;
    while (i <= j)
    {
        while (arr[i] < pivot && i <= up)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quicksort(int *arr, int low, int up)
{
    if (low >= up)
        return;
    int pivlock = partition(arr, low, up);
    quicksort(arr, low, pivlock - 1);
    quicksort(arr, pivlock + 1, up);
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    cout << "Sorted elements are: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
