#pragma once


// CChangePwdDlg 对话框

class CChangePwdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePwdDlg)

public:
	CChangePwdDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangePwdDlg();

// 对话框数据
	enum { IDD = DIALOG_CHANGE_PWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
private:
	CString m_uiAccout;
	CString m_uiOldPwd;
//	CString m_newPwd;
	CString m_uiNewPwd;
	CString m_uiSurePwd;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton3();
};
