
// MFCModalDemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCModalDemoApp:
// See MFCModalDemo.cpp for the implementation of this class
//

class CMFCModalDemoApp : public CWinApp
{
public:
	CMFCModalDemoApp();

// Overrides
public:
	virtual BOOL InitInstance();
    HACCEL m_hAccelTable;

// Implementation

	DECLARE_MESSAGE_MAP()
    virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
};

extern CMFCModalDemoApp theApp;