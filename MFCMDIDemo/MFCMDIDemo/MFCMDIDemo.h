
// MFCMDIDemo.h : main header file for the MFCMDIDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMDIDemoApp:
// See MFCMDIDemo.cpp for the implementation of this class
//

class CMFCMDIDemoApp : public CWinAppEx
{
public:
	CMFCMDIDemoApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMDIDemoApp theApp;
