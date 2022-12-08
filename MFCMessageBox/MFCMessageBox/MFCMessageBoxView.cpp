
// MFCMessageBoxView.cpp : implementation of the CMFCMessageBoxView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCMessageBox.h"
#endif

#include "MFCMessageBoxDoc.h"
#include "MFCMessageBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMessageBoxView

IMPLEMENT_DYNCREATE(CMFCMessageBoxView, CView)

BEGIN_MESSAGE_MAP(CMFCMessageBoxView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_CREATE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCMessageBoxView construction/destruction

CMFCMessageBoxView::CMFCMessageBoxView()
{
	// TODO: add construction code here

}

CMFCMessageBoxView::~CMFCMessageBoxView()
{
}

BOOL CMFCMessageBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMessageBoxView drawing

void CMFCMessageBoxView::OnDraw(CDC* /*pDC*/)
{
	CMFCMessageBoxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCMessageBoxView printing

BOOL CMFCMessageBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMessageBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMessageBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCMessageBoxView diagnostics

#ifdef _DEBUG
void CMFCMessageBoxView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMessageBoxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMessageBoxDoc* CMFCMessageBoxView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMessageBoxDoc)));
	return (CMFCMessageBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMessageBoxView message handlers


int CMFCMessageBoxView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here
    AfxMessageBox(_T("Window Created"), MB_OKCANCEL | MB_ICONINFORMATION);

    return 0;
}


void CMFCMessageBoxView::OnDestroy()
{
    CView::OnDestroy();

    // TODO: Add your message handler code here
    AfxMessageBox(_T("Window Destroy"), MB_RETRYCANCEL | MB_ICONSTOP);
}
