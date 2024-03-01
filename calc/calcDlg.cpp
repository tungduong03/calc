
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

int flag_val1 = 0, flag_val2 = 0, flag_dau = 0, flag = 1;
CString value_1 = _T("0"), value_2, answer, dau;

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

	UpdateData(true);
	edt_resul.SetWindowText(_T("0"));
	UpdateData(false);

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

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);
	
	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "1";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "1";
			}
			else {
				value_1 += "1";
			}
		}
		str_val2 = value_1; 
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "1";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "1";
			}
			else {
				value_2 += "1";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "1";
		}
		else {
			value_2 += "1";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn0()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "0";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "0";
			}
			else {
				value_1 += "0";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "0";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "0";
			}
			else {
				value_2 += "0";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "0";
		}
		else {
			value_2 += "0";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn2()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "2";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "2";
			}
			else {
				value_1 += "2";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "2";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "2";
			}
			else {
				value_2 += "2";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "2";
		}
		else {
			value_2 += "2";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn3()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "3";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "3";
			}
			else {
				value_1 += "3";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "3";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "3";
			}
			else {
				value_2 += "3";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "3";
		}
		else {
			value_2 += "3";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn4()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "4";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "4";
			}
			else {
				value_1 += "4";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "4";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "4";
			}
			else {
				value_2 += "4";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "4";
		}
		else {
			value_2 += "4";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn5()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "5";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "5";
			}
			else {
				value_1 += "5";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "5";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "5";
			}
			else {
				value_2 += "5";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "5";
		}
		else {
			value_2 += "5";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn6()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "6";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "6";
			}
			else {
				value_1 += "6";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "6";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "6";
			}
			else {
				value_2 += "6";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "6";
		}
		else {
			value_2 += "6";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE); 
}


