#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDelUserDlg �Ի���

class CDelUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDelUserDlg)

public:
	CDelUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDelUserDlg();

// �Ի�������
	enum { IDD = DIALOG_DEL_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_uiCombo;
	CString m_uiAccount;
	CListCtrl m_uiListCtrl;
public:
	virtual BOOL OnInitDialog();

	void UpdateListCtrl(CString type = TEXT("���г�Ա")); //�����б�ؼ�
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
};
