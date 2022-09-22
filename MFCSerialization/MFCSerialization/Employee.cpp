// Employee.cpp : implementation file
//

#include "stdafx.h"
#include "MFCSerialization.h"
#include "Employee.h"


// CEmployee
IMPLEMENT_SERIAL(CEmployee, CObject, 0)
CEmployee::CEmployee()
{
}

CEmployee::~CEmployee()
{
}


// CEmployee member functions
void CEmployee::Serialize(CArchive& ar)
{
    CObject::Serialize(ar);

    if (ar.IsStoring())
    {
        ar << empID << empName << age;
    }
    else
    {
        ar >> empID >> empName >> age;
    }
}