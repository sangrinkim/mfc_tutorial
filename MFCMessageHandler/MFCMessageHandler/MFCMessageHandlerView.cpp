
// MFCMessageHandlerView.cpp : implementation of the CMFCMessageHandlerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCMessageHandler.h"
#endif

#include "MFCMessageHandlerDoc.h"
#include "MFCMessageHandlerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMessageHandlerView

IMPLEMENT_DYNCREATE(CMFCMessageHandlerView, CView)

BEGIN_MESSAGE_MAP(CMFCMessageHandlerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_SIZE()
END_MESSAGE_MAP()

// CMFCMessageHandlerView construction/destruction

CMFCMessageHandlerView::CMFCMessageHandlerView()
    : m_string(_T("Hello Visual C++"))
    , m_xy(0)
{
	// TODO: add construction code here

}

CMFCMessageHandlerView::~CMFCMessageHandlerView()
{
}

BOOL CMFCMessageHandlerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMessageHandlerView drawing

void CMFCMessageHandlerView::OnDraw(CDC* pDC)
{
	CMFCMessageHandlerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    pDC->SetTextAlign(TA_CENTER);
    pDC->TextOutW(m_xy.x, m_xy.y, m_string);
}


// CMFCMessageHandlerView printing

BOOL CMFCMessageHandlerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMessageHandlerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMessageHandlerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCMessageHandlerView diagnostics

#ifdef _DEBUG
void CMFCMessageHandlerView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMessageHandlerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMessageHandlerDoc* CMFCMessageHandlerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMessageHandlerDoc)));
	return (CMFCMessageHandlerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMessageHandlerView message handlers


void CMFCMessageHandlerView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);

    // TODO: Add your message handler code here
    m_xy.x = cx / 2;
    m_xy.y = cy / 2;
}
