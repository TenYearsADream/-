
// MedicAdminView.h : CMedicAdminView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CMedicAdminView : public CFormView
{
protected: // �������л�����
	CMedicAdminView();
	DECLARE_DYNCREATE(CMedicAdminView)

public:
	enum{ IDD = IDD_MEDICADMIN_FORM };

// ����
public:
	CMedicAdminDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMedicAdminView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MedicAdminView.cpp �еĵ��԰汾
inline CMedicAdminDoc* CMedicAdminView::GetDocument() const
   { return reinterpret_cast<CMedicAdminDoc*>(m_pDocument); }
#endif

