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
	cout << "�迭�� ũ�� �Է�: ";
	cin >> size;

	int arr[100]; // �ִ� ũ�� ����
	cout << size << "���� ���� �Է�: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "�ִ�: " << getMax(arr, size) << endl;

	return 0;
}