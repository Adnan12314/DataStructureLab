#include <iostream>
using namespace std;

void nearest (int array[], int length)
{
    int sum_min, sum, left_min, right_min;

    if (length < 2) {
        cout << "Invalid Input";
        return;
    }

    left_min = 0;
    right_min = 1;
    sum_min = array[0] + array[1];


    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            sum = array[i] + array[j];

            if (abs(sum_min) > abs(sum)) {
                sum_min = sum;
                left_min = i;
                right_min = j;
            }
        }
    }
    cout << "Sum nearest to zero elements : " << array[left_min] << " and " << array[right_min];
}

int main()
{
    int array[10], N;

    cout << "Enter Number of elements: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "Enter element " << i + 1 << ":";
        cin >> array[i];
    }

    nearest (array, N);

    return 0;
}
