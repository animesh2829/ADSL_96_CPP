#include <iostream>
using namespace std;
  
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], temp[n];
    int nonZeroCount = 0;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != 0)
            temp[nonZeroCount++] = arr[i];  // store only non-zero elements
    }

    
    mergeSort(temp, 0, nonZeroCount - 1);

    // Copy sorted non-zero back to original array
    for (int i = 0; i < nonZeroCount; i++) {
        arr[i] = temp[i];
    }

    // Add zeros at the end
    for (int i = nonZeroCount; i < n; i++) {
        arr[i] = 0;
    }

    // Print final result
    cout << "Sorted array with zeros at the end:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}