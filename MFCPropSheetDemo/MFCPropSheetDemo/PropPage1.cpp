// PropPage1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPropSheetDemo.h"
#include "PropPage1.h"
#include "afxdialogex.h"
//#include "resource.h"


// CPropPage1 dialog

IMPLEMENT_DYNAMIC(CPropPage1, CPropertyPage)

CPropPage1::CPropPage1()
	: CPropertyPage(CPropPage1::IDD)
{

}

CPropPage1::~CPropPage1()
{
}

void CPropPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPropPage1, CPropertyPage)
END_MESSAGE_MAP()


// CPropPage1 message handlers
