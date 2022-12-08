
// MFCClockView.cpp : implementation of the CMFCClockView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCClock.h"
#endif

#include "MFCClockDoc.h"
#include "MFCClockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCClockView

IMPLEMENT_DYNCREATE(CMFCClockView, CView)

BEGIN_MESSAGE_MAP(CMFCClockView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_CREATE()
    ON_WM_TIMER()
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
    ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCClockView construction/destruction

CMFCClockView::CMFCClockView()
    : m_timer(false)
    , m_string(_T(""))
{
	// TODO: add construction code here

}

CMFCClockView::~CMFCClockView()
{
}

BOOL CMFCClockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCClockView drawing

void CMFCClockView::OnDraw(CDC* pDC)
{
	CMFCClockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    CRect r;
    GetClientRect(&r);
    pDC->DrawText(m_string, r, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMFCClockView printing

BOOL CMFCClockView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCClockView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCClockView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCClockView diagnostics

#ifdef _DEBUG
void CMFCClockView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCClockView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCClockDoc* CMFCClockView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCClockDoc)));
	return (CMFCClockDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCClockView message handlers


int CMFCClockView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here
    SetTimer(0, 1000, NULL);
    m_timer = TRUE;

    return 0;
}


void CMFCClockView::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default
    CTime t;
    t = CTime::GetCurrentTime();
    m_string.Format(_T("Now - %d : %d : %d"), t.GetHour(), t.GetMinute(), t.GetSecond());
    Invalidate();

    CView::OnTimer(nIDEvent);
}


void CMFCClockView::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    if (!m_timer)
    {
        if (AfxMessageBox(_T("Do you want to start timer?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
            SetTimer(0, 1000, NULL);
            m_timer = TRUE;
        }
    }
    else
    {
        AfxMessageBox(_T("Timer already is working."));
    }

    CView::OnLButtonDown(nFlags, point);
}


void CMFCClockView::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    if (!m_timer)
    {
        AfxMessageBox(_T("Timer was stopped."));
    }
    else
    {
        if (AfxMessageBox(_T("Do you want to stop timer?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
            KillTimer(0);
            m_timer = FALSE;
        }
    }

    CView::OnRButtonDown(nFlags, point);
}


void CMFCClockView::OnDestroy()
{
    CView::OnDestroy();

    // TODO: Add your message handler code here
    if (m_timer)
    {
        KillTimer(0);
    }
}
