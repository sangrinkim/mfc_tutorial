
// MFCModalDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCModalDemo.h"
#include "MFCModalDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCModalDemoDlg dialog



CMFCModalDemoDlg::CMFCModalDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCModalDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCModalDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCModalDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_COMMAND(ID_FILE_NEW32771, &CMFCModalDemoDlg::OnFileNew32771)
END_MESSAGE_MAP()


// CMFCModalDemoDlg message handlers

BOOL CMFCModalDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    if (!m_wndToolBar.Create(this)
        || !m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
    {
        TRACE0("Failed to Create Dialog Toolbar\n");
        EndDialog(IDCANCEL);
    }
    butD = TRUE;
    CRect rcClientOld;
    CRect rcClientNew;

    GetClientRect(rcClientOld);
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0, reposQuery, rcClientNew);
    CPoint ptOffset(rcClientNew.left - rcClientOld.left, rcClientNew.top - rcClientOld.top);

    CRect rcChild;
    CWnd* pwndChild = GetWindow(GW_CHILD);

    while (pwndChild)
    {
        pwndChild -> GetWindowRect(rcChild);
        ScreenToClient(rcChild);

        rcChild.OffsetRect(ptOffset);
        pwndChild -> MoveWindow(rcChild, FALSE);
        pwndChild = pwndChild -> GetNextWindow();
    }

    CRect rcWindow;
    GetWindowRect(rcWindow);

    rcWindow.right += rcClientOld.Width() - rcClientNew.Width();
    rcWindow.bottom += rcClientOld.Height() - rcClientNew.Height();

    MoveWindow(rcWindow, FALSE);

    RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

    // ShowWindow(SW_NORMAL);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCModalDemoDlg::OnPaint()
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
HCURSOR CMFCModalDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCModalDemoDlg::OnFileNew32771()
{
    // TODO: Add your command handler code here
    MessageBox(L"File > New menu option");
}
