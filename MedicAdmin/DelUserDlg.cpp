// DelUserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "DelUserDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"	//���
#include "MedicAdminDoc.h" //�ĵ�
#include "UserTreeView.h" //����ͼͷ�ļ�


// CDelUserDlg �Ի���

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


// CDelUserDlg ��Ϣ�������

//ɾ���û��Ի����ʼ��
BOOL CDelUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��Ͽ���ʾ ���г�Ա
	m_uiCombo.SetCurSel(3);

	//���÷�񣬱��ѡ��ȫ��
	m_uiListCtrl.SetExtendedStyle(m_uiListCtrl.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//���ñ�ͷ
	CString head[] = {
		TEXT("�û����"), TEXT("�û��˺�"), TEXT("�û�����"), TEXT("�û�����")
	};
	int n = sizeof(head) / sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		m_uiListCtrl.InsertColumn(i, head[i], LVCFMT_CENTER, 75);
	}

	//�������ݿ����ݣ����

	//��ȡ��ǰѡ������
	int index = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(index, type);


	//type����Ϊ��
	if (type.IsEmpty())
	{
		MessageBox(TEXT("�����Ϊ��"));
		return TRUE;
	}

	UpdateListCtrl(type); //�����б�


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//�����б�ؼ�
void CDelUserDlg::UpdateListCtrl(CString type)
{
	//����������
	//��ȡ��������ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//ͨ����ܻ�ȡ�ĵ�
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//ȡ���û����ݿ��¼��ָ��
	CUserSet *pUserSet = (CUserSet *)pDoc->GetUserSet();



	if (type == TEXT("���г�Ա"))
	{
		pUserSet->m_strFilter = TEXT("");
	}
	else
	{
		//��ʽ����������
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type);
		pUserSet->m_strFilter = sql;
	}

	//��ѯ
	pUserSet->Requery();

	if (pUserSet->GetRecordCount() == 0)
	{
		MessageBox(TEXT("û�д������û�"));
		return;
	}

	//���
	m_uiListCtrl.DeleteAllItems();

	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{

		/*
		TEXT("�û����"), TEXT("�û��˺�"), TEXT("�û�����"), TEXT("�û�����")
		*/
		CString str;
		int j = 1;

		m_uiListCtrl.InsertItem(i, pUserSet->m_classification);


		m_uiListCtrl.SetItemText(i, j++, pUserSet->m_account);
		m_uiListCtrl.SetItemText(i, j++, pUserSet->m_name);
		m_uiListCtrl.SetItemText(i, j++, pUserSet->m_password);

		//��¼���ƶ�
		pUserSet->MoveNext();
	}

}

//������������ݣ��Զ�����
void CDelUserDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ȡ��ǰѡ������
	int index = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(index, type);


	//type����Ϊ��
	if (type.IsEmpty())
	{
		MessageBox(TEXT("�����Ϊ��"));
	}

	UpdateListCtrl(type); //�����б�
}

//����б�ʱ������
void CDelUserDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//ת�����ͣ������ͼ
	NM_LISTVIEW *pList = (NM_LISTVIEW *)pNMHDR;

	//�˺ŵ��к���
	int i = pList->iItem;
	int j = 1;

	//��ȡ�б��i�е�j�е�����
	CString str = m_uiListCtrl.GetItemText(i, j);

	m_uiAccount = str;

	UpdateData(FALSE);
	
}

//ɾ������
void CDelUserDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��ǰ�˺�
	UpdateData(TRUE);

	//���ݲ���Ϊ��
	if (m_uiAccount.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}

	//��ȡ���
	//��ȡ�ļ�
	//��ȡ���ݿ��¼��ָ��
	//��ȡ�û�

	//��ȡ��������ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//ͨ����ܻ�ȡ�ĵ�
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//��ȡ���ݿ��¼��ָ��
	CUserSet *pUserSet = pDoc->GetUserSet();

	//��ȡ��ǰ�û���Ϣ
	CUser *pUser = pDoc->GetUser();

	//ɾ���û�
	int ret = pUser->DelUser(m_uiAccount);
	if (ret != 0) //ʧ��
	{
		MessageBox(TEXT("ɾ���û�ʧ��"));
		return;

	}

	//���µ�ǰ���
	OnCbnSelchangeCombo1(); //��������������

	//��������ͼ
	//�ҵ�����ͼ��ͨ���ĵ�����ͼ������Ĺ���
	CUserTreeView *treeView = NULL;

	POSITION pos = pDoc->GetFirstViewPosition(); //��ȡ��һ����ͼλ��
	while (pos != NULL)
	{
		//����λ�û�ȡ��ǰ��ͼ��posλ��ͬʱ�����ƶ�
		CView *view = pDoc->GetNextView(pos);

		//�����ͼ��CUserTreeView���͵���ͼ
		if (view->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
		{
			treeView = (CUserTreeView *)view; //����ת��
			break;
		}

	}

	//����
	if (treeView == NULL)
	{
		return;
	}

	//��ȡ��ͼ�е����ؼ�
	CTreeCtrl& treeCtrl = treeView->GetTreeCtrl();

	//���
	treeCtrl.DeleteAllItems();

	pUserSet->m_strFilter = TEXT(""); //���²�ѯ

	//��ѯ
	pUserSet->Requery();

	CString type[] = { TEXT("����Ա"), TEXT("ҽ��"), TEXT("��ҩԱ") };

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
			{ //����ǵ�ǰ�û�
				CString str;
				str.Format(TEXT("%s[��½�û�]"), pUserSet->m_account);

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
