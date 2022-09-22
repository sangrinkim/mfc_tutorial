
// MFCModalDemoDlg.h : header file
//

#pragma once


// CMFCModalDemoDlg dialog
class CMFCModalDemoDlg : public CDialogEx
{
// Construction
public:
	CMFCModalDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCMODALDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;
    CToolBar m_wndToolBar;
    BOOL butD;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnFileNew32771();
};
