#pragma once

#define WM_GOODBYE WM_USER + 5

// CModalessDlg dialog

class CModalessDlg : public CDialog
{
	DECLARE_DYNAMIC(CModalessDlg)
private:
    CView* m_pView;

public:
    CModalessDlg(CView* pView);
    BOOL Create();

	CModalessDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CModalessDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_MODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    CString m_Text;
};
