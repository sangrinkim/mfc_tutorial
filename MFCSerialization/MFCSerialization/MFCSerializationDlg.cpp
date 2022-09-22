
// MFCSerializationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCSerialization.h"
#include "MFCSerializationDlg.h"
#include "afxdialogex.h"
#include "Employee.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSerializationDlg dialog



CMFCSerializationDlg::CMFCSerializationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSerializationDlg::IDD, pParent)
    , m_id(0)
    , m_strName(_T(""))
    , m_age(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSerializationDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_ID, m_id);
    DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
    DDX_Text(pDX, IDC_EDIT_AGE, m_age);
}

BEGIN_MESSAGE_MAP(CMFCSerializationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_OPEN, &CMFCSerializationDlg::OnBnClickedButtonOpen)
    ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCSerializationDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CMFCSerializationDlg message handlers

BOOL CMFCSerializationDlg::OnInitDialog()
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

void CMFCSerializationDlg::OnPaint()
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
HCURSOR CMFCSerializationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSerializationDlg::OnBnClickedButtonOpen()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    CFile file;

    file.Open(L"C:\\Temp\\EmployeeInfo.hse", CFile::modeRead);
    CArchive ar(&file, CArchive::load);
    CEmployee emplyee;

    emplyee.Serialize(ar);

    m_id = emplyee.empID;
    m_strName = emplyee.empName;
    m_age = emplyee.age;
    file.Close();

    UpdateData(FALSE);
}


void CMFCSerializationDlg::OnBnClickedButtonSave()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    CEmployee employee;
    CFile file;
    file.Open(L"C:\\Temp\\EmployeeInfo.hse", CFile::modeCreate | CFile::modeWrite);
    CArchive ar(&file, CArchive::store);
    employee.empID = m_id;
    employee.empName = m_strName;
    employee.age = m_age;
    employee.Serialize(ar);
    ar.Close();
}
