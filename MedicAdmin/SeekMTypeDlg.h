#pragma once
#include "afxwin.h"


// CSeekMTypeDlg 对话框

class CSeekMTypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSeekMTypeDlg)

public:
	CSeekMTypeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSeekMTypeDlg();

// 对话框数据
	enum { IDD = DIALOG_S_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	CComboBox m_uiCombo;
public:
	afx_msg void OnCbnSelchangeCombo1();
};
