
// MFCDirectoriesDemoDlg.h : header file
//

#pragma once


// CMFCDirectoriesDemoDlg dialog
class CMFCDirectoriesDemoDlg : public CDialogEx
{
// Construction
public:
	CMFCDirectoriesDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDIRECTORIESDEMO_DIALOG };

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
    afx_msg void OnBnClickedButtonCreate();
    afx_msg void OnBnClickedButtonDelete();
    afx_msg void OnBnClickedButtonMove();
};
