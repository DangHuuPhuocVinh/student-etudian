#include "RGB.h"

RGB::RGB()
{
	this->blue = this->green = this->red = 255;
}

void RGB::Gan(const char* mau)
{
	if (strcmp(mau, "black") == 0)
		this->blue = this->green = this->red = 0;
	if (strcmp(mau, "white") == 0)
		this->blue = this->green = this->red = 255;
	if (strcmp(mau, "green") == 0)
		this->blue = 0; this->green = 255; this->red = 0;
	if (strcmp(mau, "blue") == 0)
		this->blue = 255; this->green = 0, this->red = 0;
	if (strcmp(mau, "red") == 0)
		this->blue = 0; this->red = 255; this->green = 0;
	if (strcmp(mau, "yellow") == 0)
		this->blue = 0; this->red = 255; this->green = 255;
	if (strcmp(mau, "aqua") == 0)
		this->blue = 255; this->green = 255; this->red = 0;
	if (strcmp(mau, "fuchsia") == 0)
		this->blue = 255; this->red = 255; this->green = 0;
}

void RGB::check()
{
	if (this->blue >= 255)
		this->blue = 255;
	if (this->blue <= 0)
		this->blue = 0;
	if (this->green >= 255)
		this->green = 255;
	if (this->green <= 0)
		this->green = 0;
	if (this->red >= 255)
		this->red = 255;
	if (this->red <= 0)
		this->red = 0;
}

RGB& RGB::operator+(const RGB &rbg)
{
	RGB temp;
	temp.blue = this->blue + rbg.blue;
	temp.green = this->green + rbg.green;
	temp.red = this->red + rgb.red;
	temp.check();
	return temp;
}

RGB& RGB::operator+(int number)
{
	RGB temp;
	temp.blue = this->blue + number;
	temp.green = this->green + number;
	temp.red = this->red + number;
	temp.check();
	return temp;
}

RBG::operator+(int number, const RGB &rgb)
{
	RGB temp;
	temp.blue = rgb.blue + number;
	temp.green = rgb.green + number;
	temp.red = rgb.red + number;
	temp.check();
	return temp;
}

RGB RGB::operator-(int number)
{
	RGB temp;
	temp.blue = this->blue - number;
	temp.green = this->green - number;
	temp.red = this->red - number;
	return temp;
}

ostream& operator<<(ostream& os, const RGB &rgb)
{
	os << "(" << rgb.red << ", " << rgb.green << " , " << rgb.blue << ")" << endl;
	return os;
}

Pic::Pic(int m, int n)
{
	this->m = m;
	this->n = n;
	this->pic = new RGB*[this->m];

	for (int i = 0; i < m; i++)
		this->pic[i] = new RGB[this->n];
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			this->pic[i][j] = 0;
		}
	}
}

Pic Pic::TangSang(int pixel)
{

}