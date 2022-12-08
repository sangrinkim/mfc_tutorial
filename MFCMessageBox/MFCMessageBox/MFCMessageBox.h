
// MFCMessageBox.h : main header file for the MFCMessageBox application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMessageBoxApp:
// See MFCMessageBox.cpp for the implementation of this class
//

class CMFCMessageBoxApp : public CWinApp
{
public:
	CMFCMessageBoxApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMessageBoxApp theApp;
