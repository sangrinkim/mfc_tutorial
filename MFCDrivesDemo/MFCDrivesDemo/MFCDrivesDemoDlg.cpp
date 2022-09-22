
// MFCDrivesDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDrivesDemo.h"
#include "MFCDrivesDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrivesDemoDlg dialog



CMFCDrivesDemoDlg::CMFCDrivesDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDrivesDemoDlg::IDD, pParent)
    , m_strDrives(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDrivesDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STATIC_TEXT, m_strDrives);
}

BEGIN_MESSAGE_MAP(CMFCDrivesDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON2, &CMFCDrivesDemoDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCDrivesDemoDlg message handlers

BOOL CMFCDrivesDemoDlg::OnInitDialog()
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

void CMFCDrivesDemoDlg::OnPaint()
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
HCURSOR CMFCDrivesDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDrivesDemoDlg::OnBnClickedButton2()
{
    // TODO: Add your control notification handler code here
    wchar_t drive[512] = L"A:";
	unsigned int drives = GetLogicalDrives();
	CString strListOfDrives = L"The list of drives is ";

	if( drives == 0 )
		AfxMessageBox(L"There is no drive to show");
	else
	{
		while(drives)
		{
			if( drives & 1 )
			{
				strListOfDrives += drive;
				strListOfDrives += L", ";
			}

			drive[0]++;
			drives >>= 1;
		}

        m_strDrives = strListOfDrives;
		UpdateData(FALSE);
	}
}
