
// MFCGDIBasicView.h : interface of the CMFCGDIBasicView class
//

#pragma once
#include "atltypes.h"

#define HBOX 0
#define HLINE 1
#define HCIRCLE 2
#define HTEXT 3


class CMFCGDIBasicView : public CView
{
protected: // create from serialization only
	CMFCGDIBasicView();
	DECLARE_DYNCREATE(CMFCGDIBasicView)

// Attributes
public:
	CMFCGDIBasicDoc* GetDocument() const;

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
	virtual ~CMFCGDIBasicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    CRect m_rect;
    int m_style;
    CString m_string;
    afx_msg void OnDrawQuadrangle();
    afx_msg void OnDrawLine();
    afx_msg void OnDrawCircle();
    afx_msg void OnDrawFont();
    COLORREF m_color;
    afx_msg void OnColorBlack();
    afx_msg void OnColorBlue();
    afx_msg void OnColorGreen();
    afx_msg void OnColorRed();
};

#ifndef _DEBUG  // debug version in MFCGDIBasicView.cpp
inline CMFCGDIBasicDoc* CMFCGDIBasicView::GetDocument() const
   { return reinterpret_cast<CMFCGDIBasicDoc*>(m_pDocument); }
#endif

