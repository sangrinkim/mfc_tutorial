#pragma once


// CPropPage1 dialog

class CPropPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropPage1)

public:
	CPropPage1();
	virtual ~CPropPage1();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
