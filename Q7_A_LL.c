#include <stdio.h>

 

void func ( int arr[], int size ) 
{
    for ( int i = 0; i < size; i++ ) 
        {
        arr[ i ] = arr[ i ] + 1;
        }
}

 

int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    func(arr, 5);

    for (int i = 0; i < 5; i++) {

        printf("%d ", arr[i]);

    }

    return 0;

}