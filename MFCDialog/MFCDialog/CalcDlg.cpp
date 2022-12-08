// CalcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDialog.h"
#include "CalcDlg.h"
#include "afxdialogex.h"


// CCalcDlg dialog

IMPLEMENT_DYNAMIC(CCalcDlg, CDialog)

CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalcDlg::IDD, pParent)
    , m_Num1(0)
    , m_Num2(0)
    , m_Result(0)
{

}

CCalcDlg::~CCalcDlg()
{
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_NUM1, m_Num1);
    DDX_Text(pDX, IDC_EDIT_NUM2, m_Num2);
    DDX_Text(pDX, IDC_EDIT_RESULT, m_Result);
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
    ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalcDlg::OnClickedButtonAdd)
    ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &CCalcDlg::OnClickedButtonSubtract)
    ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalcDlg::OnClickedButtonMultiply)
    ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalcDlg::OnClickedButtonDivide)
    ON_BN_CLICKED(IDC_BUTTON_OK, &CCalcDlg::OnClickedButtonOk)
END_MESSAGE_MAP()


// CCalcDlg message handlers


void CCalcDlg::OnClickedButtonAdd()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    m_Result = m_Num1 + m_Num2;
    UpdateData(FALSE);
}


void CCalcDlg::OnClickedButtonSubtract()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    m_Result = m_Num1 - m_Num2;
    UpdateData(FALSE);
}


void CCalcDlg::OnClickedButtonMultiply()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    m_Result = m_Num1 * m_Num2;
    UpdateData(FALSE);
}


void CCalcDlg::OnClickedButtonDivide()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    m_Result = m_Num1 / m_Num2;
    UpdateData(FALSE);
}


void CCalcDlg::OnClickedButtonOk()
{
    // TODO: Add your control notification handler code here
    m_Result = m_Num1 = m_Num2 = 0;
    UpdateData(FALSE);
}
