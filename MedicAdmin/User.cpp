#include "stdafx.h"
#include "User.h"


CUser::CUser()
{
	m_pUserSet = NULL;
}


CUser::~CUser()
{
}

void CUser::SetAllMember(CString accout, CString pwd, CString type, CString name /*= TEXT("")*/)
{
	m_userAccount = accout;
	m_userPwd = pwd;
	m_userType = type;
	m_userName = name;

}

CString CUser::GetAccount()
{
	return m_userAccount;
}

CString CUser::GetPwd()
{
	return m_userPwd;
}

CString CUser::GetType()
{
	return m_userType;
}

CString CUser::GetName()
{
	return m_userName;
}

void CUser::SetUserSet(CUserSet *pSet)
{
	m_pUserSet = pSet;
}

int CUser::Login()
{
	if (m_pUserSet == NULL)
	{
		return -1;
	}

	//��������
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_userAccount, m_userPwd, m_userType);

	//MessageBox(sql);

	//���ù�������
	m_pUserSet->m_strFilter = sql;

	//���²�ѯ
	m_pUserSet->Requery();

	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -2;
	}


	return 0;
}

int CUser::ChangePwd(CString oldPwd, CString newPwd, CString surePwd)
{
	if (m_pUserSet == NULL) //���ݿ�ָ��
	{
		return -1;
	}

	if (oldPwd.IsEmpty() || newPwd.IsEmpty() || surePwd.IsEmpty())
	{
		return -2; //����Ϊ��
	}

	if (oldPwd != m_userPwd)
	{
		return -7; //�����벻һ��
	}

	//������������벻����ͬ
	if (oldPwd == newPwd)
	{
		return -3;
	}

	//ȷ������������벻һ��
	if (newPwd != surePwd)
	{
		return -4;
	}

	//��������, ���ݿ�ָ�룬ָ��ǰ�û���Ϣ
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_userAccount, m_userPwd, m_userType);

	m_pUserSet->m_strFilter = sql;

	//��ѯ
	m_pUserSet->Requery();

	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -5; //û�д��û�
	}

	//�޸�
	m_pUserSet->Edit();

	m_pUserSet->m_password = newPwd; //�����븳ֵ


	//����
	if (m_pUserSet->CanUpdate())
	{
		if (TRUE == m_pUserSet->Update()) //���³ɹ�
		{
			m_userPwd = newPwd; //��ǰ��Ա�����޸�
			return 0;
		}
		else
		{
			return -6; //����ʧ��
		}
	}

	return 0;
}

int CUser::DelUser(CString account)
{
	if (account.IsEmpty())
	{
		return -1; //�������ݲ���Ϊ��
	}

	if (m_pUserSet == NULL)
	{
		return -2; //���ݿ�ָ��û�г�ʼ��
	}

	//ɾ�����˺Ų���Ϊ��ǰ��½�˺�
	if (account == m_userAccount)
	{
		return -3;
	}

	//����
	CString sql;
	sql.Format(TEXT("account = '%s'"), account);

	m_pUserSet->m_strFilter = sql;

	m_pUserSet->Requery(); //��ѯ

	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -4; //ɾ�����û�������
	}

	m_pUserSet->Delete(); //ɾ����ǰ��¼��

	return 0;
}
