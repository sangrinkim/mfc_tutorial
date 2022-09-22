#pragma once

// CEmployee command target

class CEmployee : public CObject
{
    public:
        int empID;
        CString empName;
        int age;
	    CEmployee();
	    virtual ~CEmployee();

    public:
        void Serialize(CArchive& ar);
        DECLARE_SERIAL(CEmployee);
};


