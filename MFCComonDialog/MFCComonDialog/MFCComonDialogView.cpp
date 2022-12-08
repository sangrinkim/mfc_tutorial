
// MFCComonDialogView.cpp : implementation of the CMFCComonDialogView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCComonDialog.h"
#endif

#include "MFCComonDialogDoc.h"
#include "MFCComonDialogView.h"
#include "DialogTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCComonDialogView

IMPLEMENT_DYNCREATE(CMFCComonDialogView, CView)

BEGIN_MESSAGE_MAP(CMFCComonDialogView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(IDD_DIALOG_TEST, &CMFCComonDialogView::OnIddDialogTest)
    ON_COMMAND(ID_DIALOG_FONTCOLOR, &CMFCComonDialogView::OnDialogFontcolor)
    ON_COMMAND(ID_DIALOG_CHANGETEXT, &CMFCComonDialogView::OnDialogChangetext)
END_MESSAGE_MAP()

// CMFCComonDialogView construction/destruction

CMFCComonDialogView::CMFCComonDialogView()
    : m_string(_T("Learning Common Dialog"))
{
	// TODO: add construction code here
    m_color = RGB(255, 0, 0);
}

CMFCComonDialogView::~CMFCComonDialogView()
{
}

BOOL CMFCComonDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCComonDialogView drawing

void CMFCComonDialogView::OnDraw(CDC* pDC)
{
	CMFCComonDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    CRect r;
    GetClientRect(r);
    pDC->SetTextColor(m_color);
    pDC->SetTextAlign(TA_CENTER);
    pDC->TextOutW(r.right / 2, r.bottom / 2, m_string);
}


// CMFCComonDialogView printing

BOOL CMFCComonDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCComonDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCComonDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCComonDialogView diagnostics

#ifdef _DEBUG
void CMFCComonDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCComonDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCComonDialogDoc* CMFCComonDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCComonDialogDoc)));
	return (CMFCComonDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCComonDialogView message handlers


void CMFCComonDialogView::OnIddDialogTest()
{
    // TODO: Add your command handler code here
    CDialogTest dlg;
    //dlg.DoModal();
    dlg.m_strDlg = m_string;
    if (dlg.DoModal() == IDOK)
    {
        m_string = dlg.m_strDlg;
        Invalidate();
    }
}


void CMFCComonDialogView::OnDialogFontcolor()
{
    // TODO: Add your command handler code here
    CColorDialog CDlg;
    CDlg.DoModal();
    m_color = CDlg.GetColor();
    Invalidate();
}


void CMFCComonDialogView::OnDialogChangetext()
{
    // TODO: Add your command handler code here
    CDialogTest dlg;
    dlg.m_strDlg = m_string;
    if (dlg.DoModal() == IDOK)
    {
        m_string = dlg.m_strDlg;
        Invalidate();
    }

}
