#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	// �̹��� ������ �׷��̽����Ϸ� �б�
	Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);

	// �̹����� ����� �ҷ��������� Ȯ��
	if (img.empty()) {
		cout << "�̹����� �ҷ��� �� �����ϴ�!" << endl;
		return -1;
	}

	// �ִ� ���� ����
	double minVal, maxVal;

	// �ּڰ�, �ִ� ã��
	minMaxLoc(img, &minVal, &maxVal);

	cout << "�ִ� ��Ⱚ: " << maxVal << endl;

	return 0;

}