// UI.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "UI.h"

#include "MainWnd.h"

// �˴���ģ���а����ĺ�����ǰ������:

INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
CMainWnd*	g_mainWnd = NULL;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;
	
	g_mainWnd = new CMainWnd();
	
	g_mainWnd->Init(hInstance, SW_SHOW);
	/*g_mainWnd->CreateWnd();*/

 	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_UI));
 
 	// ����Ϣѭ��:
 	while (GetMessage(&msg, NULL, 0, 0))
 	{
 		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
 		{
 			TranslateMessage(&msg);
 			DispatchMessage(&msg);
 		}
 	}

	return (int) msg.wParam;
}





// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
