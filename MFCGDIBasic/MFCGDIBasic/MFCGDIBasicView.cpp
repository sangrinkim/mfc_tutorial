
// MFCGDIBasicView.cpp : implementation of the CMFCGDIBasicView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCGDIBasic.h"
#endif

#include "MFCGDIBasicDoc.h"
#include "MFCGDIBasicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCGDIBasicView

IMPLEMENT_DYNCREATE(CMFCGDIBasicView, CView)

BEGIN_MESSAGE_MAP(CMFCGDIBasicView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(ID_DRAW_QUADRANGLE, &CMFCGDIBasicView::OnDrawQuadrangle)
    ON_COMMAND(ID_DRAW_LINE, &CMFCGDIBasicView::OnDrawLine)
    ON_COMMAND(ID_DRAW_CIRCLE, &CMFCGDIBasicView::OnDrawCircle)
    ON_COMMAND(ID_DRAW_FONT, &CMFCGDIBasicView::OnDrawFont)
    ON_COMMAND(ID_COLOR_BLACK, &CMFCGDIBasicView::OnColorBlack)
    ON_COMMAND(ID_COLOR_BLUE, &CMFCGDIBasicView::OnColorBlue)
    ON_COMMAND(ID_COLOR_GREEN, &CMFCGDIBasicView::OnColorGreen)
    ON_COMMAND(ID_COLOR_RED, &CMFCGDIBasicView::OnColorRed)
END_MESSAGE_MAP()

// CMFCGDIBasicView construction/destruction

CMFCGDIBasicView::CMFCGDIBasicView()
    : m_style(HBOX)
    , m_string(_T("GDI Practice"))
{
	// TODO: add construction code here
    m_rect = CRect(50, 50, 100, 100);
    m_color = RGB(0, 0, 0);
}

CMFCGDIBasicView::~CMFCGDIBasicView()
{
}

BOOL CMFCGDIBasicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCGDIBasicView drawing

void CMFCGDIBasicView::OnDraw(CDC* pDC)
{
    CPen myPen;
    myPen.CreatePen(PS_SOLID, 1, m_color);
    CPen *pOldPen;
    pOldPen = pDC->SelectObject(&myPen);

	CMFCGDIBasicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

    if (m_style == HBOX)
    {
        pDC->Rectangle(m_rect);
    }
    else if (m_style == HLINE)
    {
        pDC->MoveTo(m_rect.left, m_rect.top);
        pDC->LineTo(m_rect.right, m_rect.bottom);
    }
    else if (m_style == HCIRCLE)
    {
        pDC->Ellipse(m_rect);
    }
    else if (m_style == HTEXT)
    {
        pDC->TextOutW(m_rect.right / 2, m_rect.bottom / 2, m_string);
        
    }
    pDC->SelectObject(pOldPen);
}


// CMFCGDIBasicView printing

BOOL CMFCGDIBasicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCGDIBasicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCGDIBasicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCGDIBasicView diagnostics

#ifdef _DEBUG
void CMFCGDIBasicView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCGDIBasicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCGDIBasicDoc* CMFCGDIBasicView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCGDIBasicDoc)));
	return (CMFCGDIBasicDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCGDIBasicView message handlers


void CMFCGDIBasicView::OnDrawQuadrangle()
{
    // TODO: Add your command handler code here
    m_style = HBOX;
    Invalidate();
}


void CMFCGDIBasicView::OnDrawLine()
{
    // TODO: Add your command handler code here
    m_style = HLINE;
    Invalidate();
}


void CMFCGDIBasicView::OnDrawCircle()
{
    // TODO: Add your command handler code here
    m_style = HCIRCLE;
    Invalidate();
}


void CMFCGDIBasicView::OnDrawFont()
{
    // TODO: Add your command handler code here
    m_style = HTEXT;
    Invalidate();
}


void CMFCGDIBasicView::OnColorBlack()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 0, 0);
    Invalidate();
}


void CMFCGDIBasicView::OnColorBlue()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 0, 255);
    Invalidate();
}


void CMFCGDIBasicView::OnColorGreen()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 255, 0);
    Invalidate();
}


void CMFCGDIBasicView::OnColorRed()
{
    // TODO: Add your command handler code here
    m_color = RGB(255, 0, 0);
    Invalidate();
}
