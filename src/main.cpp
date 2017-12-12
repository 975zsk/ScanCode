#include "my.h"
#include "location.h"
#include "recognize.h"

int main()
{
	//Mat img = imread("��ά����.jpg");
	//resize(img, img, Size(648, 419));//��Сͼ�񣬷��㴦��
	Mat img;
	VideoCapture cap(0);
	while (1)
	{
		//��ʼ��ʱ
		double time_;
		time_ = static_cast<double>(getTickCount());

		cap >> img;
		if (img.empty())
			break;


		Mat img_out;
		Location location(img);//��ʵ����
		location.located();//���ú������д���
		location.get_dstimg(img_out);

		recognized(img_out);

		//���ʱ��
		time_ = (static_cast<double>(getTickCount()) - time_) / getTickFrequency();
		double FPS = 1 / time_;
		//cout << "time = " << time_ * 1000 << "ms" << endl;
		cout << "FPS=" << FPS << endl;

		if (!img_out.empty())
			imshow("img_out", img_out);

		imshow("img", img);
		char key = waitKey(10);
		switch(key)
		{
			case 27:return 0; break;
		}
	}

	return 0;
}