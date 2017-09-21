#pragma once
#include "UserSet.h"

class CUser //用户管理类
{
public:
	CUser();
	virtual ~CUser();

	//设置所有成员
	void SetAllMember(CString accout, CString pwd, CString type, CString name = TEXT(""));

	//获取账号
	CString GetAccount();

	//获取密码
	CString GetPwd();

	//获取类别
	CString GetType();

	//获取真实姓名
	CString GetName();

	//设置用户数据库记录集指针
	void SetUserSet(CUserSet *pSet);

	//成功为0，失败非0
	int Login();

	//修改密码, 成功为0，失败非0
	int ChangePwd(CString oldPwd, CString newPwd, CString surePwd);

	//根据账号删除用户，成功为0，失败非0
	int DelUser(CString account);


private:
	CString m_userAccount;// 账号
	CString m_userPwd;	// 密码
	CString m_userType;	// 类别
	CString m_userName;	// 真实姓名

	//用户数据库记录集指针
	CUserSet *m_pUserSet;
};

