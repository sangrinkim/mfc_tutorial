
// MFCMenuView.cpp : implementation of the CMFCMenuView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCMenu.h"
#endif

#include "MFCMenuDoc.h"
#include "MFCMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenuView

IMPLEMENT_DYNCREATE(CMFCMenuView, CView)

BEGIN_MESSAGE_MAP(CMFCMenuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(ID_COLOR_BLACK, &CMFCMenuView::OnColorBlack)
    ON_COMMAND(ID_COLOR_BLUE, &CMFCMenuView::OnColorBlue)
    ON_COMMAND(ID_COLOR_GREEN, &CMFCMenuView::OnColorGreen)
    ON_COMMAND(ID_COLOR_RED, &CMFCMenuView::OnColorRed)
END_MESSAGE_MAP()

// CMFCMenuView construction/destruction

CMFCMenuView::CMFCMenuView()
{
	// TODO: add construction code here
    m_color = RGB(0, 0, 0);
}

CMFCMenuView::~CMFCMenuView()
{
}

BOOL CMFCMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMenuView drawing

void CMFCMenuView::OnDraw(CDC* pDC)
{
	CMFCMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    CRect r;
    GetClientRect(r);
    pDC->SetTextColor(m_color);
    pDC->DrawText(_T("TextColor"), -1, r, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMFCMenuView printing

BOOL CMFCMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCMenuView diagnostics

#ifdef _DEBUG
void CMFCMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenuDoc* CMFCMenuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenuDoc)));
	return (CMFCMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenuView message handlers


void CMFCMenuView::OnColorBlack()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 0, 0);
    Invalidate();
}


void CMFCMenuView::OnColorBlue()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 0, 255);
    Invalidate();
}


void CMFCMenuView::OnColorGreen()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 255, 0);
    Invalidate();
}


void CMFCMenuView::OnColorRed()
{
    // TODO: Add your command handler code here
    m_color = RGB(255, 0, 0);
    Invalidate();
}
