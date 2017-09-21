// ChangePwdDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "ChangePwdDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h" //框架
#include "MedicAdminDoc.h" //文档


// CChangePwdDlg 对话框

IMPLEMENT_DYNAMIC(CChangePwdDlg, CDialogEx)

CChangePwdDlg::CChangePwdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangePwdDlg::IDD, pParent)
	, m_uiAccout(_T(""))
	, m_uiOldPwd(_T(""))
	, m_uiNewPwd(_T(""))
	, m_uiSurePwd(_T(""))
{

}

CChangePwdDlg::~CChangePwdDlg()
{
}

void CChangePwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccout);
	DDX_Text(pDX, IDC_EDIT2, m_uiOldPwd);
	//  DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT3, m_uiNewPwd);
	DDX_Text(pDX, IDC_EDIT4, m_uiSurePwd);
}


BEGIN_MESSAGE_MAP(CChangePwdDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CChangePwdDlg::OnBnClickedButton4)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, &CChangePwdDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CChangePwdDlg 消息处理程序

//敲回车键，对话框不退出
void CChangePwdDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

//修改密码对话框初始化
BOOL CChangePwdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//获取框架类对象指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//通过框架获取文档
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//获取当前用户信息
	CUser *pUser = pDoc->GetUser();

	m_uiAccout = pUser->GetAccount(); //用户信息赋值

	UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

//退出按钮
void CChangePwdDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码

	//关闭对话框
	CDialogEx::OnOK();
}

//关闭， 不写，默认也是关闭对话框
void CChangePwdDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnOK();
	CDialogEx::OnClose();
}

//确定修改密码按钮
void CChangePwdDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码

	//获取框架类对象指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//通过框架获取文档
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//获取当前用户信息
	CUser *pUser = pDoc->GetUser();

	//获取编辑区内容
	UpdateData(TRUE);

	int ret =0;// = pUser->ChangePwd(m_uiOldPwd, m_uiNewPwd, m_uiSurePwd);
	if (ret == 0)
	{
		MessageBox(TEXT("密码修改成功"));
	}
	else if (ret == -2)
	{
		MessageBox(TEXT("输入内容不能为空"));
	}
	else if (ret == -3)
	{
		MessageBox(TEXT("旧密码和新密码不能相同"));
	}
	else if (ret == -4)
	{
		MessageBox(TEXT("确定密码和新密码不一致"));
	}
	else if (ret == -5)
	{
		MessageBox(TEXT("没有此用户"));
	}
	else if (ret == -6)
	{
		MessageBox(TEXT("更新失败"));
	}
	else if (ret == -7)
	{
		MessageBox(TEXT("旧密码不正确"));
	}

}
