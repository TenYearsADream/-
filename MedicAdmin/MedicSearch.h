#pragma once
//���ݿ�ָ��
#include "MedicSet.h" //ҩƷ���ݿ�

class CMedicSearch
{
public:
	CMedicSearch();
	virtual ~CMedicSearch();

	//����ҩƷ���ݿ�ָ��
	void SetMedicSet(CMedicSet *pSet);

	//�����б�ؼ�ָ��
	void SetListCtrl(CListCtrl *listCtrl);

	//��������ѯҩƷ��Ϣ���ɹ�Ϊ0��ʧ�ܷ�0
	int SearchByType(CString type = TEXT("�������"));

private:
	CMedicSet *m_pMedicSet; //ҩƷ���ݿ�ָ��
	CListCtrl *m_listCtrl; //�б�ؼ�ָ��
};

