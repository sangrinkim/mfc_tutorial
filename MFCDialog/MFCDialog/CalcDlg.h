#pragma once


// CCalcDlg dialog

class CCalcDlg : public CDialog
{
	DECLARE_DYNAMIC(CCalcDlg)

public:
	CCalcDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCalcDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    UINT m_Num1;
    UINT m_Num2;
    UINT m_Result;
    afx_msg void OnClickedButtonAdd();
    afx_msg void OnClickedButtonSubtract();
    afx_msg void OnClickedButtonMultiply();
    afx_msg void OnClickedButtonDivide();
    afx_msg void OnClickedButtonOk();
};
