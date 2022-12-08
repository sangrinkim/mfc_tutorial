// ModalessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCModalessDialog.h"
#include "ModalessDlg.h"
#include "afxdialogex.h"


// CModalessDlg dialog

IMPLEMENT_DYNAMIC(CModalessDlg, CDialog)

CModalessDlg::CModalessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModalessDlg::IDD, pParent)
    , m_Text(_T(""))
{
    m_pView = NULL;
}

CModalessDlg::CModalessDlg(CView* pView)
{
    m_pView = pView;
}

BOOL CModalessDlg::Create()
{
    return CDialog::Create(CModalessDlg::IDD);
}

CModalessDlg::~CModalessDlg()
{
}

void CModalessDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_TEXT, m_Text);
}


BEGIN_MESSAGE_MAP(CModalessDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CModalessDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CModalessDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CModalessDlg message handlers


void CModalessDlg::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    if (m_pView != NULL)
    {
        UpdateData(TRUE);
        m_pView->PostMessageW(WM_GOODBYE, IDOK);
    }
    else
    {
        CDialog::OnOK();
    }

}


void CModalessDlg::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    if (m_pView != NULL)
    {
        m_pView->PostMessageW(WM_GOODBYE, IDCANCEL);
    }

    CDialog::OnCancel();
}
