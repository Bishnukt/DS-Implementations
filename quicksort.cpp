#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int partition(vector<int> &arr, int low, int up)
{
    // Taking the element at the low index of the array/subarray as pivot
    int pivot = arr[low];
    int i = low + 1, j = up;
    //
    while (i <= j)
    {
        while (arr[i] < pivot && i < up)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        else
            i++;
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quicksort(vector<int> &arr, int low, int up)
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
    std::cout << "Enter no. of elements: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter elements: " << std::endl;
    for (auto &it : arr)
        std::cin >> it;
    quicksort(arr, 0, n - 1);
    std::cout << "Sorted elements are: ";
    for (auto it : arr)
        std::cout << it << " ";
    std::cout << std::endl;
    return 0;
}