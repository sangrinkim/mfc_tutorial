
// MFCComonDialogView.h : interface of the CMFCComonDialogView class
//

#pragma once


class CMFCComonDialogView : public CView
{
protected: // create from serialization only
	CMFCComonDialogView();
	DECLARE_DYNCREATE(CMFCComonDialogView)

// Attributes
public:
	CMFCComonDialogDoc* GetDocument() const;

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
	virtual ~CMFCComonDialogView();
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
    afx_msg void OnIddDialogTest();
    afx_msg void OnDialogFontcolor();
    COLORREF m_color;
    afx_msg void OnDialogChangetext();
};

#ifndef _DEBUG  // debug version in MFCComonDialogView.cpp
inline CMFCComonDialogDoc* CMFCComonDialogView::GetDocument() const
   { return reinterpret_cast<CMFCComonDialogDoc*>(m_pDocument); }
#endif

