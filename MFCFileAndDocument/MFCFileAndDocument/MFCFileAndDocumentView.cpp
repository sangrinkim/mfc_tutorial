
// MFCFileAndDocumentView.cpp : implementation of the CMFCFileAndDocumentView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCFileAndDocument.h"
#endif

#include "MFCFileAndDocumentDoc.h"
#include "MFCFileAndDocumentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFileAndDocumentView

IMPLEMENT_DYNCREATE(CMFCFileAndDocumentView, CView)

BEGIN_MESSAGE_MAP(CMFCFileAndDocumentView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_COMMAND(ID_EDIT_UNDO, &CMFCFileAndDocumentView::OnEditUndo)
    ON_COMMAND(ID_EDIT_COPY, &CMFCFileAndDocumentView::OnEditCopy)
    ON_COMMAND(ID_EDIT_PASTE, &CMFCFileAndDocumentView::OnEditPaste)
    ON_COMMAND(ID_EDIT_CUT, &CMFCFileAndDocumentView::OnEditCut)
END_MESSAGE_MAP()

// CMFCFileAndDocumentView construction/destruction

CMFCFileAndDocumentView::CMFCFileAndDocumentView()
{
	// TODO: add construction code here

}

CMFCFileAndDocumentView::~CMFCFileAndDocumentView()
{
}

BOOL CMFCFileAndDocumentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCFileAndDocumentView drawing

void CMFCFileAndDocumentView::OnDraw(CDC* /*pDC*/)
{
	CMFCFileAndDocumentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCFileAndDocumentView printing

BOOL CMFCFileAndDocumentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCFileAndDocumentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCFileAndDocumentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCFileAndDocumentView diagnostics

#ifdef _DEBUG
void CMFCFileAndDocumentView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCFileAndDocumentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCFileAndDocumentDoc* CMFCFileAndDocumentView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCFileAndDocumentDoc)));
	return (CMFCFileAndDocumentDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCFileAndDocumentView message handlers


int CMFCFileAndDocumentView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here
    CMFCFileAndDocumentDoc *pDoc = GetDocument();
    CRect rect(0, 0, 0, 0);
    pDoc->m_richEdit.Create(ES_AUTOVSCROLL | ES_MULTILINE | WS_CHILD | ES_WANTRETURN | WS_VISIBLE | WS_VSCROLL, rect, this, 1);

    return 0;
}


void CMFCFileAndDocumentView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);

    // TODO: Add your message handler code here
    CMFCFileAndDocumentDoc *pDoc = GetDocument();
    CRect rect;
    GetClientRect(rect);
    pDoc->m_richEdit.SetWindowPos(&wndTop, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
}


void CMFCFileAndDocumentView::OnEditUndo()
{
    // TODO: Add your command handler code here
    CMFCFileAndDocumentDoc *pDoc = GetDocument();
    pDoc->m_richEdit.Undo();
}


void CMFCFileAndDocumentView::OnEditCopy()
{
    // TODO: Add your command handler code here
    CMFCFileAndDocumentDoc *pDoc = GetDocument();
    pDoc->m_richEdit.Copy();
}


void CMFCFileAndDocumentView::OnEditPaste()
{
    // TODO: Add your command handler code here
    CMFCFileAndDocumentDoc *pDoc = GetDocument();
    pDoc->m_richEdit.Paste();
}


void CMFCFileAndDocumentView::OnEditCut()
{
    // TODO: Add your command handler code here
    CMFCFileAndDocumentDoc *pDoc = GetDocument();
    pDoc->m_richEdit.Cut();
}
