
// MFCModalessDialogView.h : interface of the CMFCModalessDialogView class
//

#pragma once

class CModalessDlg;

class CMFCModalessDialogView : public CView
{
protected: // create from serialization only
	CMFCModalessDialogView();
	DECLARE_DYNCREATE(CMFCModalessDialogView)

private:
    CModalessDlg* m_pDlg;

// Attributes
public:
	CMFCModalessDialogDoc* GetDocument() const;

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
	virtual ~CMFCModalessDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    afx_msg LONG OnGoodBye(UINT wParam, LONG lParam);
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCModalessDialogView.cpp
inline CMFCModalessDialogDoc* CMFCModalessDialogView::GetDocument() const
   { return reinterpret_cast<CMFCModalessDialogDoc*>(m_pDocument); }
#endif

