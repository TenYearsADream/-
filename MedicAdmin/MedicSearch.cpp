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

int CMedicSearch::SearchByType(CString type /*= TEXT("所有类别")*/)
{
	if (m_listCtrl == NULL || m_pMedicSet == NULL)
	{
		AfxMessageBox(TEXT("列表控件指针或数据库指针没有初始化"));
		return -1;
	}

	if (type == TEXT("所有类别"))
	{
		m_pMedicSet->m_strFilter = TEXT("");
	}
	else
	{
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type);
		m_pMedicSet->m_strFilter = sql;
	}

	//查询
	m_pMedicSet->Requery();

	if (m_pMedicSet->GetRecordCount() == 0)
	{
		AfxMessageBox(TEXT("没有相应的数据"));
		return -2;
	}

	//更新列表

	//先清空
	m_listCtrl->DeleteAllItems();

	for (int i = 0; i < m_pMedicSet->GetRecordCount(); i++)
	{

		/*
		TEXT("药品代号"), TEXT("药品名称"), TEXT("药品类别"),
		TEXT("库存数目"), TEXT("出厂公司"), TEXT("产地"),
		TEXT("出厂时间"), TEXT("保质期(月)"), TEXT("单价(元)")
		*/
		CString str;
		int j = 1;

		//代号，确定行
		m_listCtrl->InsertItem(i, m_pMedicSet->m_id);

		//再确定列
		//药品名称
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_name);

		//药品类别
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_classification);

		//库存数目
		str.Format(TEXT("%d"), m_pMedicSet->m_number);
		m_listCtrl->SetItemText(i, j++, str);

		//出厂公司
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_produceCompany);

		//产地
		m_listCtrl->SetItemText(i, j++, m_pMedicSet->m_producePlace);

		//时间
		CTime time = m_pMedicSet->m_produceDate;
		str = time.Format(TEXT("%Y-%m-%d")); //2016-03-20;
		m_listCtrl->SetItemText(i, j++, str);

		//保质期(月)
		str.Format(TEXT("%d"), m_pMedicSet->m_quelityAssurance);
		m_listCtrl->SetItemText(i, j++, str);

		//单价，整型
		str.Format(TEXT("%d"), m_pMedicSet->m_unitPrice);
		m_listCtrl->SetItemText(i, j++, str);

		//记录集移动
		m_pMedicSet->MoveNext();
	}

	return 0;

}
