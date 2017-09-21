// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "MedicAdminDoc.h"
#include "MainFrm.h"
#include "User.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_uiAccout(_T(""))
	, m_uiPwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiCombo);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccout);
	DDX_Text(pDX, IDC_EDIT2, m_uiPwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

//敲回车键，对话框不退出
void CLoginDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

//关闭
void CLoginDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	exit(1);

	CDialogEx::OnClose();
}

//退出按钮
void CLoginDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码

	OnClose();
}

//对话框初始化
BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//设置组合框显示第0个
	m_uiCombo.SetCurSel(0);

	//用户名和密码
	m_uiAccout = TEXT("cat");
	m_uiPwd = TEXT("cat");

	//更新到对应的编辑区
	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

//登陆按钮
void CLoginDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	//先获取框架对象指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//通过取框架对象指针获取文档对象指针
	CMedicAdminDoc *pDc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//获取用户数据库记录集指针
	CUserSet *pUserSet = pDc->GetUserSet();

	//类别，账号，密码

	//获取编辑区内容
	UpdateData(TRUE);

	//获取类别
	int index = m_uiCombo.GetCurSel(); //当前选中第几项
	CString type;
	m_uiCombo.GetLBText(index, type);

	if (type.IsEmpty() || m_uiAccout.IsEmpty() || m_uiPwd.IsEmpty())
	{
		MessageBox(TEXT("输入信息不能为空"));
		return;
	}

	//CUser user;
	//通过文档类获取用户指针
	CUser *pUser = pDc->GetUser();

	pUser->SetAllMember(m_uiAccout, m_uiPwd, type);
	pUser->SetUserSet(pUserSet);

	int ret = pUser->Login();
	if (ret == 0) //登陆成功
	{
		CDialogEx::OnOK();
	}
	else if (ret == -2)
	{
		MessageBox(TEXT("登陆失败，账号或密码不正确"));
	}





#if 0
	//过滤条件
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_uiAccout, m_uiPwd, type);

	//MessageBox(sql);

	//设置过滤条件
	pUserSet->m_strFilter = sql;

	//重新查询
	pUserSet->Requery();

	if (pUserSet->GetRecordCount() == 0)
	{
		MessageBox(TEXT("登陆失败，账号或密码不正确"));
	}
	else //登陆成功
	{
		CDialogEx::OnOK();
	}
#endif




}
