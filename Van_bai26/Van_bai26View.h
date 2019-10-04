
// Van_bai26View.h : interface of the CVanbai26View class
//

#pragma once
#include "PhimBam.h"
#include "HCN.h"
#include "VeHinh.h"


class CVanbai26View : public CView
{
protected: // create from serialization only
	CVanbai26View() noexcept;
	DECLARE_DYNCREATE(CVanbai26View)

// Attributes
public:
	PhimBam b2, b4;
	CClientDC* pdc;
	CPoint p1, p2;
	
	int control;
	VeHinh* ph[20];
	int n;
	CVanbai26Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVanbai26View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in Van_bai26View.cpp
inline CVanbai26Doc* CVanbai26View::GetDocument() const
   { return reinterpret_cast<CVanbai26Doc*>(m_pDocument); }
#endif

