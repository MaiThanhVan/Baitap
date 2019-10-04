#include "pch.h"
#include "HCN.h"

HCN::HCN()
{
}
HCN::HCN(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
}
HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::draw(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
	CString str;
	//str.Format(_T("%f"), dientich());
	//pdc->TextOutW(point2.x, point2.y, str);
}
CPoint HCN::getA()
{
	return CPoint(x1, y1);
}
CPoint HCN::getC()
{
	return CPoint(x2, y2);
}
int HCN::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}
HCN::~HCN()
{
}

void HCN::dichuyen(int dx, int dy)
{
	x1 = x1 + dx;
	x2 += dx;
	y1 += dy;
	y2 += dy;

}

