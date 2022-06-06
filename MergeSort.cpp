#include <iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int *b = new int[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
        arr[i] = b[i];
    free(b);
}

void merge_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements to be sorted: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(arr, 0, n - 1);
    cout << "Elements after sorting : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
