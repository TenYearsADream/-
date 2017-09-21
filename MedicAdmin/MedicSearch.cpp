#include "stdafx.h"
#include "MedicSearch.h"


CMedicSearch::CMedicSearch()
{
	m_pMedicSet = NULL;
	m_listCtrl = NULL;
}


CMedicSearch::~CMedicSearch()
{
}

void CMedicSearch::SetMedicSet(CMedicSet *pSet)
{
	m_pMedicSet = pSet;
}

void CMedicSearch::SetListCtrl(CListCtrl *listCtrl)
{
	m_listCtrl = listCtrl;
}

int CMedicSearch::SearchByType(CString type /*= TEXT("�������")*/)
{
	if (m_listCtrl == NULL || m_pMedicSet == NULL)
	{
		AfxMessageBox(TEXT("�б�ؼ�ָ������ݿ�ָ��û�г�ʼ��"));
		return -1;
	}

	if (type == TEXT("�������"))
	{
		m_pMedicSet->m_strFilter = TEXT("");
	}
	else
	{
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type);
		m_pMedicSet->m_strFilter = sql;
	}

	//��ѯ
	m_pMedicSet->Requery();

	if (m_pMedicSet->GetRecordCount() == 0)
	{
		AfxMessageBox(TEXT("û����Ӧ������"));
		return -2;
	}

	//�����б�

	//�����
	m_listCtrl->DeleteAllItems();

	for (int i = 0; i < m_pMedicSet->GetRecordCount(); i++)
	{

		/*
		TEXT("ҩƷ����"), TEXT("ҩƷ����"), TEXT("ҩƷ���"),
		TEXT("�����Ŀ"), TEXT("������˾"), TEXT("����"),
		TEXT("����ʱ��"), TEXT("������(��)"), TEXT("����(Ԫ)")
		*/
		CString str;
		int j = 1;

		//���ţ�ȷ����
		m_listCtrl->InsertItem(i, m_pMedicSet->m_id);

		//��ȷ����
		//ҩƷ����
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_name);

		//ҩƷ���
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_classification);

		//�����Ŀ
		str.Format(TEXT("%d"), m_pMedicSet->m_number);
		m_listCtrl->SetItemText(i, j++, str);

		//������˾
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_produceCompany);

		//����
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_producePlace);

		//ʱ��
		CTime time = m_pMedicSet->m_produceDate;
		str = time.Format(TEXT("%Y-%m-%d")); //2016-03-20;
		m_listCtrl->SetItemText(i, j++, str);

		//������(��)
		str.Format(TEXT("%d"), m_pMedicSet->m_quelityAssurance);
		m_listCtrl->SetItemText(i, j++, str);

		//���ۣ�����
		str.Format(TEXT("%d"), m_pMedicSet->m_unitPrice);
		m_listCtrl->SetItemText(i, j++, str);

		//��¼���ƶ�
		m_pMedicSet->MoveNext();
	}

	return 0;

}
