#include <stdio.h>

// function to search position of element
int BinarySearch(int a[], int data, int low, int high)
{
    int mid;
    if (low > high)
    {
        return -1;
    }
    else
    {
        // finding the mid
        mid = (low + high) / 2;
        if (data == a[mid])
        {
            return mid;
        }
        else if (data < a[mid])
        {
            // function call.
            BinarySearch(a, data, low, mid - 1); // high=mid-1;
        }
        else
        {
            BinarySearch(a, data, mid + 1, high); // low=mid+1;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int low = 0, high = 5;
    int pos = BinarySearch(arr, 5, low, high);
    if (pos == -1)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("The position of the element is %d", pos + 1);
    }
    return 0;
}
