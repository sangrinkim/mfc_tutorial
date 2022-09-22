
// MFCStringDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCStringDemo.h"
#include "MFCStringDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCStringDemoDlg dialog



CMFCStringDemoDlg::CMFCStringDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCStringDemoDlg::IDD, pParent)
    , m_strText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStringDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STATIC_STR, m_strText);
}

BEGIN_MESSAGE_MAP(CMFCStringDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCStringDemoDlg message handlers

BOOL CMFCStringDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
    //CString string1 = _T("This is a string1");
    //CString string2("This is a string2");

    //CString string1 = _T("");
    //CString string2;
    //
    //if (string1.IsEmpty())
    //{
    //    m_strText.Append(L"String1 is empty\n");
    //}
    //else
    //{
    //    m_strText.Append(string1 + L"\n");
    //}

    //if (string2.IsEmpty())
    //{
    //    m_strText.Append(L"String2 is empty");
    //}
    //else
    //{
    //    m_strText.Append(string2);
    //}

    //CString s1 = _T("This ");
    //s1 += _T("is a ");
    //CString s2 = _T("test");
    //CString message = s1;
    //message.Append(_T("big ") + s2);

    //m_strText = L"message: " + message;

    //CString string1 = _T("This is string 1");
    //int length = string1.GetLength();
    //CString strLen;

    //strLen.Format(L"\nString1 contains %d characters", length);
    //m_strText = string1 + strLen;

    //CString string1 = _T("Hello");
    //CString string2 = _T("World");

    //CString string3 = _T("MFC Tutorial");
    //CString string4 = _T("MFC Tutorial");

    //if (string1 == string2)
    //{
    //    m_strText = "string and string1 are smae\n";
    //}
    //else
    //{
    //    m_strText = "string1 and string 1 are not same\n";
    //}

    //if (string3 == string4)
    //{
    //    m_strText += "string3 and string4 are same";
    //}
    //else
    //{
    //    m_strText += "string3 and string4 are not same";
    //}




    UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCStringDemoDlg::OnPaint()
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
HCURSOR CMFCStringDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

