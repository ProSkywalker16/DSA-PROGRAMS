#include <iostream>

using namespace std;

int main()
{
    int n;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare an array of size n
    int arr[n];

    // Get the elements of the array from the user
    cout << "Enter elements in the array:";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Perform insertion sort
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Display the sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
