#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDelUserDlg 对话框

class CDelUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDelUserDlg)

public:
	CDelUserDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDelUserDlg();

// 对话框数据
	enum { IDD = DIALOG_DEL_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_uiCombo;
	CString m_uiAccount;
	CListCtrl m_uiListCtrl;
public:
	virtual BOOL OnInitDialog();

	void UpdateListCtrl(CString type = TEXT("所有成员")); //更新列表控件
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
};
