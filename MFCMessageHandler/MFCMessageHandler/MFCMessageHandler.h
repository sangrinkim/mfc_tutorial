
// MFCMessageHandler.h : main header file for the MFCMessageHandler application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMessageHandlerApp:
// See MFCMessageHandler.cpp for the implementation of this class
//

class CMFCMessageHandlerApp : public CWinApp
{
public:
	CMFCMessageHandlerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMessageHandlerApp theApp;
