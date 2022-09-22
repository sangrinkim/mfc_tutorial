
// MFCMultithreadingDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCMultithreadingDlg dialog
class CMFCMultithreadingDlg : public CDialogEx
{
// Construction
public:
	CMFCMultithreadingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCMULTITHREADING_DIALOG };

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
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    CStatic m_ctrlStatus;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
