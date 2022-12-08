
// MFCFileAndDocumentDoc.h : interface of the CMFCFileAndDocumentDoc class
//


#pragma once
#include "afxcmn.h"


class CMFCFileAndDocumentDoc : public CDocument
{
protected: // create from serialization only
	CMFCFileAndDocumentDoc();
	DECLARE_DYNCREATE(CMFCFileAndDocumentDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCFileAndDocumentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
    CRichEditCtrl m_richEdit;
};
