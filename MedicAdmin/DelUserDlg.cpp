// DelUserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "DelUserDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"	//框架
#include "MedicAdminDoc.h" //文档
#include "UserTreeView.h" //树视图头文件


// CDelUserDlg 对话框

IMPLEMENT_DYNAMIC(CDelUserDlg, CDialogEx)

CDelUserDlg::CDelUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDelUserDlg::IDD, pParent)
	, m_uiAccount(_T(""))
{

}

CDelUserDlg::~CDelUserDlg()
{
}

void CDelUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiCombo);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Control(pDX, IDC_LIST1, m_uiListCtrl);
}


BEGIN_MESSAGE_MAP(CDelUserDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelUserDlg::OnCbnSelchangeCombo1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDelUserDlg::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelUserDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDelUserDlg 消息处理程序

//删除用户对话框初始化
BOOL CDelUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//组合框显示 所有成员
	m_uiCombo.SetCurSel(3);

	//设置风格，表格，选中全行
	m_uiListCtrl.SetExtendedStyle(m_uiListCtrl.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//设置表头
	CString head[] = {
		TEXT("用户类别"), TEXT("用户账号"), TEXT("用户姓名"), TEXT("用户密码")
	};
	int n = sizeof(head) / sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		m_uiListCtrl.InsertColumn(i, head[i], LVCFMT_CENTER, 75);
	}

	//插入数据库内容（类别）

	//获取当前选中内容
	int index = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(index, type);


	//type不能为空
	if (type.IsEmpty())
	{
		MessageBox(TEXT("类别不能为空"));
		return TRUE;
	}

	UpdateListCtrl(type); //更新列表


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

//更新列表控件
void CDelUserDlg::UpdateListCtrl(CString type)
{
	//根据类别过滤
	//获取框架类对象指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//通过框架获取文档
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//取出用户数据库记录集指针
	CUserSet *pUserSet = (CUserSet *)pDoc->GetUserSet();



	if (type == TEXT("所有成员"))
	{
		pUserSet->m_strFilter = TEXT("");
	}
	else
	{
		//格式化过滤条件
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type);
		pUserSet->m_strFilter = sql;
	}

	//查询
	pUserSet->Requery();

	if (pUserSet->GetRecordCount() == 0)
	{
		MessageBox(TEXT("没有此类别的用户"));
		return;
	}

	//清空
	m_uiListCtrl.DeleteAllItems();

	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{

		/*
		TEXT("用户类别"), TEXT("用户账号"), TEXT("用户姓名"), TEXT("用户密码")
		*/
		CString str;
		int j = 1;

		m_uiListCtrl.InsertItem(i, pUserSet->m_classification);


		m_uiListCtrl.SetItemText(i, j++, pUserSet->m_account);
		m_uiListCtrl.SetItemText(i, j++, pUserSet->m_name);
		m_uiListCtrl.SetItemText(i, j++, pUserSet->m_password);

		//记录集移动
		pUserSet->MoveNext();
	}

}

//点击下拉框内容，自动调用
void CDelUserDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	//获取当前选中内容
	int index = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(index, type);


	//type不能为空
	if (type.IsEmpty())
	{
		MessageBox(TEXT("类别不能为空"));
	}

	UpdateListCtrl(type); //更新列表
}

//点击列表时，触发
void CDelUserDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;

	//转换类型，类别视图
	NM_LISTVIEW *pList = (NM_LISTVIEW *)pNMHDR;

	//账号的行和列
	int i = pList->iItem;
	int j = 1;

	//获取列表第i行第j列的内容
	CString str = m_uiListCtrl.GetItemText(i, j);

	m_uiAccount = str;

	UpdateData(FALSE);
	
}

//删除功能
void CDelUserDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	//获取当前账号
	UpdateData(TRUE);

	//内容不能为空
	if (m_uiAccount.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}

	//获取框架
	//获取文件
	//获取数据库记录集指针
	//获取用户

	//获取框架类对象指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//通过框架获取文档
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//获取数据库记录集指针
	CUserSet *pUserSet = pDoc->GetUserSet();

	//获取当前用户信息
	CUser *pUser = pDoc->GetUser();

	//删除用户
	int ret = pUser->DelUser(m_uiAccount);
	if (ret != 0) //失败
	{
		MessageBox(TEXT("删除用户失败"));
		return;

	}

	//更新当前类别
	OnCbnSelchangeCombo1(); //下拉框点击处理函数

	//更新树视图
	//找到树视图，通过文档找视图，链表的管理
	CUserTreeView *treeView = NULL;

	POSITION pos = pDoc->GetFirstViewPosition(); //获取第一个视图位置
	while (pos != NULL)
	{
		//根据位置获取当前视图，pos位置同时往下移动
		CView *view = pDoc->GetNextView(pos);

		//如果视图是CUserTreeView类型的视图
		if (view->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
		{
			treeView = (CUserTreeView *)view; //类型转换
			break;
		}

	}

	//更新
	if (treeView == NULL)
	{
		return;
	}

	//获取视图中的树控件
	CTreeCtrl& treeCtrl = treeView->GetTreeCtrl();

	//清空
	treeCtrl.DeleteAllItems();

	pUserSet->m_strFilter = TEXT(""); //重新查询

	//查询
	pUserSet->Requery();

	CString type[] = { TEXT("管理员"), TEXT("医生"), TEXT("售药员") };

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
