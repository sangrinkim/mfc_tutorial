
// MFCToolBarView.cpp : implementation of the CMFCToolBarView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCToolBar.h"
#endif

#include "MFCToolBarDoc.h"
#include "MFCToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCToolBarView

IMPLEMENT_DYNCREATE(CMFCToolBarView, CView)

BEGIN_MESSAGE_MAP(CMFCToolBarView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(ID_BUTTON_BLUE, &CMFCToolBarView::OnButtonBlue)
    ON_COMMAND(ID_BUTTON_GREEN, &CMFCToolBarView::OnButtonGreen)
    ON_COMMAND(ID_BUTTON_RED, &CMFCToolBarView::OnButtonRed)
END_MESSAGE_MAP()

// CMFCToolBarView construction/destruction

CMFCToolBarView::CMFCToolBarView()
{
	// TODO: add construction code here
    m_color = RGB(0, 0, 0);
}

CMFCToolBarView::~CMFCToolBarView()
{
}

BOOL CMFCToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCToolBarView drawing

void CMFCToolBarView::OnDraw(CDC* pDC)
{
	CMFCToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    CRect r;
    GetClientRect(r);
    pDC->SetTextColor(m_color);
    pDC->DrawText(_T("FontColor"), -1, r, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMFCToolBarView printing

BOOL CMFCToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCToolBarView diagnostics

#ifdef _DEBUG
void CMFCToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCToolBarDoc* CMFCToolBarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCToolBarDoc)));
	return (CMFCToolBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCToolBarView message handlers


void CMFCToolBarView::OnButtonBlue()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 0, 255);
    Invalidate();
}


void CMFCToolBarView::OnButtonGreen()
{
    // TODO: Add your command handler code here
    m_color = RGB(0, 255, 0);
    Invalidate();
}


void CMFCToolBarView::OnButtonRed()
{
    // TODO: Add your command handler code here
    m_color = RGB(255, 0, 0);
    Invalidate();
}
