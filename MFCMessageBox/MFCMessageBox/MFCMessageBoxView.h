
// MFCMessageBoxView.h : interface of the CMFCMessageBoxView class
//

#pragma once


class CMFCMessageBoxView : public CView
{
protected: // create from serialization only
	CMFCMessageBoxView();
	DECLARE_DYNCREATE(CMFCMessageBoxView)

// Attributes
public:
	CMFCMessageBoxDoc* GetDocument() const;

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
	virtual ~CMFCMessageBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
};

#ifndef _DEBUG  // debug version in MFCMessageBoxView.cpp
inline CMFCMessageBoxDoc* CMFCMessageBoxView::GetDocument() const
   { return reinterpret_cast<CMFCMessageBoxDoc*>(m_pDocument); }
#endif

