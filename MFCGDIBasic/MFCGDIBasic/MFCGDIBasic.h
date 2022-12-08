
// MFCGDIBasic.h : main header file for the MFCGDIBasic application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCGDIBasicApp:
// See MFCGDIBasic.cpp for the implementation of this class
//

class CMFCGDIBasicApp : public CWinApp
{
public:
	CMFCGDIBasicApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCGDIBasicApp theApp;
