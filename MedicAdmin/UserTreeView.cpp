// UserTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserTreeView.h"
#include "MedicAdminDoc.h"
#include "LoginDlg.h"


// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView 诊断

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView 消息处理程序

//树视图初始化
void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	//创建图像列表
	//CImageList imageList;

	//创建CImageList
	imageList.Create(30, 30, ILC_COLOR32, 4, 4);
	
	//创建4个bitmap
	CBitmap bitmap[4];
	bitmap[0].LoadBitmapW(IDB_BITMAP_NOR);
	bitmap[1].LoadBitmapW(IDB_BITMAP_MAN);
	bitmap[2].LoadBitmapW(IDB_BITMAP_DOC);
	bitmap[3].LoadBitmapW(IDB_BITMAP_SAL);

	//图像列表添加图标
	for (int i = 0; i < 4; i++)
	{
		imageList.Add(&bitmap[i], RGB(0, 0, 0));
	}

	//获取视图中的树控件
	CTreeCtrl& treeCtrl = this->GetTreeCtrl();

	//树控件设置图像列表
	treeCtrl.SetImageList(&imageList, TVSIL_NORMAL);


	//treeCtrl.InsertItem(TEXT("测试"), 0, 0, NULL);

	//获取文档对象指针
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetDocument();

	//获取数据库记录集指针
	CUserSet *pUserSet = pDoc->GetUserSet();

	//打开数据库
	if (pUserSet->IsOpen() == FALSE)
	{
		pUserSet->Open();
	}

	//数据库打开后，弹出登陆对话框
	CLoginDlg dlg;
	dlg.DoModal();

	pUserSet->m_strFilter = TEXT("");

	//查询
	pUserSet->Requery();

	//根据数据库内容创建节点
	//插入根节点， 3 个

	CString type[] = { TEXT("管理员"), TEXT("医生"), TEXT("售药员") };

	//获取当前用户信息
	CUser *pUser = pDoc->GetUser();

	HTREEITEM cur = NULL;

	for (int i = 0; i < 3; i++)
	{
		HTREEITEM root = treeCtrl.InsertItem(type[i], 0, 0, NULL);


		CString sql;
		sql.Format(TEXT("classification = '%s'"), type[i]);
		pUserSet->m_strFilter = sql;

		pUserSet->Requery();

		for (int j = 0; j < pUserSet->GetRecordCount(); j++)
		{
			if (pUser->GetAccount() == pUserSet->m_account)
			{ //如果是当前用户
				CString str;
				str.Format(TEXT("%s[登陆用户]"), pUserSet->m_account);

				cur = treeCtrl.InsertItem(str, i + 1, i + 1, root);

			}
			else
			{
				treeCtrl.InsertItem(pUserSet->m_account, i + 1, i + 1, root);
			}
			
			

			pUserSet->MoveNext();
		}
	}

	if (cur != NULL)
	{
		treeCtrl.SelectItem(cur);
	}


}
