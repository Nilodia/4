
// kolDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CkolDlg
class CkolDlg : public CDialogEx
{
// ��������
public:
	CkolDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_KOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_edit2;
	CString m_edit3;
	int m_edit1;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};
