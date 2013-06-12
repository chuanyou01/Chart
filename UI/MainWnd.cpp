#include "StdAfx.h"
#include "MainWnd.h"
extern CMainWnd* g_mainWnd;

CMainWnd::CMainWnd()
:m_dwBkColor(0x1D1D1D)
{

	m_rect.left = 200;
	m_rect.top = 200;
	m_rect.bottom = 400;
	m_rect.right = 500;
}

CMainWnd::~CMainWnd(void)
{
}

//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM CMainWnd::MyRegisterClass()
{
	WNDCLASSEX wcex;
// 
// 	HBITMAP bmp;
// 	HBRUSH hBursh;
// 	bmp = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
// 
// 	hBursh = CreatePatternBrush(bmp);
	HBRUSH hBrush = CreateSolidBrush(m_dwBkColor);

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= AfxWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInstance;
	wcex.hIcon			= LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_UI));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= hBrush;//(HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//MAKEINTRESOURCE(IDC_UI);
	wcex.lpszClassName	= m_szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
//BOOL CMainWnd::InitInstance(int nCmdShow)
//{
//// 	m_hWnd = CreateWindow(m_szWindowClass, m_szTitle, WS_OVERLAPPEDWINDOW,
//// 		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, m_hInstance, NULL);
//
//// 	m_hWnd = CreateWindowEx(/*WS_EX_TOPMOST*/WS_EX_APPWINDOW  , m_szWindowClass, m_szWindowClass,
//// 		WS_POPUP | WS_SYSMENU | WS_MINIMIZEBOX | WS_SIZEBOX, /*CW_USEDEFAULT*/m_rect.left, m_rect.top, m_rect.right-m_rect.left, 
//// 		m_rect.bottom - m_rect.top, NULL, NULL, m_hInstance, NULL);
//// 
//// 	if (!m_hWnd)
//// 	{
//// 		return FALSE;
//// 	}
//
//	ShowWindow(nCmdShow);
//	UpdateWindow();
//
//	return TRUE;
//}

void CMainWnd::Init( HINSTANCE hinst, int nCmdShow )
{
	m_hInstance = hinst;
	LoadString(hinst, IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadString(hinst, IDC_UI, m_szWindowClass, MAX_LOADSTRING);

	afxCurrentInstanceHandle = hinst;
	AfxSetResourceHandle(m_hInstance);

	CreateEx(WS_EX_APPWINDOW, m_szWindowClass, m_szTitle, WS_POPUP | WS_SYSMENU | WS_MINIMIZEBOX | WS_SIZEBOX,
		m_rect, NULL, 900);

	ShowWindow(nCmdShow);
	UpdateWindow();
}
//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
// LRESULT CALLBACK CMainWnd::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// {
// 	int wmId, wmEvent;
// 	PAINTSTRUCT ps;
// 	HDC hdc;
// 
// 	switch (message)
// 	{
// 	case WM_COMMAND:
// 		wmId    = LOWORD(wParam);
// 		wmEvent = HIWORD(wParam);
// 		// 分析菜单选择:
// 		switch (wmId)
// 		{
// 	//	case IDM_ABOUT:
// 	//		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
// 	//		break;
// 		case IDM_EXIT:
// 			DestroyWindow(hWnd);
// 			break;
// 		default:
// 			return DefWindowProc(hWnd, message, wParam, lParam);
// 		}
// 		break;
// 	case WM_PAINT:
// 		hdc = BeginPaint(hWnd, &ps);
// 		// TODO: 在此添加任意绘图代码...
// 		EndPaint(hWnd, &ps);
// 		break;
// 	case WM_DESTROY:
// 		PostQuitMessage(0);
// 		break;
// 	case WM_NCPAINT:
// 		{
// 			HDC hdc;
// 
// 			hdc = GetDCEx(hWnd, (HRGN)wParam, DCX_WINDOW|DCX_INTERSECTRGN);
// 
// 			// 进入设备场景画
// 			HBRUSH hBkBrush = CreateSolidBrush(g_mainWnd->m_dwFrameColor);
// 			if (hBkBrush!=NULL)
// 			{
// 				RECT wnd, rtClient;
// 				GetWindowRect(hWnd, &wnd);
// 				GetClientRect(hWnd, &rtClient);
// 				
// 				//FillRect(hdc, &wnd, hBkBrush);
// 				//FillRgn(hdc, (HRGN)wParam, hBkBrush);
// 
// 				POINT pt;
// 				MoveToEx(hdc, wnd.left, wnd.top, &pt);
// 				LineTo(hdc, wnd.right, wnd.top);
// 				LineTo(hdc, wnd.right, wnd.bottom);
// 				LineTo(hdc, wnd.left, wnd.bottom);
// 				LineTo(hdc, wnd.left, wnd.top);
// 
// 				FillPath()
// 			}
// 
// 			ReleaseDC(hWnd, hdc);
// 		}
// 		break;
// 	default:
// 		return DefWindowProc(hWnd, message, wParam, lParam);
// 	}
// 	return 0;
// }

bool CMainWnd::Load( wchar_t* pXmlBuffer )
{
	return false;
}


BOOL CMainWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	MyRegisterClass();
	cs.hInstance = m_hInstance;
	cs.lpszClass = m_szWindowClass;
	cs.hMenu = NULL;

	return CWnd::PreCreateWindow(cs);
}


BEGIN_MESSAGE_MAP(CMainWnd, CWnd)
	ON_WM_NCPAINT()
	ON_WM_SYSCOMMAND()
	ON_WM_NCCALCSIZE()
END_MESSAGE_MAP()

void CMainWnd::OnNcPaint()
{
	return CWnd::OnNcPaint();
	CDC* pDC = GetWindowDC();
	CRect wnd;
	GetClientRect(&wnd);
	wnd.InflateRect(1, 1, 1, 1);
		
	pDC->MoveTo(wnd.left, wnd.top);
	pDC->LineTo(wnd.right, wnd.top);
	pDC->LineTo( wnd.right, wnd.bottom);
	pDC->LineTo(wnd.left, wnd.bottom);
	pDC->LineTo(wnd.left, wnd.top);
	ReleaseDC(pDC);
}

void CMainWnd::OnSysCommand(UINT nID, LPARAM lParam)
{
	switch (nID)
	{
	case SC_CLOSE :
		PostMessage(WM_QUIT);
		break;
	}

	CWnd::OnSysCommand(nID, lParam);
}

void CMainWnd::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	CRect rtOld = lpncsp->rgrc[0];
	int nfixframe = GetSystemMetrics(SM_CXFIXEDFRAME);
	int nCalc = nfixframe - 1;
	rtOld.InflateRect(nCalc, nCalc, nCalc, nCalc);
	lpncsp->rgrc[0] = rtOld;

	
	CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}
