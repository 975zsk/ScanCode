#include "my.h"
#include "location.h"
#include "recognize.h"

int main()
{
	Mat img = imread("��ά����.jpg");
	resize(img, img, Size(648, 419));//��Сͼ�񣬷��㴦��

	//�򵥽���ͼ����ת�����е���
	Point center = Point(img.cols / 2, img.rows / 2);
	double scale = 1.0;
	Mat rotMat(2, 3, CV_32FC1);
	rotMat = getRotationMatrix2D(center, 180, scale);
	warpAffine(img, img, rotMat, img.size());

	Mat img_show = img.clone();

	//��ʼ��ʱ
	double time_;
	time_ = static_cast<double>(getTickCount());

	cvtColor(img, img, COLOR_BGR2GRAY);		//�ҶȻ�
	imshow("test1", img);

	mythreshold(img, 100);					//��ֵ��
	imshow("��ֵ��", img);

	Location location(img);//��ʵ����
	location.located();//���ú������д���

	//���ʱ��
	time_ = (static_cast<double>(getTickCount()) - time_) / getTickFrequency();
	double FPS = 1 / time_;
	cout << "time = " << time_ * 1000 << "ms" << endl;


	imshow("img_show", img_show);
	waitKey(0);
	return 0;
}