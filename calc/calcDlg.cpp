
// calcDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "calc.h"
#include "calcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalcDlg dialog



CcalcDlg::CcalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_BTN_1, btn_1);
	DDX_Control(pDX, ID_BTN_2, btn_2);
	DDX_Control(pDX, ID_BTN_3, btn_3);
	DDX_Control(pDX, ID_BTN_0, btn_0);
	DDX_Control(pDX, ID_BTN_4, btn_4);
	DDX_Control(pDX, ID_BTN_5, btn_5);
	DDX_Control(pDX, ID_BTN_6, btn_6);
	DDX_Control(pDX, ID_BTN_7, btn_7);
	DDX_Control(pDX, ID_BTN_8, btn_8);
	DDX_Control(pDX, ID_BTN_9, btn_9);
	DDX_Control(pDX, ID_BTN_SUM, btn_sum);
	DDX_Control(pDX, ID_BTN_SUB, btn_sub);
	DDX_Control(pDX, ID_BTN_MUL, btn_mul);
	DDX_Control(pDX, ID_BTN_DIV, btn_div);
	DDX_Control(pDX, ID_BTN_EQUA, btn_equa);
	DDX_Control(pDX, ID_EDIT1, edt_resul);
	DDX_Control(pDX, IDC_EDIT2, edt_2);
	DDX_Control(pDX, ID_BTN_SQRT, btn_sqrt);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BTN_1, &CcalcDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(ID_BTN_0, &CcalcDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(ID_BTN_2, &CcalcDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(ID_BTN_3, &CcalcDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(ID_BTN_4, &CcalcDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(ID_BTN_5, &CcalcDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(ID_BTN_6, &CcalcDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(ID_BTN_7, &CcalcDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(ID_BTN_8, &CcalcDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(ID_BTN_9, &CcalcDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(ID_BTN_SUM, &CcalcDlg::OnBnClickedBtnSum)
	ON_BN_CLICKED(ID_BTN_EQUA, &CcalcDlg::OnBnClickedBtnEqua)
	ON_BN_CLICKED(IDC_BUTTON18, &CcalcDlg::OnBnClickedButton18)
	ON_BN_CLICKED(ID_BTN_SUB, &CcalcDlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(ID_BTN_MUL, &CcalcDlg::OnBnClickedBtnMul)
	ON_BN_CLICKED(ID_BTN_DIV, &CcalcDlg::OnBnClickedBtnDiv)
	ON_BN_CLICKED(ID_BTN_CE, &CcalcDlg::OnBnClickedBtnCe)
	ON_BN_CLICKED(ID_BTN_C, &CcalcDlg::OnBnClickedBtnC)
	ON_BN_CLICKED(ID_BTN_SQRT, &CcalcDlg::OnBnClickedBtnSqrt)
END_MESSAGE_MAP()


// CcalcDlg message handlers

BOOL CcalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalcDlg::OnBnClickedBtn1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_result);
	edt_2.GetWindowText(str_val1);


	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "1";
	}
	else {
		str_result += "1";
	}
	
	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn0()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);

	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "0";
	}
	else {
		str_result += "0";
	}
	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn2()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "2";
	}
	else {
		str_result += "2";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE); 
}


void CcalcDlg::OnBnClickedBtn3()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "3";
	}
	else {
		str_result += "3";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE); 
}


void CcalcDlg::OnBnClickedBtn4()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "4";
	}
	else {
		str_result += "4";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn5()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "5";
	}
	else {
		str_result += "5";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn6()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "6";
	}
	else {
		str_result += "6";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn7()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "7";
	}
	else {
		str_result += "7";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn8()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "8";
	}
	else {
		str_result += "8";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE); 
}


void CcalcDlg::OnBnClickedBtn9()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result == "0" || str_result == "Cannot divide by zero.") {
		str_result = "9";
	}
	else {
		str_result += "9";
	}

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


CString calc(CString str_val1, CString str_val2) {

	//convert string to float
	float val1 = _tstof(str_val1);
	float val2;
	val2 = _tstof(str_val2);

	float ret = 0.0;

	//handle math
	if (str_val1[str_val1.GetLength() - 1] == '+') {
		ret = val1 + val2;
	}
	else if (str_val1[str_val1.GetLength() - 1] == '-') {
		ret = val1 - val2;
	}
	else if (str_val1[str_val1.GetLength() - 1] == '*') {
		ret = val1 * val2;
	}
	else if (str_val1[str_val1.GetLength() - 1] == '/') {
		if (val2 == 0) {
			return _T("Cannot divide by zero.");
		}
		else {
			ret = val1 / val2;
		}
	}
	else {
		ret = val2;
	}

	//convert float to string 
	CString strRet;
	strRet.Format(_T("%f"), ret);

	str_val1 += str_val2;

	//chuan hoa
	while (strRet.GetAt(strRet.GetLength() - 1) == '0') {
		int length = strRet.GetLength() - 1;
		strRet.Delete(length, 1);
	}

	if (strRet.GetAt(strRet.GetLength() - 1) == '.') {
		int length = strRet.GetLength() - 1;
		strRet.Delete(length, 1);
	}
	return strRet;
}

void CcalcDlg::OnBnClickedBtnSum()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T(""); 
	CString str_val1 = _T(""); 

	edt_resul.GetWindowText(str_result); 
	edt_2.GetWindowText(str_val1); 

	//



	//
	if (str_result == "0") {
		str_result = "+";
	}
	else {
		str_result += "+";
	}
	edt_2.SetWindowText(str_result);
	edt_resul.SetWindowText(_T(""));
	UpdateData(FALSE);



}


void CcalcDlg::OnBnClickedBtnEqua()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val1 = _T("");
	CString str_val2 = _T("");

	//get data 
	edt_resul.GetWindowText(str_val2);
	edt_2.GetWindowText(str_val1);
	CString str =_T("");
	if (str_val2 == "") {
		str_val2 = str_val1;
		str_val2.Delete(str_val2.GetLength() - 1, 1);
		str = calc(str_val1, str_val2);
	}
	else {
		str = calc(str_val1, str_val2);
	}
	

	//result
	str_val1 += str_val2;
	edt_2.SetWindowText(str_val1);
	edt_resul.SetWindowText(str);
	UpdateData(FALSE);

}


void CcalcDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	if (str_result.Find('.', 0) == 1) return;
	str_result += ".";

	edt_resul.SetWindowText(str_result);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnSub()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_result);
	str_val1 = str_result;

	if (str_result == "0") {
		str_result = "-";
	}
	else {
		str_result += "-";
	}

	edt_2.SetWindowText(str_result);
	edt_resul.SetWindowText(_T(""));
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnMul()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_result);
	str_val1 = str_result;

	if (str_result == "0") {
		str_result = "*";
	}
	else {
		str_result += "*";
	}

	edt_2.SetWindowText(str_result);
	edt_resul.SetWindowText(_T(""));
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnDiv()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_result);
	str_val1 = str_result;

	if (str_result == "0") {
		str_result = "/";
	}
	else {
		str_result += "/";
	}

	edt_2.SetWindowText(str_result);
	edt_resul.SetWindowText(_T(""));
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnCe()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	edt_resul.SetWindowText(_T("")); 
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnC()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_result = _T("");
	edt_resul.GetWindowText(str_result);
	edt_resul.SetWindowText(_T(""));
	edt_2.SetWindowTextW(_T(""));
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnSqrt()
{
	// TODO: Add your control notification handler code here
}
