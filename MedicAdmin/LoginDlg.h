#pragma once
#include "afxwin.h"


// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
	enum { IDD = DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton2();
private:
	CComboBox m_uiCombo;
	CString m_uiAccout;
	CString m_uiPwd;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
