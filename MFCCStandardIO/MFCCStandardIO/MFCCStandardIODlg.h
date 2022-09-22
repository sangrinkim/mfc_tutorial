
// MFCCStandardIODlg.h : header file
//

#pragma once


// CMFCCStandardIODlg dialog
class CMFCCStandardIODlg : public CDialogEx
{
// Construction
public:
	CMFCCStandardIODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCCSTANDARDIO_DIALOG };

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
    CString m_strEditCtrol;
    afx_msg void OnBnClickedButtonOpen();
    afx_msg void OnBnClickedButtonSave();
};
