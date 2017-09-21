// MedicSet.h : CMedicSet ���ʵ��



// CMedicSet ʵ��

// ���������� 2016��3��20��, 11:33

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
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// CMedicSet ���

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


