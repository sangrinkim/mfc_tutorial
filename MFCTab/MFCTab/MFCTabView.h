
// MFCTabView.h : interface of the CMFCTabView class
//

#pragma once
#include "atltypes.h"


class CMFCTabView : public CView
{
protected: // create from serialization only
	CMFCTabView();
	DECLARE_DYNCREATE(CMFCTabView)

// Attributes
public:
	CMFCTabDoc* GetDocument() const;

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
	virtual ~CMFCTabView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    CString m_string;
    COLORREF m_color;
    CPoint m_xy;
    afx_msg void OnTabDialog();
};

#ifndef _DEBUG  // debug version in MFCTabView.cpp
inline CMFCTabDoc* CMFCTabView::GetDocument() const
   { return reinterpret_cast<CMFCTabDoc*>(m_pDocument); }
#endif