void CcalcDlg::OnBnClickedBtn7()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "7";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "7";
			}
			else {
				value_1 += "7";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "7";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "7";
			}
			else {
				value_2 += "7";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "7";
		}
		else {
			value_2 += "7";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn8()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "8";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "8";
			}
			else {
				value_1 += "8";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "8";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "8";
			}
			else {
				value_2 += "8";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "8";
		}
		else {
			value_2 += "8";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtn9()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "9";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "9";
			}
			else {
				value_1 += "9";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_2 = "9";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "9";
			}
			else {
				value_2 += "9";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "9";
		}
		else {
			value_2 += "9";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


CString calc(CString str_val1, CString str_val2, CString dau) {

	//convert string to float
	float val1 = _tstof(str_val1);
	float val2 = _tstof(str_val2);

	float ret = 0.0;

	//handle math
	if (dau == "+") {
		ret = val1 + val2;
	}
	else if (dau == "-") {
		ret = val1 - val2;
	}
	else if (dau == "*") {
		ret = val1 * val2;
	}
	else if (dau == "/") {
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
	CString str_val2 = _T(""); 
	CString str_val1 = _T(""); 

	edt_resul.GetWindowText(str_val2); 
	edt_2.GetWindowText(str_val1); 
	
	if (flag == 2) { //đang ở trạng thái nhập dấu
		dau = "+";
		flag_val2 = 0;
		edt_2.SetWindowText(str_val2+dau);
		edt_resul.SetWindowText(_T(""));
		UpdateData(FALSE);
	}
	else if (flag == 1) {
		flag = 2; //chuyển trạng thái từ nhập số qua nhập dấu
		dau = "+";
		edt_2.SetWindowText(str_val2+dau);
		edt_resul.SetWindowText(str_val2);
		UpdateData(FALSE);
	}
	else if (flag == 3) { //đủ bộ số và dấu sẽ đưa lên tính toán
		answer = calc(value_1, value_2, dau);
		dau = "+";
		flag = 2;
		value_1 = answer;
		value_2 = answer;
		flag_val2 = 0;
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(str_val1 + str_val2 + dau); 
			edt_resul.SetWindowText(answer); 
			UpdateData(FALSE); 
		}
		else {
			edt_2.SetWindowText(value_1);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 4) { //vừa mới tính phép "="
		flag = 2;
		dau = "+";
		value_1 = answer;
		flag_val2 = 0;
		edt_2.SetWindowText(value_1 + dau);
		edt_resul.SetWindowText(answer);
		UpdateData(FALSE);
	}

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
	
	if (flag == 3) { //nếu đã đủ 3 số
		answer = calc(value_1, value_2, dau);
		str = answer;
		str_val1 += str_val2;
		str_val1 += "=";
		str_val1 += answer;
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(str_val1);
			edt_resul.SetWindowText(str);
			UpdateData(FALSE);
		}
		else {
			edt_2.SetWindowText(value_1 + "/0");
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 2) { //nếu chỉ có biến 1 và dấu thì 5 + = là 5 + 5 = 10
		value_2 = value_1;
		answer = calc(value_1, value_2, dau);
		str = answer;
		str_val1 += str_val2; 
		str_val1 += "=";
		str_val1 += answer; 
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(str_val1);
			edt_resul.SetWindowText(str);
			UpdateData(FALSE);
		}
		else {
			edt_2.SetWindowText(value_1 + "/0");
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 1) { //nếu chỉ có biến 1 chưa có dấu và biến 2: 5 = 5
		answer = value_1;
		str = answer;
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(value_1 + "=" + answer);
			edt_resul.SetWindowText(str);
			UpdateData(FALSE);
		}
		else {
			edt_2.SetWindowText(value_1 + "/0");
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 4) {
		answer = calc(value_1, value_2, dau);
		str = answer;
		
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(value_1 + dau + value_2 + "=" + answer);
			edt_resul.SetWindowText(str);
			UpdateData(FALSE); 
		}
		else {
			edt_2.SetWindowText(value_1 + "/0");
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	flag = 4; // flag = 4 đã tính kết quả
	value_1 = answer;
	flag_val1 = 0;

	
}


void CcalcDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CString str_val2 = _T("");

	edt_resul.GetWindowText(str_val2);

	if (flag == 1) {   //nhập số thứ 1
		if (flag_val1 == 0) {
			value_1 = "0.";
			flag_val1 = 1;
		}
		else {
			if (value_1 == "0" || value_1 == "Cannot divide by zero.") {
				value_1 = "0.";
			}
			else {
				if (value_1.Find('.', 0) == 1) return;
				value_1 += ".";
			}
		}
		str_val2 = value_1;
	}
	else if (flag == 3) {  //nhập số thứ 2
		if (flag_val2 == 0) {
			value_1 = "0.";
			flag_val2 = 1;
		}
		else {
			if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
				value_2 = "0.";
			}
			else {
				if (value_2.Find('.', 0) == 1) return;
				value_2 += ".";
			}
		}
		str_val2 = value_2;
	}
	else if (flag == 2) { //chuyển trạng thái từ nhập dấu qua nhập số
		flag = 3;
		value_2 = "0";
		if (value_2 == "0" || value_2 == "Cannot divide by zero.") {
			value_2 = "0.";
		}
		else {
			if (value_2.Find('.', 0) == 1) return;
			value_2 += ".";
		}
		flag_val2 = 1;
		str_val2 = value_2;
	}

	edt_resul.SetWindowText(str_val2);
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnSub()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_val2 = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_val2);
	edt_2.GetWindowText(str_val1);

	if (flag == 2) { //đang ở trạng thái nhập dấu
		dau = "-";
		flag_val2 = 0;
		edt_2.SetWindowText(str_val2 + dau);
		edt_resul.SetWindowText(_T(""));
		UpdateData(FALSE);
	}
	else if (flag == 1) {
		flag = 2; //chuyển trạng thái từ nhập số qua nhập dấu
		dau = "-";
		edt_2.SetWindowText(str_val2 + dau);
		edt_resul.SetWindowText(str_val2);
		UpdateData(FALSE);
	}
	else if (flag == 3) { //đủ bộ số và dấu sẽ đưa lên tính toán
		answer = calc(value_1, value_2, dau);
		dau = "-";
		flag = 2;
		value_1 = answer;
		value_2 = answer;
		flag_val2 = 0;
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(str_val1 + str_val2 + dau);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
		else {
			edt_2.SetWindowText(value_1);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 4) { //vừa mới tính phép "="
		flag = 2;
		dau = "-";
		value_1 = answer;
		flag_val2 = 0;
		edt_2.SetWindowText(value_1 + dau);
		edt_resul.SetWindowText(answer);
		UpdateData(FALSE);
	}
}


void CcalcDlg::OnBnClickedBtnMul()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_val2 = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_val2);
	edt_2.GetWindowText(str_val1);

	if (flag == 2) { //đang ở trạng thái nhập dấu
		dau = "*";
		flag_val2 = 0;
		edt_2.SetWindowText(str_val2 + dau);
		edt_resul.SetWindowText(_T(""));
		UpdateData(FALSE);
	}
	else if (flag == 1) {
		flag = 2; //chuyển trạng thái từ nhập số qua nhập dấu
		dau = "*";
		edt_2.SetWindowText(str_val2 + dau);
		edt_resul.SetWindowText(str_val2);
		UpdateData(FALSE);
	}
	else if (flag == 3) { //đủ bộ số và dấu sẽ đưa lên tính toán
		answer = calc(value_1, value_2, dau);
		dau = "*";
		flag = 2;
		value_1 = answer;
		value_2 = answer;
		flag_val2 = 0;
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(str_val1 + str_val2 + dau);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
		else {
			edt_2.SetWindowText(value_1);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 4) { //vừa mới tính phép "="
		flag = 2;
		dau = "*";
		value_1 = answer;
		flag_val2 = 0;
		edt_2.SetWindowText(value_1 + dau);
		edt_resul.SetWindowText(answer);
		UpdateData(FALSE);
	}
}


