
// MedicAdminDoc.h : CMedicAdminDoc 类的接口
//


#pragma once
#include "MedicSet.h"
#include "UserSet.h"
#include "User.h"
#include "MedicSearch.h"


class CMedicAdminDoc : public CDocument
{
protected: // 仅从序列化创建
	CMedicAdminDoc();
	DECLARE_DYNCREATE(CMedicAdminDoc)

public:
	//返回药品数据库记录集
	CMedicSet *GetMedicSet()
	{
		return &m_medicSet;
	}

	//返回用户信息数据库记录集
	CUserSet *GetUserSet()
	{
		return &m_userSet;
	}

	//返回用户管理类对象指针
	CUser *GetUser()
	{
		return &m_user;
	}

	CMedicSearch *GetMedicS()
	{
		return &m_medicS;
	}


private:
	CMedicSet m_medicSet; //药品数据库记录集
	CUserSet m_userSet; //用户信息数据库记录集

	CUser m_user; //用户管理类对象

	CMedicSearch m_medicS; //药品查询对象

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMedicAdminDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
