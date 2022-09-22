#pragma once


// PropPage2 dialog

class PropPage2 : public CPropertyPage
{
	DECLARE_DYNAMIC(PropPage2)

public:
	PropPage2();
	virtual ~PropPage2();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
