#include<opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> 
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(1);
	Mat img;
	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");
	if (plateCascade.empty()) {
		cout << " error" << endl;
	}
	vector<Rect>plates;
	while (true) {
		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 10);
		for (int i = 0; i < plates.size(); i++)
		{	
			Mat imgCrop = img(plates[i]);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(0, 0, 255), 3);
			string  path_to_ImgCrop = "Resources/car_plates/" + to_string(i) + ".png";
			imwrite(path_to_ImgCrop,imgCrop);
		}
		imshow("Image", img);
		waitKey(1);
	}
	return 0;
}

















