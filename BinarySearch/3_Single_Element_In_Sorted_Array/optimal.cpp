#include <iostream>
#include <vector>
using namespace std;
int singleElement(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];

    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int start = 1;
    int end = n - 2;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if (
            (mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 1, 2,2, 3, 3, 4, 5, 5, 6, 6};

    cout << "The single element in the sorted array is: " << singleElement(arr);
    return 0;
}