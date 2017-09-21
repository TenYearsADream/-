
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "ChangePwdDlg.h" //修改密码对话框
#include "DelUserDlg.h" //删除用户对话框
#include "SeekMTypeDlg.h" //根据类型查找对话框

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_ADD_USER, &CMainFrame::OnUpdateAddUser)
	ON_COMMAND(ID_CHANGE_PWD, &CMainFrame::OnChangePwd)
	ON_COMMAND(ID_ADD_USER, &CMainFrame::OnAddUser)
	ON_UPDATE_COMMAND_UI(ID_DELETE_USER, &CMainFrame::OnUpdateDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_SEARCH_USER, &CMainFrame::OnUpdateSearchUser)
	ON_COMMAND(ID_DELETE_USER, &CMainFrame::OnDeleteUser)
	ON_COMMAND(ID_BY_TYPE, &CMainFrame::OnByType)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));


		 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  在此添加专用代码和/或调用基类

	//在this框架上拆分1行2列
	m_sWnd.CreateStatic(this, 1, 2);

	//创建视图
	m_sWnd.CreateView(0, 0, RUNTIME_CLASS(CUserTreeView),
		CSize(230, 600), pContext);

	m_sWnd.CreateView(0, 1, RUNTIME_CLASS(CMedicListView),
		CSize(720, 600), pContext);



	//把默认创建客户区（视图）屏蔽
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

//菜单更新，自动调用，只有管理员才有添加用户的权限
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码

	//获取用户对象指针
	SetMyEnable(pCmdUI, 1);
}

//自定义菜单更新
void CMainFrame::SetMyEnable(CCmdUI *pCmdUI, int flag)
{
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();

	if (1 == flag)
	{
		if (pUser->GetType() == TEXT("管理员"))
		{
			pCmdUI->Enable(TRUE);
		}
		else
		{
			pCmdUI->Enable(FALSE);
		}
	}
	else if (2 == flag)
	{
		if (pUser->GetType() == TEXT("售药员"))
		{
			pCmdUI->Enable(TRUE);
		}
		else
		{
			pCmdUI->Enable(FALSE);
		}
	}


}

//修改密码
void CMainFrame::OnChangePwd()
{
	// TODO:  在此添加命令处理程序代码
	//弹出对话框
	CChangePwdDlg dlg;
	dlg.DoModal();

}

//添加用户
void CMainFrame::OnAddUser()
{
	// TODO:  在此添加命令处理程序代码
}


//菜单更新，只有管理员才能删除用户
void CMainFrame::OnUpdateDeleteUser(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码

	SetMyEnable(pCmdUI);
}

//菜单更新，只有管理员才有权限查询用户
void CMainFrame::OnUpdateSearchUser(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码

	SetMyEnable(pCmdUI);
}

//删除用户
void CMainFrame::OnDeleteUser()
{
	// TODO:  在此添加命令处理程序代码
	CDelUserDlg dlg;
	dlg.DoModal();

}

//按药品类别查询
void CMainFrame::OnByType()
{
	// TODO:  在此添加命令处理程序代码
	CSeekMTypeDlg dlg;
	dlg.DoModal();
}
