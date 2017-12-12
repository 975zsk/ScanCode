#include "my.h"
#include <zbar.h>

void recognized(Mat &img)
{
	//ͼƬת��Ϊzbar��Image
	int width = img.cols;
	int height = img.rows;
	uchar *raw = (uchar *)img.data;
	zbar::Image imageZbar(width, height, "Y800", raw, width * height);

	//����ɨ��
	zbar::ImageScanner scanner;
	scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
	scanner.scan(imageZbar);
	zbar::Image::SymbolIterator symbol = imageZbar.symbol_begin();

	//������
	if (imageZbar.symbol_begin() == imageZbar.symbol_end())
		cout << "    ScanCode is failed" << endl;
	for (; symbol != imageZbar.symbol_end(); ++symbol)
	{
		cout << "    ���ͣ�" << symbol->get_type_name() << "���룺" << symbol->get_data() << endl;
	}
	imageZbar.set_data(NULL, 0);	//�ͷ�
	//imshow("img", img);
}