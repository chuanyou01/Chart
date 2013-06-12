#pragma once
#include "Control.h"

class CMainWnd: public CWnd
{
public:
	CMainWnd();
	virtual ~CMainWnd(void);

	ATOM MyRegisterClass();
	void Init(HINSTANCE hinst, int nCmdShow);
	//static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	virtual bool Load(wchar_t* pXmlBuffer);
public:
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
private:
	TCHAR		m_szTitle[MAX_LOADSTRING];					// 标题栏文本
	TCHAR		m_szWindowClass[MAX_LOADSTRING];			// 主窗口类名
	RECT		m_rect;
	DWORD		m_dwBkColor;
	DWORD		m_dwFrameColor;
	wchar_t*	m_pBckImg;
	
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnNcPaint();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
};
