
// MFCFileProcessing.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCFileProcessingApp:
// See MFCFileProcessing.cpp for the implementation of this class
//

class CMFCFileProcessingApp : public CWinApp
{
public:
	CMFCFileProcessingApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCFileProcessingApp theApp;