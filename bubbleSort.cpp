#include <iostream>
using namespace std;
void bubble_sort(int *arr, int n)
{
    int swap = 1;
    for (int i = n - 1; i >= 0 && swap; i--)
    {
        swap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swap++;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements to be sorted: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubble_sort(arr, n);
    cout << "Elements after sorting : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}