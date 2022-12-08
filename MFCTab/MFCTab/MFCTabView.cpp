
// MFCTabView.cpp : implementation of the CMFCTabView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTab.h"
#endif

#include "MFCTabDoc.h"
#include "MFCTabView.h"
#include "property.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTabView

IMPLEMENT_DYNCREATE(CMFCTabView, CView)

BEGIN_MESSAGE_MAP(CMFCTabView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(ID_TAB_DIALOG, &CMFCTabView::OnTabDialog)
END_MESSAGE_MAP()

// CMFCTabView construction/destruction

CMFCTabView::CMFCTabView()
    : m_string(_T("New Tab Application"))
    , m_xy(0)
{
	// TODO: add construction code here
    m_color = RGB(255, 0, 0);
    m_xy = CPoint(150, 150);
}

CMFCTabView::~CMFCTabView()
{
}

BOOL CMFCTabView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTabView drawing

void CMFCTabView::OnDraw(CDC* pDC)
{
	CMFCTabDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    pDC->SetTextColor(m_color);
    pDC->SetTextAlign(TA_CENTER);
    pDC->TextOutW(m_xy.x, m_xy.y, m_string);
}


// CMFCTabView printing

BOOL CMFCTabView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTabView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTabView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCTabView diagnostics

#ifdef _DEBUG
void CMFCTabView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTabView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTabDoc* CMFCTabView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTabDoc)));
	return (CMFCTabDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTabView message handlers


void CMFCTabView::OnTabDialog()
{
    // TODO: Add your command handler code here
    CTabSheet myDlg(_T(""));
    myDlg.DoModal();

    if (myDlg.m_page1.m_strDlg == "")
    {
        myDlg.m_page1.m_strDlg = m_string;
    }

    switch (myDlg.m_page2.m_colorDlg)
    {
        case 0: m_color = RGB(0, 0, 0); break;
        case 1: m_color = RGB(0, 255, 0); break;
        case 2: m_color = RGB(255, 0, 0); break;
        case 3: m_color = RGB(0, 0, 255); break;
    }

    m_xy.x = myDlg.m_page3.m_x;
    m_xy.y = myDlg.m_page3.m_y;

    m_string = myDlg.m_page1.m_strDlg;
    Invalidate();
}
