#pragma once


// CUserTreeView ��ͼ

class CUserTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CUserTreeView)

protected:
	CUserTreeView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();

	CImageList imageList;
};


