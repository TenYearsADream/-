// MedicListView.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "MedicListView.h"
#include "MedicAdminDoc.h"


// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView 诊断

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView 消息处理程序

//列表视图初始化
void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	//获取列表视图中的列表控件
	CListCtrl &listCtrl = this->GetListCtrl();

	//设置风格，表格，选中全行
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//设置模型：报表
	listCtrl.ModifyStyle(0, LVS_REPORT);

	//设置表头
	CString head[] ={
		TEXT("药品代号"), TEXT("药品名称"), TEXT("药品类别"),
		TEXT("库存数目"), TEXT("出厂公司"), TEXT("产地"),
		TEXT("出厂时间"), TEXT("保质期(月)"), TEXT("单价(元)")
	};
	int n = sizeof(head) / sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		listCtrl.InsertColumn(i, head[i], LVCFMT_CENTER, 90);
	}

	//获取文档类对象指针
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetDocument();

	//获取数据库记录集指针
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	//打开数据库
	if (pMedicSet->IsOpen() == FALSE)
	{
		pMedicSet->Open();
	}

	//查询
	pMedicSet->Requery();


	//设置数据库内容
	//先设置行，在设置列
// 	listCtrl.InsertItem();
// 	listCtrl.SetItemText();

	//pMedicSet->GetRecordCount(): 记录集总行数（除了表头）
	for (int i = 0; i < pMedicSet->GetRecordCount(); i++)
	{

		/*
			TEXT("药品代号"), TEXT("药品名称"), TEXT("药品类别"),
			TEXT("库存数目"), TEXT("出厂公司"), TEXT("产地"),
			TEXT("出厂时间"), TEXT("保质期(月)"), TEXT("单价(元)")
		*/
		CString str;
		int j = 1;

		//代号，确定行
		listCtrl.InsertItem(i, pMedicSet->m_id);

		//再确定列
		//药品名称
		listCtrl.SetItemText(i, j++, pMedicSet->m_name);

		//药品类别
		listCtrl.SetItemText(i, j++, pMedicSet->m_classification);

		//库存数目
		str.Format(TEXT("%d"), pMedicSet->m_number);
		listCtrl.SetItemText(i, j++, str);

		//出厂公司
		listCtrl.SetItemText(i, j++, pMedicSet->m_produceCompany);

		//产地
		listCtrl.SetItemText(i, j++, pMedicSet->m_producePlace);

		//时间
		CTime time = pMedicSet->m_produceDate;
		str = time.Format(TEXT("%Y-%m-%d")); //2016-03-20;
		listCtrl.SetItemText(i, j++, str);

		//保质期(月)
		str.Format(TEXT("%d"), pMedicSet->m_quelityAssurance);
		listCtrl.SetItemText(i, j++, str);

		//单价，整型
		str.Format(TEXT("%d"), pMedicSet->m_unitPrice);
		listCtrl.SetItemText(i, j++, str);

		//记录集移动
		pMedicSet->MoveNext();
	}

}
