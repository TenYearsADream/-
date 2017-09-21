
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "ChangePwdDlg.h" //�޸�����Ի���
#include "DelUserDlg.h" //ɾ���û��Ի���
#include "SeekMTypeDlg.h" //�������Ͳ��ҶԻ���

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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));


		 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  �ڴ����ר�ô����/����û���

	//��this����ϲ��1��2��
	m_sWnd.CreateStatic(this, 1, 2);

	//������ͼ
	m_sWnd.CreateView(0, 0, RUNTIME_CLASS(CUserTreeView),
		CSize(230, 600), pContext);

	m_sWnd.CreateView(0, 1, RUNTIME_CLASS(CMedicListView),
		CSize(720, 600), pContext);



	//��Ĭ�ϴ����ͻ�������ͼ������
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

//�˵����£��Զ����ã�ֻ�й���Ա��������û���Ȩ��
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������

	//��ȡ�û�����ָ��
	SetMyEnable(pCmdUI, 1);
}

//�Զ���˵�����
void CMainFrame::SetMyEnable(CCmdUI *pCmdUI, int flag)
{
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();

	if (1 == flag)
	{
		if (pUser->GetType() == TEXT("����Ա"))
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
		if (pUser->GetType() == TEXT("��ҩԱ"))
		{
			pCmdUI->Enable(TRUE);
		}
		else
		{
			pCmdUI->Enable(FALSE);
		}
	}


}

//�޸�����
void CMainFrame::OnChangePwd()
{
	// TODO:  �ڴ���������������
	//�����Ի���
	CChangePwdDlg dlg;
	dlg.DoModal();

}

//����û�
void CMainFrame::OnAddUser()
{
	// TODO:  �ڴ���������������
}


//�˵����£�ֻ�й���Ա����ɾ���û�
void CMainFrame::OnUpdateDeleteUser(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������

	SetMyEnable(pCmdUI);
}

//�˵����£�ֻ�й���Ա����Ȩ�޲�ѯ�û�
void CMainFrame::OnUpdateSearchUser(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������

	SetMyEnable(pCmdUI);
}

//ɾ���û�
void CMainFrame::OnDeleteUser()
{
	// TODO:  �ڴ���������������
	CDelUserDlg dlg;
	dlg.DoModal();

}

//��ҩƷ����ѯ
void CMainFrame::OnByType()
{
	// TODO:  �ڴ���������������
	CSeekMTypeDlg dlg;
	dlg.DoModal();
}
