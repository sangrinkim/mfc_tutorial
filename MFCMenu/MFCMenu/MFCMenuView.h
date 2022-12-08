
// MFCMenuView.h : interface of the CMFCMenuView class
//

#pragma once


class CMFCMenuView : public CView
{
protected: // create from serialization only
	CMFCMenuView();
	DECLARE_DYNCREATE(CMFCMenuView)

// Attributes
public:
	CMFCMenuDoc* GetDocument() const;

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
	virtual ~CMFCMenuView();
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
    afx_msg void OnColorBlack();
    afx_msg void OnColorBlue();
    afx_msg void OnColorGreen();
    afx_msg void OnColorRed();
};

#ifndef _DEBUG  // debug version in MFCMenuView.cpp
inline CMFCMenuDoc* CMFCMenuView::GetDocument() const
   { return reinterpret_cast<CMFCMenuDoc*>(m_pDocument); }
#endif

