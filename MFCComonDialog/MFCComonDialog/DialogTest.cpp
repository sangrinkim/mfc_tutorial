// DialogTest.cpp : implementation file
//

#include "stdafx.h"
#include "MFCComonDialog.h"
#include "DialogTest.h"
#include "afxdialogex.h"


// CDialogTest dialog

IMPLEMENT_DYNAMIC(CDialogTest, CDialog)

CDialogTest::CDialogTest(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTest::IDD, pParent)
    , m_strDlg(_T(""))
{

}

CDialogTest::~CDialogTest()
{
}

void CDialogTest::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_TEXT, m_strDlg);
}


BEGIN_MESSAGE_MAP(CDialogTest, CDialog)
END_MESSAGE_MAP()


// CDialogTest message handlers
