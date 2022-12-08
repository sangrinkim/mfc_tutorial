
// MFCClock.h : main header file for the MFCClock application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCClockApp:
// See MFCClock.cpp for the implementation of this class
//

class CMFCClockApp : public CWinAppEx
{
public:
	CMFCClockApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCClockApp theApp;
