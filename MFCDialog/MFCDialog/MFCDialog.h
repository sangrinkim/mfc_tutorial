
// MFCDialog.h : main header file for the MFCDialog application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCDialogApp:
// See MFCDialog.cpp for the implementation of this class
//

class CMFCDialogApp : public CWinApp
{
public:
	CMFCDialogApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDialogApp theApp;
