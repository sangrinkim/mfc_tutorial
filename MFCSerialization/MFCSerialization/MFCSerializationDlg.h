
// MFCSerializationDlg.h : header file
//

#pragma once


// CMFCSerializationDlg dialog
class CMFCSerializationDlg : public CDialogEx
{
// Construction
public:
	CMFCSerializationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCSERIALIZATION_DIALOG };

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
    int m_id;
    afx_msg void OnBnClickedButtonOpen();
    afx_msg void OnBnClickedButtonSave();
    CString m_strName;
    int m_age;
};
