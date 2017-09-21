#pragma once
#include "UserSet.h"

class CUser //�û�������
{
public:
	CUser();
	virtual ~CUser();

	//�������г�Ա
	void SetAllMember(CString accout, CString pwd, CString type, CString name = TEXT(""));

	//��ȡ�˺�
	CString GetAccount();

	//��ȡ����
	CString GetPwd();

	//��ȡ���
	CString GetType();

	//��ȡ��ʵ����
	CString GetName();

	//�����û����ݿ��¼��ָ��
	void SetUserSet(CUserSet *pSet);

	//�ɹ�Ϊ0��ʧ�ܷ�0
	int Login();

	//�޸�����, �ɹ�Ϊ0��ʧ�ܷ�0
	int ChangePwd(CString oldPwd, CString newPwd, CString surePwd);

	//�����˺�ɾ���û����ɹ�Ϊ0��ʧ�ܷ�0
	int DelUser(CString account);


private:
	CString m_userAccount;// �˺�
	CString m_userPwd;	// ����
	CString m_userType;	// ���
	CString m_userName;	// ��ʵ����

	//�û����ݿ��¼��ָ��
	CUserSet *m_pUserSet;
};

