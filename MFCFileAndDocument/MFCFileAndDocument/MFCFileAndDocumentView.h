
// MFCFileAndDocumentView.h : interface of the CMFCFileAndDocumentView class
//

#pragma once


class CMFCFileAndDocumentView : public CView
{
protected: // create from serialization only
	CMFCFileAndDocumentView();
	DECLARE_DYNCREATE(CMFCFileAndDocumentView)

// Attributes
public:
	CMFCFileAndDocumentDoc* GetDocument() const;

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
	virtual ~CMFCFileAndDocumentView();
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
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnEditUndo();
    afx_msg void OnEditCopy();
    afx_msg void OnEditPaste();
    afx_msg void OnEditCut();
};

#ifndef _DEBUG  // debug version in MFCFileAndDocumentView.cpp
inline CMFCFileAndDocumentDoc* CMFCFileAndDocumentView::GetDocument() const
   { return reinterpret_cast<CMFCFileAndDocumentDoc*>(m_pDocument); }
#endif

