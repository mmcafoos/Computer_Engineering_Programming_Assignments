#include <iostream>

using namespace std;

void bubbleSort(int *a, int size)
{
    int bub, ble;
    // will exit if null pointer    
    if(a==nullptr)exit(0);
        cout << "a is not null" << endl;
        for (bub = 0; bub < size - 1; bub++)
            // Last i elements are already in place
            for (ble = 0; ble < size - bub - 1; ble++)
                if (*(a+ble) > *(a+ble+1))//keeps in in "pointer syntax"
                    swap(*(a+ble),*(a+ble+1));
}
//Code below given from example link in assignment, tried to base assignment off it
// A function to implement bubble sort
/*
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
*/
 
int main() // Required main function given in assignment
{
    const int SIZE=5;
    int a1[] = {3,4,8,2,1};
    int *p=nullptr;
    bubbleSort(a1, SIZE);
    for (int i = 0; i < SIZE; i++){
        cout << a1[i] << " ";
    }
    bubbleSort(nullptr, SIZE);
    return 0;
}

//Rest of code from example
/*
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 5, 1, 4, 2, 8};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}
// This code is contributed by rathbhupendra
*/
