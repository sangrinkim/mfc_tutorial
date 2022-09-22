
// MFCMultithreadingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCMultithreading.h"
#include "MFCMultithreadingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMultithreadingDlg dialog
int currValue;
int maxValue;
BOOL stopNow;



CMFCMultithreadingDlg::CMFCMultithreadingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCMultithreadingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCMultithreadingDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STATIC_TEXT, m_ctrlStatus);
}

BEGIN_MESSAGE_MAP(CMFCMultithreadingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CMFCMultithreadingDlg::OnBnClickedButton1)
    ON_WM_TIMER()
    ON_BN_CLICKED(IDC_BUTTON2, &CMFCMultithreadingDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCMultithreadingDlg message handlers

BOOL CMFCMultithreadingDlg::OnInitDialog()
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

void CMFCMultithreadingDlg::OnPaint()
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
HCURSOR CMFCMultithreadingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT MyThreadProc(LPVOID Param)
// AfxBeginThread
{
    while (!stopNow && (currValue < maxValue))
    {
        currValue++;
        Sleep(50);  // would do some work here
    }

    return TRUE;
}

void CMFCMultithreadingDlg::OnBnClickedButton1()
{
    // TODO: Add your control notification handler code here
    currValue = 0;
    maxValue = 5000;
    stopNow = 0;
    m_ctrlStatus.SetWindowText(L"Stating...");
    SetTimer(1234, 333, 0); // 3 times per second

    AfxBeginThread(MyThreadProc, 0); // <<== START THE THREAD
}

void CMFCMultithreadingDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default
    CString sStatusMsg;
    sStatusMsg.Format(L"Running: %d", currValue);
    m_ctrlStatus.SetWindowText(sStatusMsg);

    CDialogEx::OnTimer(nIDEvent);
}

void CMFCMultithreadingDlg::OnBnClickedButton2()
{
    // TODO: Add your control notification handler code here
    stopNow = TRUE;
    KillTimer(1234);
    m_ctrlStatus.SetWindowText(L"Stopped");
}


