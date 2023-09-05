// login.cpp: ʵ���ļ�
//

#include "stdafx.h"
#include "login.h"
#include "afxdialogex.h"
#include "resource.h"


// login �Ի���

IMPLEMENT_DYNAMIC(login, CDialogEx)

login::login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_login, pParent)
	, password_value(_T(""))
	, username_value(_T(""))

{

}

login::~login()
{
}

void login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1_username, m_edit_usingname);
	DDX_Control(pDX, IDC_EDIT2_password, m_edit_password);
	DDX_Text(pDX, IDC_EDIT2_password, password_value);
	DDX_Text(pDX, IDC_EDIT1_username, username_value);
	DDX_Control(pDX, IDC_YONG, m_user);
	DDX_Control(pDX, IDC_MI, m_password);
	DDX_Control(pDX, IDC_BUTTON_OK, m_ok);
	DDX_Control(pDX, IDC_BUTTON2, m_cancle);
}


BEGIN_MESSAGE_MAP(login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &login::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_CHECK1, &login::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON2, &login::OnBnClickedButton2)
END_MESSAGE_MAP()


// login ��Ϣ�������

BOOL login::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	cfont.CreatePointFont(120, L"Consolas");
	m_edit_usingname.SetFont(&cfont);				//Ҫ��ȡ��ַ��
	m_edit_password.SetFont(&cfont);
	m_user.SetFont(&cfont);
	m_password.SetFont(&cfont);
	m_ok.SetFont(&cfont);
	m_cancle.SetFont(&cfont);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void login::OnBnClickedButtonOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int k = 3;
	CString name;
	CString password; // ���������ַ��������������û��������Ϣ���û���������ȣ�
	GetDlgItemText(IDC_EDIT1, name); // �����û���
	GetDlgItemText(IDC_EDIT2, password); // ��������
	UpdateData(true);
	if (password_value.IsEmpty())
	{
		MessageBox(L"�û�������Ϊ��");
	}
	if (password_value.IsEmpty())
		MessageBox(L"���벻��Ϊ��");
	if (username_value == "admin" && password_value == "123456")
	{
		// �������Ի������
		m_SuccessLogin = true;
		CDialogEx::OnOK(); // �رյ�½����
	}
	else
	{
		// ����������ʾ�û��������벻��ȷ
		MessageBox(_T("�û��������벻��ȷ��"), _T("��ʾ"), MB_OK);
		// ����û��������룬������������
		username_value = "";
		password_value = "";
		UpdateData(FALSE); // ���±༭��ؼ�����ʾֵ
	}
}


void login::OnBnClickedCheck1()			//��ʾ���밴ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (IsDlgButtonChecked(IDC_CHECK1) == BST_CHECKED)	//�����ѡ��
	{
		UpdateData(true);
		CEdit* pEdit = (CEdit*)(this)->GetDlgItem(IDC_EDIT2_password);
		pEdit->SetPasswordChar(0);
		SetDlgItemText(IDC_EDIT2_password, password_value);
		UpdateData(false);
	}
	else
	{
		UpdateData(true);
		CEdit* pEdit = (CEdit*)(this)->GetDlgItem(IDC_EDIT2_password);
		pEdit->SetPasswordChar('*');
		SetDlgItemText(IDC_EDIT2_password, password_value);
		UpdateData(false);
	}
	GetDlgItem(IDC_EDIT2_password)->SetFocus();
}
BOOL login::PreTranslateMessage(MSG* pMsg)	//���λس���Ӧ
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:     // ���λس�
			OnBnClickedButtonOk();
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}





void login::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
