#pragma once
#include "afxwin.h"


// CSeekMTypeDlg �Ի���

class CSeekMTypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSeekMTypeDlg)

public:
	CSeekMTypeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSeekMTypeDlg();

// �Ի�������
	enum { IDD = DIALOG_S_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	CComboBox m_uiCombo;
public:
	afx_msg void OnCbnSelchangeCombo1();
};
