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

	//过滤条件
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_userAccount, m_userPwd, m_userType);

	//MessageBox(sql);

	//设置过滤条件
	m_pUserSet->m_strFilter = sql;

	//重新查询
	m_pUserSet->Requery();

	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -2;
	}


	return 0;
}

int CUser::ChangePwd(CString oldPwd, CString newPwd, CString surePwd)
{
	if (m_pUserSet == NULL) //数据库指针
	{
		return -1;
	}

	if (oldPwd.IsEmpty() || newPwd.IsEmpty() || surePwd.IsEmpty())
	{
		return -2; //内容为空
	}

	if (oldPwd != m_userPwd)
	{
		return -7; //旧密码不一致
	}

	//旧密码和新密码不能相同
	if (oldPwd == newPwd)
	{
		return -3;
	}

	//确定密码和新密码不一致
	if (newPwd != surePwd)
	{
		return -4;
	}

	//过滤条件, 数据库指针，指向当前用户信息
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_userAccount, m_userPwd, m_userType);

	m_pUserSet->m_strFilter = sql;

	//查询
	m_pUserSet->Requery();

	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -5; //没有此用户
	}

	//修改
	m_pUserSet->Edit();

	m_pUserSet->m_password = newPwd; //新密码赋值


	//更新
	if (m_pUserSet->CanUpdate())
	{
		if (TRUE == m_pUserSet->Update()) //更新成功
		{
			m_userPwd = newPwd; //当前成员密码修改
			return 0;
		}
		else
		{
			return -6; //更新失败
		}
	}

	return 0;
}

int CUser::DelUser(CString account)
{
	if (account.IsEmpty())
	{
		return -1; //输入内容不能为空
	}

	if (m_pUserSet == NULL)
	{
		return -2; //数据库指针没有初始化
	}

	//删除的账号不能为当前登陆账号
	if (account == m_userAccount)
	{
		return -3;
	}

	//过滤
	CString sql;
	sql.Format(TEXT("account = '%s'"), account);

	m_pUserSet->m_strFilter = sql;

	m_pUserSet->Requery(); //查询

	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -4; //删除的用户不存在
	}

	m_pUserSet->Delete(); //删除当前记录集

	return 0;
}
