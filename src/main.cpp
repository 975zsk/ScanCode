#include "my.h"
#include "location.h"
#include "recognize.h"

int main()
{
	Mat img = imread("��ά����.jpg");
	resize(img, img, Size(648, 419));//��Сͼ�񣬷��㴦��

	//��ʼ��ʱ
	double time_;
	time_ = static_cast<double>(getTickCount());


	Mat img_out;
	Location location(img);//��ʵ����
	location.located();//���ú������д���
	location.get_dstimg(img_out);

	recognized(img_out);

	//���ʱ��
	time_ = (static_cast<double>(getTickCount()) - time_) / getTickFrequency();
	double FPS = 1 / time_;
	cout << "time = " << time_ * 1000 << "ms" << endl;

	imshow("img_out", img_out);
	waitKey(0);
	return 0;
}