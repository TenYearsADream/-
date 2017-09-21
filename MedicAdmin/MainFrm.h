
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "UserTreeView.h"
#include "MedicListView.h"
#include "MedicAdminDoc.h" //�ĵ������ָ��

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	//��ִ��ڶ���
	CSplitterWnd m_sWnd;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnUpdateAddUser(CCmdUI *pCmdUI);

	//flag = 1������Ա
	//flag = 2����ҩԱ
	void SetMyEnable(CCmdUI *pCmdUI, int flag = 1); //�Զ���˵�����

private:
public:
	afx_msg void OnChangePwd();
	afx_msg void OnAddUser();
	afx_msg void OnUpdateDeleteUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSearchUser(CCmdUI *pCmdUI);
	afx_msg void OnDeleteUser();
	afx_msg void OnByType();
};


