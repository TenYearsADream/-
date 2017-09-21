// ChangePwdDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "ChangePwdDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h" //���
#include "MedicAdminDoc.h" //�ĵ�


// CChangePwdDlg �Ի���

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


// CChangePwdDlg ��Ϣ�������

//�ûس������Ի����˳�
void CChangePwdDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}

//�޸�����Ի����ʼ��
BOOL CChangePwdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//��ȡ��������ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//ͨ����ܻ�ȡ�ĵ�
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//��ȡ��ǰ�û���Ϣ
	CUser *pUser = pDoc->GetUser();

	m_uiAccout = pUser->GetAccount(); //�û���Ϣ��ֵ

	UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//�˳���ť
void CChangePwdDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//�رնԻ���
	CDialogEx::OnOK();
}

//�رգ� ��д��Ĭ��Ҳ�ǹرնԻ���
void CChangePwdDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnOK();
	CDialogEx::OnClose();
}

//ȷ���޸����밴ť
void CChangePwdDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��������ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//ͨ����ܻ�ȡ�ĵ�
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)pFrame->GetActiveDocument();

	//��ȡ��ǰ�û���Ϣ
	CUser *pUser = pDoc->GetUser();

	//��ȡ�༭������
	UpdateData(TRUE);

	int ret =0;// = pUser->ChangePwd(m_uiOldPwd, m_uiNewPwd, m_uiSurePwd);
	if (ret == 0)
	{
		MessageBox(TEXT("�����޸ĳɹ�"));
	}
	else if (ret == -2)
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
	}
	else if (ret == -3)
	{
		MessageBox(TEXT("������������벻����ͬ"));
	}
	else if (ret == -4)
	{
		MessageBox(TEXT("ȷ������������벻һ��"));
	}
	else if (ret == -5)
	{
		MessageBox(TEXT("û�д��û�"));
	}
	else if (ret == -6)
	{
		MessageBox(TEXT("����ʧ��"));
	}
	else if (ret == -7)
	{
		MessageBox(TEXT("�����벻��ȷ"));
	}

}
