// property.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTab.h"
#include "property.h"
#include "afxdialogex.h"


// CPage1 dialog

IMPLEMENT_DYNAMIC(CPage1, CPropertyPage)

CPage1::CPage1()
	: CPropertyPage(CPage1::IDD)
    , m_strDlg(_T(""))
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_TEXT, m_strDlg);
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
END_MESSAGE_MAP()


// CPage1 message handlers
// C:\Codes\MFC2013\MFCTab\MFCTab\property.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTab.h"
#include "C:\Codes\MFC2013\MFCTab\MFCTab\property.h"
#include "afxdialogex.h"


// CPage2 dialog

IMPLEMENT_DYNAMIC(CPage2, CPropertyPage)

CPage2::CPage2()
	: CPropertyPage(CPage2::IDD)
    , m_colorDlg(0)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_COLOR, m_colorDlg);
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
END_MESSAGE_MAP()


// CPage2 message handlers
// C:\Codes\MFC2013\MFCTab\MFCTab\property.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTab.h"
#include "C:\Codes\MFC2013\MFCTab\MFCTab\property.h"
#include "afxdialogex.h"


// CPage3 dialog

IMPLEMENT_DYNAMIC(CPage3, CPropertyPage)

CPage3::CPage3()
	: CPropertyPage(CPage3::IDD)
    , m_x(0)
    , m_y(0)
{

}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_x, m_x);
    DDX_Text(pDX, IDC_EDIT_Y, m_y);
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
END_MESSAGE_MAP()


// CPage3 message handlers
// C:\Codes\MFC2013\MFCTab\MFCTab\property.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTab.h"
#include "C:\Codes\MFC2013\MFCTab\MFCTab\property.h"


// CTabSheet

IMPLEMENT_DYNAMIC(CTabSheet, CPropertySheet)

CTabSheet::CTabSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CTabSheet::CTabSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
    AddPage(&m_page1);
    AddPage(&m_page2);
    AddPage(&m_page3);
}

CTabSheet::~CTabSheet()
{
}


BEGIN_MESSAGE_MAP(CTabSheet, CPropertySheet)
END_MESSAGE_MAP()


// CTabSheet message handlers
