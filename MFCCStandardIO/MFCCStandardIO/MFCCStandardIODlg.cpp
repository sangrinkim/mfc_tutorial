
// MFCCStandardIODlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCCStandardIO.h"
#include "MFCCStandardIODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCStandardIODlg dialog



CMFCCStandardIODlg::CMFCCStandardIODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCCStandardIODlg::IDD, pParent)
    , m_strEditCtrol(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCStandardIODlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_strEditCtrol);
}

BEGIN_MESSAGE_MAP(CMFCCStandardIODlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_OPEN, &CMFCCStandardIODlg::OnBnClickedButtonOpen)
    ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCCStandardIODlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CMFCCStandardIODlg message handlers

BOOL CMFCCStandardIODlg::OnInitDialog()
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

void CMFCCStandardIODlg::OnPaint()
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
HCURSOR CMFCCStandardIODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCStandardIODlg::OnBnClickedButtonOpen()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    CStdioFile file;
    file.Open(L"C:\\Temp\\MFCDirectoryDEMO\\test.txt", CFile::modeRead | CFile::typeText);
    file.ReadString(m_strEditCtrol);
    file.Close();
    UpdateData(FALSE);
}


void CMFCCStandardIODlg::OnBnClickedButtonSave()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    CStdioFile file;
    if (m_strEditCtrol.GetLength() == 0)
    {
        AfxMessageBox(L"You must specify the text.");
        return;
    }
    file.Open(L"C:\\Temp\\MFCDirectoryDEMO\\test.txt", CFile::modeCreate | CFile::modeWrite | CFile::typeText);
    file.WriteString(m_strEditCtrol);
    file.Close();
}
