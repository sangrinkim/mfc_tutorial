
// MFCControlManagementDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCControlManagement.h"
#include "MFCControlManagementDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCControlManagementDlg dialog



CMFCControlManagementDlg::CMFCControlManagementDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCControlManagementDlg::IDD, pParent)
    , m_enableDisableVal(FALSE)
    , m_editControlVal(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCControlManagementDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK1, m_enableDisableCheck);
    DDX_Control(pDX, IDC_EDIT1, m_myEditControl);
    DDX_Check(pDX, IDC_CHECK1, m_enableDisableVal);
    DDX_Text(pDX, IDC_EDIT1, m_editControlVal);
}

BEGIN_MESSAGE_MAP(CMFCControlManagementDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_CHECK1, &CMFCControlManagementDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CMFCControlManagementDlg message handlers

BOOL CMFCControlManagementDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
    UpdateData(TRUE);
    if (m_enableDisableVal)
    {
        m_myEditControl.EnableWindow(TRUE);
    }
    else
    {
        m_myEditControl.EnableWindow(FALSE);
    }

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCControlManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCControlManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCControlManagementDlg::OnBnClickedCheck1()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    if (m_enableDisableVal)
    {
        m_myEditControl.EnableWindow(TRUE);
    }
    else
    {
        m_myEditControl.EnableWindow(FALSE);
    }
}
