
// MFCStatusBarView.cpp : implementation of the CMFCStatusBarView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCStatusBar.h"
#endif

#include "MFCStatusBarDoc.h"
#include "MFCStatusBarView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCStatusBarView

IMPLEMENT_DYNCREATE(CMFCStatusBarView, CView)

BEGIN_MESSAGE_MAP(CMFCStatusBarView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCStatusBarView construction/destruction

CMFCStatusBarView::CMFCStatusBarView()
{
	// TODO: add construction code here

}

CMFCStatusBarView::~CMFCStatusBarView()
{
}

BOOL CMFCStatusBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCStatusBarView drawing

void CMFCStatusBarView::OnDraw(CDC* /*pDC*/)
{
	CMFCStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCStatusBarView printing

BOOL CMFCStatusBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCStatusBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCStatusBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCStatusBarView diagnostics

#ifdef _DEBUG
void CMFCStatusBarView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCStatusBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCStatusBarDoc* CMFCStatusBarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCStatusBarDoc)));
	return (CMFCStatusBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCStatusBarView message handlers


void CMFCStatusBarView::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    CString str;
    CMainFrame *pF;
    pF = (CMainFrame*)AfxGetApp()->m_pMainWnd;
    CStatusBar *pStatus = &pF->m_wndStatusBar;
    if (pStatus)
    {
        str.Format(_T("Mouse Loc x: %d y: %d"), point.x, point.y);
        pStatus->SetPaneText(1, str);
    }

    CView::OnMouseMove(nFlags, point);
}
