#pragma once
#include <afxwin.h>  // MFC �������
#include <afxdlgs.h> // MFC ��׼�Ի���
// login �Ի���

class login: public CDialogEx
{
	DECLARE_DYNAMIC(login)

public:
	login(CWnd* pParent = nullptr);   // ��׼���캯��
	virtual ~login();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	void OnBnClickedButtonOk();
	CEdit m_edit_usingname;
	CEdit m_edit_password;
	CString password_value;
	CString username_value;
	afx_msg void OnBnClickedCheck1();
	BOOL PreTranslateMessage(MSG* pMsg);
	BOOL m_SuccessLogin;
	afx_msg void OnBnClickedButton2();
	CFont cfont;
	CStatic m_user;
	CStatic m_password;
	CButton m_ok;
	CButton m_cancle;
};
