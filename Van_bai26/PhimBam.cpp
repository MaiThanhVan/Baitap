#include "pch.h"
#include "PhimBam.h"

PhimBam::PhimBam()
{
}


PhimBam::~PhimBam()
{
}


void PhimBam::draw(CClientDC* pdc)
{
	// TODO: Add your implementation code here.
	pdc->Rectangle(getA().x, getA().y, getC().x, getC().y);
	pdc->TextOutW(getA().x + 18, getA().y + 18, chu);
}
