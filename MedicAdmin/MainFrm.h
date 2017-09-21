
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "UserTreeView.h"
#include "MedicListView.h"
#include "MedicAdminDoc.h" //文档类对象指针

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	//拆分窗口对象
	CSplitterWnd m_sWnd;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnUpdateAddUser(CCmdUI *pCmdUI);

	//flag = 1，管理员
	//flag = 2，售药员
	void SetMyEnable(CCmdUI *pCmdUI, int flag = 1); //自定义菜单更新

private:
public:
	afx_msg void OnChangePwd();
	afx_msg void OnAddUser();
	afx_msg void OnUpdateDeleteUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSearchUser(CCmdUI *pCmdUI);
	afx_msg void OnDeleteUser();
	afx_msg void OnByType();
};


