
// MFCStatusBarView.h : interface of the CMFCStatusBarView class
//

#pragma once


class CMFCStatusBarView : public CView
{
protected: // create from serialization only
	CMFCStatusBarView();
	DECLARE_DYNCREATE(CMFCStatusBarView)

// Attributes
public:
	CMFCStatusBarDoc* GetDocument() const;

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
	virtual ~CMFCStatusBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCStatusBarView.cpp
inline CMFCStatusBarDoc* CMFCStatusBarView::GetDocument() const
   { return reinterpret_cast<CMFCStatusBarDoc*>(m_pDocument); }
#endif

