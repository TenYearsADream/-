// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "MedicAdminDoc.h"
#include "MainFrm.h"
#include "User.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������

//�ûس������Ի����˳�
void CLoginDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}

//�ر�
void CLoginDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	exit(1);

	CDialogEx::OnClose();
}

//�˳���ť
void CLoginDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	OnClose();
}

//�Ի����ʼ��
BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	//������Ͽ���ʾ��0��
	m_uiCombo.SetCurSel(0);

	//�û���������
	m_uiAccout = TEXT("cat");
	m_uiPwd = TEXT("cat");

	//���µ���Ӧ�ı༭��
	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//��½��ť
void CLoginDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//�Ȼ�ȡ��ܶ���ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//ͨ��ȡ��ܶ���ָ���ȡ�ĵ�����ָ��
	CMedicAdminDoc *pDc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//��ȡ�û����ݿ��¼��ָ��
	CUserSet *pUserSet = pDc->GetUserSet();

	//����˺ţ�����

	//��ȡ�༭������
	UpdateData(TRUE);

	//��ȡ���
	int index = m_uiCombo.GetCurSel(); //��ǰѡ�еڼ���
	CString type;
	m_uiCombo.GetLBText(index, type);

	if (type.IsEmpty() || m_uiAccout.IsEmpty() || m_uiPwd.IsEmpty())
	{
		MessageBox(TEXT("������Ϣ����Ϊ��"));
		return;
	}

	//CUser user;
	//ͨ���ĵ����ȡ�û�ָ��
	CUser *pUser = pDc->GetUser();

	pUser->SetAllMember(m_uiAccout, m_uiPwd, type);
	pUser->SetUserSet(pUserSet);

	int ret = pUser->Login();
	if (ret == 0) //��½�ɹ�
	{
		CDialogEx::OnOK();
	}
	else if (ret == -2)
	{
		MessageBox(TEXT("��½ʧ�ܣ��˺Ż����벻��ȷ"));
	}





#if 0
	//��������
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_uiAccout, m_uiPwd, type);

	//MessageBox(sql);

	//���ù�������
	pUserSet->m_strFilter = sql;

	//���²�ѯ
	pUserSet->Requery();

	if (pUserSet->GetRecordCount() == 0)
	{
		MessageBox(TEXT("��½ʧ�ܣ��˺Ż����벻��ȷ"));
	}
	else //��½�ɹ�
	{
		CDialogEx::OnOK();
	}
#endif




}
