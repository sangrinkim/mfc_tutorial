
// MFCFileProcessingDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCFileProcessingDlg dialog
class CMFCFileProcessingDlg : public CDialogEx
{
// Construction
public:
	CMFCFileProcessingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCFILEPROCESSING_DIALOG };

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
    CEdit m_editCtrl;
    CString m_strEdit;
    afx_msg void OnBnClickedButtonOpen();
    afx_msg void OnBnClickedButtonSave();
};
