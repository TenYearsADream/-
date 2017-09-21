
// MedicAdminDoc.h : CMedicAdminDoc ��Ľӿ�
//


#pragma once
#include "MedicSet.h"
#include "UserSet.h"
#include "User.h"
#include "MedicSearch.h"


class CMedicAdminDoc : public CDocument
{
protected: // �������л�����
	CMedicAdminDoc();
	DECLARE_DYNCREATE(CMedicAdminDoc)

public:
	//����ҩƷ���ݿ��¼��
	CMedicSet *GetMedicSet()
	{
		return &m_medicSet;
	}

	//�����û���Ϣ���ݿ��¼��
	CUserSet *GetUserSet()
	{
		return &m_userSet;
	}

	//�����û����������ָ��
	CUser *GetUser()
	{
		return &m_user;
	}

	CMedicSearch *GetMedicS()
	{
		return &m_medicS;
	}


private:
	CMedicSet m_medicSet; //ҩƷ���ݿ��¼��
	CUserSet m_userSet; //�û���Ϣ���ݿ��¼��

	CUser m_user; //�û����������

	CMedicSearch m_medicS; //ҩƷ��ѯ����

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMedicAdminDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
