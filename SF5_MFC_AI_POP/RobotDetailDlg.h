﻿#pragma once
#include "afxdialogex.h"

#include "ChartViewer.h"
#include <vector>

using namespace std;


#define WM_UPDATE_CHART1 (WM_USER + 11)


// RobotDetailDlg dialog

class RobotDetailDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RobotDetailDlg)

public:
	RobotDetailDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~RobotDetailDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROBOT_DETAIL_DAILOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
    afx_msg LRESULT OnUpdateChart(WPARAM wParam, LPARAM lParam);

private:
    vector<vector<double>> m_dataSets;
    vector<double> m_timestamps;
    CChartViewer m_ChartViewer1, m_ChartViewer2;
    double m_nextTime;

    void UpdateChart();
    void AddDataPoints(const vector<vector<double>>& dataPoints);
public:
    afx_msg void OnBnClickedButton1();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    virtual BOOL OnInitDialog();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};