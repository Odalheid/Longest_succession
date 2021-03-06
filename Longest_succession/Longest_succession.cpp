#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned int arr_size;
	cin >> arr_size;
	int *arr = new int[arr_size];
	for (int *ptr = arr; ptr != arr + arr_size; ++ptr) cin >> *ptr;

	int *subsequence_length = new int[arr_size];
	for (int *ptr = subsequence_length; ptr != subsequence_length + arr_size; ++ptr) *ptr = 1;

	for (int i = 1; i < arr_size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] % arr[j] == 0 && subsequence_length[j] + 1 > subsequence_length[i]) {
				++subsequence_length[i];
			}
		}
	}
	
	int max_length = 1;
	for (int i = 0; i < arr_size; ++i) {
		if (subsequence_length[i] > max_length) max_length = subsequence_length[i];
	}
	cout << max_length;
	delete[] arr;
    return 0;
}

