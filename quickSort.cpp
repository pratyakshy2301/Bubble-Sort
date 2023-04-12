#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {

    int pivot = arr[s];
    int count = 0;

    for(int i=s+1; i<=e; i++) {
        if(pivot >= arr[i]) {
            count++;
        }
    }

    int index = s + count;
    swap(arr[s], arr[index]);

    int i = s, j = e;

    while (i < index && j > index) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) 
        {
            j--;
        }

        if(i < index && j > index) 
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return index;
}

void quickSort(int arr[], int s, int e) {

    //BASE CASE
    if(s >= e) {
        return;
    }

    //PARTITION
    int p = partition(arr, s, e);

    //RECURSIVE CALL
    //LEFT PART
    quickSort(arr, s, p-1);
    //RIGHT PART
    quickSort(arr, p+1, e);
}

int main() {
    int arr[] = {3,1,4,5,2,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}