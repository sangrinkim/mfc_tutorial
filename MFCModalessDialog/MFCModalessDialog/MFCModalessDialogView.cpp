
// MFCModalessDialogView.cpp : implementation of the CMFCModalessDialogView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCModalessDialog.h"
#endif

#include "MFCModalessDialogDoc.h"
#include "MFCModalessDialogView.h"
#include "ModalessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCModalessDialogView

IMPLEMENT_DYNCREATE(CMFCModalessDialogView, CView)

BEGIN_MESSAGE_MAP(CMFCModalessDialogView, CView)
    ON_MESSAGE(WM_GOODBYE, OnGoodBye)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCModalessDialogView construction/destruction

CMFCModalessDialogView::CMFCModalessDialogView()
{
	// TODO: add construction code here
    m_pDlg = new CModalessDlg(this);
}

CMFCModalessDialogView::~CMFCModalessDialogView()
{
    delete m_pDlg;
}

BOOL CMFCModalessDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCModalessDialogView drawing

void CMFCModalessDialogView::OnDraw(CDC* /*pDC*/)
{
	CMFCModalessDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCModalessDialogView printing

BOOL CMFCModalessDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCModalessDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCModalessDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCModalessDialogView diagnostics

#ifdef _DEBUG
void CMFCModalessDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCModalessDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCModalessDialogDoc* CMFCModalessDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCModalessDialogDoc)));
	return (CMFCModalessDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCModalessDialogView message handlers


void CMFCModalessDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    if (m_pDlg->GetSafeHwnd() == NULL)
    {
        m_pDlg->Create();
        m_pDlg->ShowWindow(SW_SHOW);
    }

    CView::OnLButtonDown(nFlags, point);
}


void CMFCModalessDialogView::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    m_pDlg->DestroyWindow();

    CView::OnRButtonDown(nFlags, point);
}

LONG CMFCModalessDialogView::OnGoodBye(UINT wParam, LONG lParam)
{
    m_pDlg->DestroyWindow();
    return 0L;
}