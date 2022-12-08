
// MFCFileAndDocumentDoc.cpp : implementation of the CMFCFileAndDocumentDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCFileAndDocument.h"
#endif

#include "MFCFileAndDocumentDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCFileAndDocumentDoc

IMPLEMENT_DYNCREATE(CMFCFileAndDocumentDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCFileAndDocumentDoc, CDocument)
END_MESSAGE_MAP()


// CMFCFileAndDocumentDoc construction/destruction

CMFCFileAndDocumentDoc::CMFCFileAndDocumentDoc()
{
	// TODO: add one-time construction code here

}

CMFCFileAndDocumentDoc::~CMFCFileAndDocumentDoc()
{
}

BOOL CMFCFileAndDocumentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    m_richEdit.SetSel(0, -1);
    m_richEdit.Clear();

	return TRUE;
}




// CMFCFileAndDocumentDoc serialization

void CMFCFileAndDocumentDoc::Serialize(CArchive& ar)
{
    CString m_string;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
        m_richEdit.SetSel(0, -1);
        m_string = m_richEdit.GetSelText();
        ar << m_string;
	}
	else
	{
		// TODO: add loading code here
        ar >> m_string;
        m_richEdit.SetSel(0, -1);
        m_richEdit.Clear();
        m_richEdit.ReplaceSel(m_string);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCFileAndDocumentDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCFileAndDocumentDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCFileAndDocumentDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCFileAndDocumentDoc diagnostics

#ifdef _DEBUG
void CMFCFileAndDocumentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCFileAndDocumentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCFileAndDocumentDoc commands
