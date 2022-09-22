
// MFCMDIDemoView.cpp : implementation of the CMFCMDIDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCMDIDemo.h"
#endif

#include "MFCMDIDemoDoc.h"
#include "MFCMDIDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMDIDemoView

IMPLEMENT_DYNCREATE(CMFCMDIDemoView, CView)

BEGIN_MESSAGE_MAP(CMFCMDIDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCMDIDemoView construction/destruction

CMFCMDIDemoView::CMFCMDIDemoView()
{
	// TODO: add construction code here

}

CMFCMDIDemoView::~CMFCMDIDemoView()
{
}

BOOL CMFCMDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMDIDemoView drawing

void CMFCMDIDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFCMDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCMDIDemoView printing

BOOL CMFCMDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCMDIDemoView diagnostics

#ifdef _DEBUG
void CMFCMDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMDIDemoDoc* CMFCMDIDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMDIDemoDoc)));
	return (CMFCMDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMDIDemoView message handlers
