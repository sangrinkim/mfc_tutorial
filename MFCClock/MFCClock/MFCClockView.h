
// MFCClockView.h : interface of the CMFCClockView class
//

#pragma once


class CMFCClockView : public CView
{
protected: // create from serialization only
	CMFCClockView();
	DECLARE_DYNCREATE(CMFCClockView)

// Attributes
public:
	CMFCClockDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    bool m_timer;
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    CString m_string;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnDestroy();
};

#ifndef _DEBUG  // debug version in MFCClockView.cpp
inline CMFCClockDoc* CMFCClockView::GetDocument() const
   { return reinterpret_cast<CMFCClockDoc*>(m_pDocument); }
#endif

