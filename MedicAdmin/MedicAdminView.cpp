
// MedicAdminView.cpp : CMedicAdminView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MedicAdmin.h"
#endif

#include "MedicAdminDoc.h"
#include "MedicAdminView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedicAdminView

IMPLEMENT_DYNCREATE(CMedicAdminView, CFormView)

BEGIN_MESSAGE_MAP(CMedicAdminView, CFormView)
END_MESSAGE_MAP()

// CMedicAdminView ����/����

CMedicAdminView::CMedicAdminView()
	: CFormView(CMedicAdminView::IDD)
{
	// TODO:  �ڴ˴���ӹ������

}

CMedicAdminView::~CMedicAdminView()
{
}

void CMedicAdminView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMedicAdminView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMedicAdminView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMedicAdminView ���

#ifdef _DEBUG
void CMedicAdminView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedicAdminView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedicAdminDoc* CMedicAdminView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedicAdminDoc)));
	return (CMedicAdminDoc*)m_pDocument;
}
#endif //_DEBUG


// CMedicAdminView ��Ϣ�������
