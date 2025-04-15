#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	// 이미지 파일을 그레이스케일로 읽기
	Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);

	// 이미지가 제대로 불러와졌는지 확인
	if (img.empty()) {
		cout << "이미지를 불러올 수 없습니다!" << endl;
		return -1;
	}

	// 최댓값 저장 변수
	double minVal, maxVal;

	// 최솟값, 최댓값 찾기
	minMaxLoc(img, &minVal, &maxVal);

	cout << "최대 밝기값: " << maxVal << endl;

	return 0;

}