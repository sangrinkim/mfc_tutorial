
// MFCTab.h : main header file for the MFCTab application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCTabApp:
// See MFCTab.cpp for the implementation of this class
//

class CMFCTabApp : public CWinApp
{
public:
	CMFCTabApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTabApp theApp;
