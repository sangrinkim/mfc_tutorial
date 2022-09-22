
// MFCDrivesDemoDlg.h : header file
//

#pragma once


// CMFCDrivesDemoDlg dialog
class CMFCDrivesDemoDlg : public CDialogEx
{
// Construction
public:
	CMFCDrivesDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDRIVESDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton2();
    CString m_strDrives;
};
