// MedicListView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "MedicListView.h"
#include "MedicAdminDoc.h"


// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView ���

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView ��Ϣ�������

//�б���ͼ��ʼ��
void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	//��ȡ�б���ͼ�е��б�ؼ�
	CListCtrl &listCtrl = this->GetListCtrl();

	//���÷�񣬱��ѡ��ȫ��
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//����ģ�ͣ�����
	listCtrl.ModifyStyle(0, LVS_REPORT);

	//���ñ�ͷ
	CString head[] ={
		TEXT("ҩƷ����"), TEXT("ҩƷ����"), TEXT("ҩƷ���"),
		TEXT("�����Ŀ"), TEXT("������˾"), TEXT("����"),
		TEXT("����ʱ��"), TEXT("������(��)"), TEXT("����(Ԫ)")
	};
	int n = sizeof(head) / sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		listCtrl.InsertColumn(i, head[i], LVCFMT_CENTER, 90);
	}

	//��ȡ�ĵ������ָ��
	CMedicAdminDoc *pDoc = (CMedicAdminDoc *)GetDocument();

	//��ȡ���ݿ��¼��ָ��
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	//�����ݿ�
	if (pMedicSet->IsOpen() == FALSE)
	{
		pMedicSet->Open();
	}

	//��ѯ
	pMedicSet->Requery();


	//�������ݿ�����
	//�������У���������
// 	listCtrl.InsertItem();
// 	listCtrl.SetItemText();

	//pMedicSet->GetRecordCount(): ��¼�������������˱�ͷ��
	for (int i = 0; i < pMedicSet->GetRecordCount(); i++)
	{

		/*
			TEXT("ҩƷ����"), TEXT("ҩƷ����"), TEXT("ҩƷ���"),
			TEXT("�����Ŀ"), TEXT("������˾"), TEXT("����"),
			TEXT("����ʱ��"), TEXT("������(��)"), TEXT("����(Ԫ)")
		*/
		CString str;
		int j = 1;

		//���ţ�ȷ����
		listCtrl.InsertItem(i, pMedicSet->m_id);

		//��ȷ����
		//ҩƷ����
		listCtrl.SetItemText(i, j++, pMedicSet->m_name);

		//ҩƷ���
		listCtrl.SetItemText(i, j++, pMedicSet->m_classification);

		//�����Ŀ
		str.Format(TEXT("%d"), pMedicSet->m_number);
		listCtrl.SetItemText(i, j++, str);

		//������˾
		listCtrl.SetItemText(i, j++, pMedicSet->m_produceCompany);

		//����
		listCtrl.SetItemText(i, j++, pMedicSet->m_producePlace);

		//ʱ��
		CTime time = pMedicSet->m_produceDate;
		str = time.Format(TEXT("%Y-%m-%d")); //2016-03-20;
		listCtrl.SetItemText(i, j++, str);

		//������(��)
		str.Format(TEXT("%d"), pMedicSet->m_quelityAssurance);
		listCtrl.SetItemText(i, j++, str);

		//���ۣ�����
		str.Format(TEXT("%d"), pMedicSet->m_unitPrice);
		listCtrl.SetItemText(i, j++, str);

		//��¼���ƶ�
		pMedicSet->MoveNext();
	}

}
