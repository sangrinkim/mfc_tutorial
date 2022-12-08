
// MFCComonDialog.h : main header file for the MFCComonDialog application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCComonDialogApp:
// See MFCComonDialog.cpp for the implementation of this class
//

class CMFCComonDialogApp : public CWinApp
{
public:
	CMFCComonDialogApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCComonDialogApp theApp;
