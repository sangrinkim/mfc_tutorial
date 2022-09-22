
// MFCSDIDemoView.h : interface of the CMFCSDIDemoView class
//

#pragma once


class CMFCSDIDemoView : public CView
{
protected: // create from serialization only
	CMFCSDIDemoView();
	DECLARE_DYNCREATE(CMFCSDIDemoView)

// Attributes
public:
	CMFCSDIDemoDoc* GetDocument() const;

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
	virtual ~CMFCSDIDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCSDIDemoView.cpp
inline CMFCSDIDemoDoc* CMFCSDIDemoView::GetDocument() const
   { return reinterpret_cast<CMFCSDIDemoDoc*>(m_pDocument); }
#endif

