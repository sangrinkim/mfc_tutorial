
// MFCStatusBar.h : main header file for the MFCStatusBar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCStatusBarApp:
// See MFCStatusBar.cpp for the implementation of this class
//

class CMFCStatusBarApp : public CWinApp
{
public:
	CMFCStatusBarApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCStatusBarApp theApp;
