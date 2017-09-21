// SeekMTypeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SeekMTypeDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "MedicAdminDoc.h"
#include "MedicListView.h"


// CSeekMTypeDlg 对话框

IMPLEMENT_DYNAMIC(CSeekMTypeDlg, CDialogEx)

CSeekMTypeDlg::CSeekMTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSeekMTypeDlg::IDD, pParent)
{

}

CSeekMTypeDlg::~CSeekMTypeDlg()
{
}

void CSeekMTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiCombo);
}


BEGIN_MESSAGE_MAP(CSeekMTypeDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSeekMTypeDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSeekMTypeDlg 消息处理程序

//根据类别查询药品初始化
BOOL CSeekMTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//下拉框显示所有
	m_uiCombo.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

//选择下拉框自动调用
void CSeekMTypeDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	//获取当前选中内容
	int index = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(index, type);

	if (type.IsEmpty())
	{
		MessageBox(TEXT("内容不能为空"));
		return;
	}

	//获取框架类对象指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//通过框架获取文档
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//获取列表视图，结合数据库更新
// 	CMedicSeache s;
// 	s.SearchByType(type);

	CMedicSearch *pM = pDoc->GetMedicS();

	//设置, 控件指针，数据库指针
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	pM->SetMedicSet(pMedicSet); //设置数据库指针

	//先获取列表视图

	//找到视图，通过文档找视图，链表的管理
	CMedicListView *listView = NULL;

	POSITION pos = pDoc->GetFirstViewPosition(); //获取第一个视图位置
	while (pos != NULL)
	{
		//根据位置获取当前视图，pos位置同时往下移动
		CView *view = pDoc->GetNextView(pos);

		//如果视图是CUserTreeView类型的视图
		if (view->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			listView = (CMedicListView *)view; //类型转换
			break;
		}

	}

	if (listView == NULL)
	{
		return;
	}

	///设置
	CListCtrl *pList = &listView->GetListCtrl();


	pM->SetListCtrl(pList); //设置控件指针

	pM->SearchByType(type);

}
