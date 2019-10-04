
// Van_bai26View.cpp : implementation of the CVanbai26View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Van_bai26.h"
#endif

#include "Van_bai26Doc.h"
#include "Van_bai26View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVanbai26View

IMPLEMENT_DYNCREATE(CVanbai26View, CView)

BEGIN_MESSAGE_MAP(CVanbai26View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CVanbai26View construction/destruction

CVanbai26View::CVanbai26View() noexcept
{
	// TODO: add construction code here
	b2.thietlap(100, 50, 280, 100);
	b2.chu = CString("Ve Hinh Chu Nhat");
	b4.thietlap(300, 50, 480, 100);
	b4.chu = CString("Di Chuyen");
	control = 1;
	n = 0;
}

CVanbai26View::~CVanbai26View()
{
}

BOOL CVanbai26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVanbai26View drawing

void CVanbai26View::OnDraw(CDC* /*pDC*/)
{
	CVanbai26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);
	b2.draw(pdc);
	b4.draw(pdc);

	// TODO: add draw code for native data here
}


// CVanbai26View printing

BOOL CVanbai26View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVanbai26View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVanbai26View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CVanbai26View diagnostics

#ifdef _DEBUG
void CVanbai26View::AssertValid() const
{
	CView::AssertValid();
}

void CVanbai26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVanbai26Doc* CVanbai26View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVanbai26Doc)));
	return (CVanbai26Doc*)m_pDocument;
}
#endif //_DEBUG


// CVanbai26View message handlers


void CVanbai26View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	pdc = new CClientDC(this);
	CPen* oldP, * pen1, * pen2;//Set 2pen
	pen1 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
	pen2 = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CBrush* oldB, * B1, * B2;
	B1 = new CBrush(RGB(0, 0, 0));
	B2 = new CBrush(RGB(255, 255, 255));//
	if (b2.tronghinh(point) == 1)
		control = 2;
	else
		if (b4.tronghinh(point) == 1)
			control = 4;
		else
			if (control == 2)//tamgiac
			{
				ph[n] = new HCN(p1, p2);
				ph[n]->draw(pdc);
				n++;
			}

			else//dichuyenhinh
			{
				int i = 0;
				for (i = 0; i < n; i++)
				{
					if (ph[i]->tronghinh(p1) == 1)
					{
						oldP = pdc->SelectObject(pen2);//Chọn Pen Và ghi đè lên hình cũ lúc kéo thả
						oldB = pdc->SelectObject(B2);//
						ph[i]->draw(pdc);
						ph[i]->dichuyen(p2.x - p1.x, p2.y - p1.y);
						oldP = pdc->SelectObject(pen1);
						oldB = pdc->SelectObject(B2);
						ph[i]->draw(pdc);

					}

				}
			}

	CView::OnLButtonUp(nFlags, point);
}


void CVanbai26View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}
