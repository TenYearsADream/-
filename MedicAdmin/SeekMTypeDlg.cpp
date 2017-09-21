// SeekMTypeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SeekMTypeDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "MedicAdminDoc.h"
#include "MedicListView.h"


// CSeekMTypeDlg �Ի���

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


// CSeekMTypeDlg ��Ϣ�������

//��������ѯҩƷ��ʼ��
BOOL CSeekMTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��������ʾ����
	m_uiCombo.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//ѡ���������Զ�����
void CSeekMTypeDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ȡ��ǰѡ������
	int index = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(index, type);

	if (type.IsEmpty())
	{
		MessageBox(TEXT("���ݲ���Ϊ��"));
		return;
	}

	//��ȡ��������ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//ͨ����ܻ�ȡ�ĵ�
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//��ȡ�б���ͼ��������ݿ����
// 	CMedicSeache s;
// 	s.SearchByType(type);

	CMedicSearch *pM = pDoc->GetMedicS();

	//����, �ؼ�ָ�룬���ݿ�ָ��
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	pM->SetMedicSet(pMedicSet); //�������ݿ�ָ��

	//�Ȼ�ȡ�б���ͼ

	//�ҵ���ͼ��ͨ���ĵ�����ͼ������Ĺ���
	CMedicListView *listView = NULL;

	POSITION pos = pDoc->GetFirstViewPosition(); //��ȡ��һ����ͼλ��
	while (pos != NULL)
	{
		//����λ�û�ȡ��ǰ��ͼ��posλ��ͬʱ�����ƶ�
		CView *view = pDoc->GetNextView(pos);

		//�����ͼ��CUserTreeView���͵���ͼ
		if (view->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			listView = (CMedicListView *)view; //����ת��
			break;
		}

	}

	if (listView == NULL)
	{
		return;
	}

	///����
	CListCtrl *pList = &listView->GetListCtrl();


	pM->SetListCtrl(pList); //���ÿؼ�ָ��

	pM->SearchByType(type);

}
