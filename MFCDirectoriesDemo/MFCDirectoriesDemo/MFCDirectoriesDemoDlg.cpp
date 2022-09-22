
// MFCDirectoriesDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDirectoriesDemo.h"
#include "MFCDirectoriesDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDirectoriesDemoDlg dialog



CMFCDirectoriesDemoDlg::CMFCDirectoriesDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDirectoriesDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDirectoriesDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDirectoriesDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_CREATE, &CMFCDirectoriesDemoDlg::OnBnClickedButtonCreate)
    ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMFCDirectoriesDemoDlg::OnBnClickedButtonDelete)
    ON_BN_CLICKED(IDC_BUTTON_MOVE, &CMFCDirectoriesDemoDlg::OnBnClickedButtonMove)
END_MESSAGE_MAP()


// CMFCDirectoriesDemoDlg message handlers

BOOL CMFCDirectoriesDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDirectoriesDemoDlg::OnPaint()
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
HCURSOR CMFCDirectoriesDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDirectoriesDemoDlg::OnBnClickedButtonCreate()
{
    // TODO: Add your control notification handler code here
    SECURITY_ATTRIBUTES saPermissions;

    saPermissions.nLength = sizeof(SECURITY_ATTRIBUTES);
    saPermissions.lpSecurityDescriptor = NULL;
    saPermissions.bInheritHandle = TRUE;

    if (CreateDirectory(L"C:\\Temp\\MFCDirectoryDEMO", &saPermissions) == TRUE)
    {
        AfxMessageBox(L"The directory was created.");
    }
    CreateDirectory(L"C:\\Temp\\MFCDirectoryDEMO\\Dir1", NULL);
    CreateDirectory(L"C:\\Temp\\MFCDirectoryDEMO\\Dir2", NULL);
}


void CMFCDirectoriesDemoDlg::OnBnClickedButtonDelete()
{
    // TODO: Add your control notification handler code here
    if (RemoveDirectory(L"C:\\Temp\\MFCDirectoryDEMO\\Dir1") == TRUE)
    {
        AfxMessageBox(L"The directory has been deleted");
    }
}


void CMFCDirectoriesDemoDlg::OnBnClickedButtonMove()
{
    // TODO: Add your control notification handler code here
    CreateDirectory(L"C:\\Temp\\MFCDirectory", NULL);

    if (MoveFile(L"C:\\Temp\\MFCDirectoryDEMO\\Dir1", L"C:\\Temp\\MFCDirectory\\Dir1") == TRUE)
    {
        AfxMessageBox(L"The directory has been moved");
    }
}
