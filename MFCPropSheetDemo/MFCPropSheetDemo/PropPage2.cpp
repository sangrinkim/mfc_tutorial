// PropPage2.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPropSheetDemo.h"
#include "PropPage2.h"
#include "afxdialogex.h"


// PropPage2 dialog

IMPLEMENT_DYNAMIC(PropPage2, CPropertyPage)

PropPage2::PropPage2()
	: CPropertyPage(PropPage2::IDD)
{

}

PropPage2::~PropPage2()
{
}

void PropPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PropPage2, CPropertyPage)
END_MESSAGE_MAP()


// PropPage2 message handlers
