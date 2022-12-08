
// MFCToolBarView.h : interface of the CMFCToolBarView class
//

#pragma once


class CMFCToolBarView : public CView
{
protected: // create from serialization only
	CMFCToolBarView();
	DECLARE_DYNCREATE(CMFCToolBarView)

// Attributes
public:
	CMFCToolBarDoc* GetDocument() const;

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
	virtual ~CMFCToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    COLORREF m_color;
    afx_msg void OnButtonBlue();
    afx_msg void OnButtonGreen();
    afx_msg void OnButtonRed();
};

#ifndef _DEBUG  // debug version in MFCToolBarView.cpp
inline CMFCToolBarDoc* CMFCToolBarView::GetDocument() const
   { return reinterpret_cast<CMFCToolBarDoc*>(m_pDocument); }
#endif