void CcalcDlg::OnBnClickedBtnDiv()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_val2 = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_val2);
	edt_2.GetWindowText(str_val1);

	if (flag == 2) { //đang ở trạng thái nhập dấu
		dau = "/";
		flag_val2 = 0;
		edt_2.SetWindowText(str_val2 + dau);
		edt_resul.SetWindowText(_T(""));
		UpdateData(FALSE);
	}
	else if (flag == 1) {
		flag = 2; //chuyển trạng thái từ nhập số qua nhập dấu
		dau = "/";
		edt_2.SetWindowText(str_val2 + dau);
		edt_resul.SetWindowText(str_val2);
		UpdateData(FALSE);
	}
	else if (flag == 3) { //đủ bộ số và dấu sẽ đưa lên tính toán
		answer = calc(value_1, value_2, dau);
		dau = "/";
		flag = 2;
		value_1 = answer;
		value_2 = answer;
		flag_val2 = 0;
		if (answer != "Cannot divide by zero.") {
			edt_2.SetWindowText(str_val1 + str_val2 + dau);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
		else {
			edt_2.SetWindowText(value_1);
			edt_resul.SetWindowText(answer);
			UpdateData(FALSE);
		}
	}
	else if (flag == 4) { //vừa mới tính phép "="
		flag = 2;
		dau = "/";
		value_1 = answer;
		flag_val2 = 0;
		edt_2.SetWindowText(value_1 + dau);
		edt_resul.SetWindowText(answer);
		UpdateData(FALSE);
	}
}


void CcalcDlg::OnBnClickedBtnCe()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if (flag == 1) { //đang nhập số 1
		value_1 = "0";
		flag_val1 = 0;
		edt_resul.SetWindowText(_T("0"));
		UpdateData(FALSE);
	}
	else if (flag == 3) { //đang nhập số 2
		value_2 = "0";
		flag_val2 = 1;
		edt_resul.SetWindowText(_T("0"));
		UpdateData(FALSE);
	}
	else if (flag == 2) { //đang nhập dấu
		value_2 = "0";
		flag_val2 = 0;
		edt_resul.SetWindowText(_T("0"));
		UpdateData(FALSE);
	}
}


void CcalcDlg::OnBnClickedBtnC()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	value_1 = "0";
	value_2 = "";
	answer = "";
	dau = "";
	flag = 1;
	flag_val1 = 0;
	flag_val2 = 0;


	edt_resul.SetWindowText(_T("0"));
	edt_2.SetWindowTextW(_T(""));
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedBtnSqrt()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str_val2 = _T("");
	CString str_val1 = _T("");

	edt_resul.GetWindowText(str_val2); 
	edt_2.GetWindowText(str_val1); 

	if (flag == 2) { //đang ở trạng thái nhập dấu
		flag_val2 = 0;

		float val2 = _tstof(value_1);
		val2 = sqrt(val2);
		value_2.Format(_T("%f"), val2);
		answer = calc(value_1, value_2, dau);

		edt_2.SetWindowText(value_1 + dau + "sqrt(" + value_1 + ")"); 
		edt_resul.SetWindowText(answer);
		UpdateData(FALSE);
	}
	else if (flag == 1) {
		flag = 2; //chuyển trạng thái từ nhập số qua nhập dấu
		float val1 = _tstof(value_1); 
		float val2 = sqrt(val1); 
		answer.Format(_T("%f"), val2); 
		answer = calc(answer, _T("0"), _T("+"));
		
		edt_2.SetWindowText(_T("sqrt("+value_1+_T(")")));
		edt_resul.SetWindowText(answer);
		value_1 = answer;
		UpdateData(FALSE);
	}
	else if (flag == 3) { //đủ bộ số và dấu sẽ đưa lên tính toán
		flag = 2;
		float val1 = _tstof(value_2);
		float val2 = sqrt(val1);
		value_2.Format(_T("%f"), val2);
		answer = calc(value_1, value_2, dau);
		value_2 = calc(value_2, _T("0"), _T("+"));
		edt_2.SetWindowText(value_1 + dau + _T("sqrt(" + value_2 + _T(")")));
		edt_resul.SetWindowText(answer);
		value_1 = answer;
		UpdateData(FALSE);
	}
	else if (flag == 4) { //vừa mới tính phép "="
		flag = 2;
		value_1 = answer;
		float val1 = _tstof(value_1);
		float val2 = sqrt(val1);
		answer.Format(_T("%f"), val2);
		answer = calc(answer, _T("0"), _T("+"));
		flag_val2 = 0;
		edt_2.SetWindowText(_T("sqrt(" + value_1 + _T(")")));
		edt_resul.SetWindowText(answer);
		value_1 = answer;
		UpdateData(FALSE);
	}
}
