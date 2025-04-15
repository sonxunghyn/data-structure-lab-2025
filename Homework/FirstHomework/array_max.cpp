#include <iostream>
using namespace std;

int getMax(int arr[], int size) {
	int maxVal = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	return maxVal;
}

int main() {
	int size;
	cout << "배열의 크기 입력: ";
	cin >> size;

	int arr[100]; // 최대 크기 설정
	cout << size << "개의 정수 입력: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "최댓값: " << getMax(arr, size) << endl;

	return 0;
}