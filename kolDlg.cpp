
// kolDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "kol.h"
#include "kolDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include "String.h"
//#include "CString"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CkolDlg




CkolDlg::CkolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CkolDlg::IDD, pParent)
	, m_edit2(_T(""))
	, m_edit3(_T(""))
	, m_edit1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
}

BEGIN_MESSAGE_MAP(CkolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CkolDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CkolDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// ����������� ��������� CkolDlg

BOOL CkolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CkolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CkolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CkolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CkolDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
  int i=0,j=0,k=0, ii=0;
   char mas_str[255];

 UpdateData(true);

 TCHAR buf[255];
 WCHAR qqq[500];

 CString sp = (LPWSTR)"  ";

 char p[255],ss[255];
 for (k=0;k<255;k++)  ss[k]=0;

 int len = m_edit2.GetLength() ;
 
	_tcscpy_s(buf, m_edit2.GetString());
	CW2AEX<_countof(buf)> bufA(buf);
	strcpy_s(p, bufA.m_psz);

 UpdateData(false);
 k=0;
 while ( k<len)
 {
    while (p[k] !=' ' && k<len)
	  { 
		mas_str[i] = p[k];
		k++; i++;
	   }
      mas_str[i]=' '; mas_str[i+1]=0;
	  if ((strlen( mas_str) -1) > m_edit1)
	   {
		   strcat(ss,mas_str);

	    }
	  i=0;	  k++;
 }
 
 if (strlen(ss)<m_edit1)
	  strcpy(ss,"��� ����, ��������������� �������");
   
	MultiByteToWideChar(CP_ACP,0,ss,strlen(ss)+4,(LPWSTR)qqq,sizeof(qqq)/sizeof(qqq[0]));
	 
	UpdateData(true);	
		m_edit3 = qqq;
 UpdateData(false);
	}


void CkolDlg::OnEnChangeEdit1()
{
	UpdateData(true);	
		if (m_edit1 <1)
			 this->GetDlgItem(IDOK)->EnableWindow(0);
		else
			 this->GetDlgItem(IDOK)->EnableWindow(1);
 UpdateData(false);
}
