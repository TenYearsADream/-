// UserTreeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserTreeView.h"
#include "MedicAdminDoc.h"
#include "LoginDlg.h"


// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView ���

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView ��Ϣ�������

//����ͼ��ʼ��
void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	//����ͼ���б�
	//CImageList imageList;

	//����CImageList
	imageList.Create(30, 30, ILC_COLOR32, 4, 4);
	
	//����4��bitmap
	CBitmap bitmap[4];
	bitmap[0].LoadBitmapW(IDB_BITMAP_NOR);
	bitmap[1].LoadBitmapW(IDB_BITMAP_MAN);
	bitmap[2].LoadBitmapW(IDB_BITMAP_DOC);
	bitmap[3].LoadBitmapW(IDB_BITMAP_SAL);

	//ͼ���б����ͼ��
	for (int i = 0; i < 4; i++)
	{
		imageList.Add(&bitmap[i], RGB(0, 0, 0));
	}

	//��ȡ��ͼ�е����ؼ�
	CTreeCtrl& treeCtrl = this->GetTreeCtrl();

	//���ؼ�����ͼ���б�
	treeCtrl.SetImageList(&imageList, TVSIL_NORMAL);


	//treeCtrl.InsertItem(TEXT("����"), 0, 0, NULL);

	//��ȡ�ĵ�����ָ��
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetDocument();

	//��ȡ���ݿ��¼��ָ��
	CUserSet *pUserSet = pDoc->GetUserSet();

	//�����ݿ�
	if (pUserSet->IsOpen() == FALSE)
	{
		pUserSet->Open();
	}

	//���ݿ�򿪺󣬵�����½�Ի���
	CLoginDlg dlg;
	dlg.DoModal();

	pUserSet->m_strFilter = TEXT("");

	//��ѯ
	pUserSet->Requery();

	//�������ݿ����ݴ����ڵ�
	//������ڵ㣬 3 ��

	CString type[] = { TEXT("����Ա"), TEXT("ҽ��"), TEXT("��ҩԱ") };

	//��ȡ��ǰ�û���Ϣ
	CUser *pUser = pDoc->GetUser();

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
