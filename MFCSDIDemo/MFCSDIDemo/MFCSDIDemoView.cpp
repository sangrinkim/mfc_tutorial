
// MFCSDIDemoView.cpp : implementation of the CMFCSDIDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSDIDemo.h"
#endif

#include "MFCSDIDemoDoc.h"
#include "MFCSDIDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSDIDemoView

IMPLEMENT_DYNCREATE(CMFCSDIDemoView, CView)

BEGIN_MESSAGE_MAP(CMFCSDIDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCSDIDemoView construction/destruction

CMFCSDIDemoView::CMFCSDIDemoView()
{
	// TODO: add construction code here

}

CMFCSDIDemoView::~CMFCSDIDemoView()
{
}

BOOL CMFCSDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCSDIDemoView drawing

void CMFCSDIDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFCSDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCSDIDemoView printing

BOOL CMFCSDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCSDIDemoView diagnostics

#ifdef _DEBUG
void CMFCSDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSDIDemoDoc* CMFCSDIDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSDIDemoDoc)));
	return (CMFCSDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSDIDemoView message handlers
