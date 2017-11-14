#include "my.h"
#include "location.h"
#include "recognize.h"

int main()
{
	Mat img = imread("��ά����.jpg");
	Mat img_show = img.clone();
	cvtColor(img, img, COLOR_BGR2GRAY);		//�ҶȻ�
	imshow("test1", img);

	mythreshold(img, 100);					//��ֵ��
	imshow("��ֵ��", img);
	Mat temp = img.clone();
	//location(img, temp);

	float angle = 0;
	//hierarchy[i][0]����i��������һ������
	//hierarchy[i][1]����i��������һ������
	//hierarchy[i][2]����i���ֵ�һ��������
	//hierarchy[i][3]����i���ֵ�һ��������
	vector<vector <Point> > contours;
	vector<Vec4i> hierarchy;				//����������Ϣ
	findContours(temp, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
	for (int i = 0; i < contours.size(); i++)
	{
		Rect r0 = boundingRect(Mat(contours[i]));			//��С��Χ����
		RotatedRect r1 = minAreaRect(Mat(contours[i]));	//��С��ת����

		if (r0.area() > 100 && hierarchy[i][2] > 0 && hierarchy[i][3] > 0)  //�����������100 && ���������� && ���ڸ�����
		{
			int up_number = hierarchy[i][3];		//���������
			Rect r2 = boundingRect(Mat(contours[hierarchy[i][3]]));		//������
			float w = r2.width;
			float h = r2.height;
			float rate = (float)(w / h);
			if (rate < 1.2 && rate > 0.8)		//�����
			{
				//rectangle(img_show, r2, Scalar(0, 0, 255), 2);
				drawContours(img_show, contours, up_number, Scalar(0, 0, 255), 2);	//����������Ϊ���������
				angle = r1.angle;
			}

		}
	}
#ifdef DEBUG
	cout << "��������Ϊ " << contours.size() << endl;
#endif
	//�򵥽���ͼ����ת
	Point center = Point(img.cols / 2, img.rows / 2);
	double scale = 1.0;
	Mat rotMat(2, 3, CV_32FC1);
	rotMat = getRotationMatrix2D(center, angle, scale);
	warpAffine(img_show, img_show, rotMat, img_show.size());

	imshow("img_show", img_show);
	waitKey(0);
	return 0;
}