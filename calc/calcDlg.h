
// calcDlg.h : header file
//

#pragma once


// CcalcDlg dialog
class CcalcDlg : public CDialogEx
{
// Construction
public:
	CcalcDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CButton btn_1;
	CButton btn_2;
	CButton btn_3;
	CButton btn_0;
	CButton btn_4;
	CButton btn_5;
	CButton btn_6;
	CButton btn_7;
	CButton btn_8;
	CButton btn_9;
	CButton btn_sum;
	CButton btn_sub;
	CButton btn_mul;
	CButton btn_div;
	CButton btn_equa;
	CEdit edt_resul;
public:
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
protected:
	CEdit edt_2;
public:
	afx_msg void OnBnClickedBtnSum();
	afx_msg void OnBnClickedBtnEqua();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnMul();
	afx_msg void OnBnClickedBtnDiv();
	afx_msg void OnBnClickedBtnCe();
	afx_msg void OnBnClickedBtnC();
protected:
	CButton btn_sqrt;
public:
	afx_msg void OnBnClickedBtnSqrt();
};
