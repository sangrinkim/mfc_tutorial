#pragma once


// CDialogTest dialog

class CDialogTest : public CDialog
{
	DECLARE_DYNAMIC(CDialogTest)

public:
	CDialogTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogTest();

// Dialog Data
	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    CString m_strDlg;
};
