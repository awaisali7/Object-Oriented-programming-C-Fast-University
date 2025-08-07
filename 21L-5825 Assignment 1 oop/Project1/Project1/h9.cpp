#include<iostream>
using namespace std;
int main() {

	int size = 5, num = 0, i = 0;
	int* arr = new int[size];

	cout << "Enter the integers of the array:" << endl;
	while (*(arr + i) = !- 1) {


		if (i == size) {
			int* newarr = new int[size * 2];
			for (int j = 0; j < size; j++) {
				*(arr + j) = *(newarr + j);
			}
			delete[]arr;
			arr = newarr;
			size = size * 2;
		}
		cin >> *(arr + i);

		cout << endl;
		i++;

	}


	return 0;
}