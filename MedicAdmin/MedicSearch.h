#pragma once
//数据库指针
#include "MedicSet.h" //药品数据库

class CMedicSearch
{
public:
	CMedicSearch();
	virtual ~CMedicSearch();

	//设置药品数据库指针
	void SetMedicSet(CMedicSet *pSet);

	//设置列表控件指针
	void SetListCtrl(CListCtrl *listCtrl);

	//更加类别查询药品信息，成功为0，失败非0
	int SearchByType(CString type = TEXT("所有类别"));

private:
	CMedicSet *m_pMedicSet; //药品数据库指针
	CListCtrl *m_listCtrl; //列表控件指针
};

