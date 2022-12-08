
// MFCMessageHandlerView.h : interface of the CMFCMessageHandlerView class
//

#pragma once


class CMFCMessageHandlerView : public CView
{
protected: // create from serialization only
	CMFCMessageHandlerView();
	DECLARE_DYNCREATE(CMFCMessageHandlerView)

// Attributes
public:
	CMFCMessageHandlerDoc* GetDocument() const;
    CString m_string;
    CPoint m_xy;

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
	virtual ~CMFCMessageHandlerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in MFCMessageHandlerView.cpp
inline CMFCMessageHandlerDoc* CMFCMessageHandlerView::GetDocument() const
   { return reinterpret_cast<CMFCMessageHandlerDoc*>(m_pDocument); }
#endif

