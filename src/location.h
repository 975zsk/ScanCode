//#pragma once ȷ��ͷ�ļ�ֻ������һ�ε�һ�ַ���
#ifndef _LOCATION_H_
#define _LOCATION_H_

#include "my.h"

class Location
{
private:
	Mat img;		//���ڴ���ͼ��
	Mat img_show;	//��ʾ���
	Mat dstimg;		//���ͼ��

	Point point1;		//��ά�붨λ��1
	Point point2;		//��ά�붨λ��2
	Point point3;		//��ά�붨λ��3
	Point point4;		//��ά�붨λ��4(��õĵ�)

	Point center;	//��ά����ת����
	float angle;	//��ά����ת�Ƕ�

	int judge_point(Point point1, Point point2, Point point);
	void point_locat();		//��λ��ά���ĸ���
	void rotate_info();		//�õ���ת��Ϣ
	void retate();			//������ת
public:
	Location(Mat &imgg);//���캯��
	~Location();		//��������

	void located();		//ִ��
	void get_dstimg(Mat &img);	//�õ����
};

#endif
