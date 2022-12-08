
// MFCFileAndDocument.h : main header file for the MFCFileAndDocument application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCFileAndDocumentApp:
// See MFCFileAndDocument.cpp for the implementation of this class
//

class CMFCFileAndDocumentApp : public CWinAppEx
{
public:
	CMFCFileAndDocumentApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCFileAndDocumentApp theApp;
