
// MFCToolBar.h : main header file for the MFCToolBar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCToolBarApp:
// See MFCToolBar.cpp for the implementation of this class
//

class CMFCToolBarApp : public CWinApp
{
public:
	CMFCToolBarApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCToolBarApp theApp;
