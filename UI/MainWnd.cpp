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
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
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
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
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
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
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
// 		// �����˵�ѡ��:
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
// 		// TODO: �ڴ���������ͼ����...
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
// 			// �����豸������
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
