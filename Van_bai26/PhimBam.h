#pragma once
#include "HCN.h"
class PhimBam :
	public HCN
{
public:
	CString chu;
	PhimBam();
	~PhimBam();
	void draw(CClientDC* pdc);
};

