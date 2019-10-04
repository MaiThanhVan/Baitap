#pragma once
class VeHinh
{
public:
	CPoint point1, point2;
	VeHinh();
	~VeHinh();
	virtual void draw(CClientDC* pdc);
	virtual int tronghinh(CPoint p1);
	virtual void dichuyen(int dx, int dy);
};

