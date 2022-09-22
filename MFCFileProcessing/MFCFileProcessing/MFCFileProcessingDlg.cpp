
// MFCFileProcessingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCFileProcessing.h"
#include "MFCFileProcessingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFileProcessingDlg dialog



CMFCFileProcessingDlg::CMFCFileProcessingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCFileProcessingDlg::IDD, pParent)
    , m_strEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCFileProcessingDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, m_editCtrl);
    DDX_Text(pDX, IDC_EDIT1, m_strEdit);
}

BEGIN_MESSAGE_MAP(CMFCFileProcessingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_OPEN, &CMFCFileProcessingDlg::OnBnClickedButtonOpen)
    ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCFileProcessingDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CMFCFileProcessingDlg message handlers

BOOL CMFCFileProcessingDlg::OnInitDialog()
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

void CMFCFileProcessingDlg::OnPaint()
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
HCURSOR CMFCFileProcessingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCFileProcessingDlg::OnBnClickedButtonOpen()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    CFile file;

    file.Open(L"ArchiveText.rpr", CFile::modeRead);
    if(file)
    {
        CArchive ar(&file, CArchive::load);

        ar >> m_strEdit;

        ar.Close();
        file.Close();
    }
    UpdateData(FALSE);
}


void CMFCFileProcessingDlg::OnBnClickedButtonSave()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_strEdit.GetLength() == 0)
    {
        AfxMessageBox(L"You must enter the name of the text.");
        return;
    }
    CFile file;

    file.Open(L"ArchiveText.rpr", CFile::modeCreate | CFile::modeWrite);
    CArchive ar(&file, CArchive::store);
    ar << m_strEdit;

    ar.Close();
    file.Close();
}
