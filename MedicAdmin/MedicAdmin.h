
// MedicAdmin.h : MedicAdmin Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMedicAdminApp:
// �йش����ʵ�֣������ MedicAdmin.cpp
//

class CMedicAdminApp : public CWinApp
{
public:
	CMedicAdminApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMedicAdminApp theApp;
