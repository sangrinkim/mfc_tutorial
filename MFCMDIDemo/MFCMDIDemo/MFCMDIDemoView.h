
// MFCMDIDemoView.h : interface of the CMFCMDIDemoView class
//

#pragma once


class CMFCMDIDemoView : public CView
{
protected: // create from serialization only
	CMFCMDIDemoView();
	DECLARE_DYNCREATE(CMFCMDIDemoView)

// Attributes
public:
	CMFCMDIDemoDoc* GetDocument() const;

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
	virtual ~CMFCMDIDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCMDIDemoView.cpp
inline CMFCMDIDemoDoc* CMFCMDIDemoView::GetDocument() const
   { return reinterpret_cast<CMFCMDIDemoDoc*>(m_pDocument); }
#endif

