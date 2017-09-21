// MedicSet.h : CMedicSet 类的实现



// CMedicSet 实现

// 代码生成在 2016年3月20日, 11:33

#include "stdafx.h"
#include "MedicSet.h"
IMPLEMENT_DYNAMIC(CMedicSet, CRecordset)

CMedicSet::CMedicSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = L"";
	m_name = L"";
	m_classification = L"";
	m_produceDate;
	m_producePlace = L"";
	m_discription = L"";
	m_produceCompany = L"";
	m_quelityAssurance = 0;
	m_unitPrice = 0;
	m_number = 0;
	m_nFields = 10;
	m_nDefaultType = snapshot;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMedicSet::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 5.3 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=521521;DATABASE=medicine;PORT=3306");
}

CString CMedicSet::GetDefaultSQL()
{
	return _T("[medicine]");
}

void CMedicSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[classification]"), m_classification);
	RFX_Date(pFX, _T("[produceDate]"), m_produceDate);
	RFX_Text(pFX, _T("[producePlace]"), m_producePlace);
	RFX_Text(pFX, _T("[discription]"), m_discription);
	RFX_Text(pFX, _T("[produceCompany]"), m_produceCompany);
	RFX_Long(pFX, _T("[quelityAssurance]"), m_quelityAssurance);
	RFX_Long(pFX, _T("[unitPrice]"), m_unitPrice);
	RFX_Long(pFX, _T("[number]"), m_number);

}
/////////////////////////////////////////////////////////////////////////////
// CMedicSet 诊断

#ifdef _DEBUG
void CMedicSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMedicSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


