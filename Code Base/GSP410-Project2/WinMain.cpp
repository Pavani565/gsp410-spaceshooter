#include <Windows.h>
#include <WindowsX.h>
#include "Definitions.h"
#include "DirectX.h"
#include "DirectInput.h"
#include "GameController.h"

// GLOBAL VARIABLES												//
HWND			g_hWnd;			// Window Handle				//
HINSTANCE		g_hInstance;	// Application Instance Handle	//
bool			g_bWindowed;	// Fullscreen Boolean			//
CDirectX		g_DX;			// DirectX Instance				//
CDirectInput*	g_DI;			// DirectInput Pointer			//
GameController	g_GC;			// GameController				//

// FUNCTIONS //

int WINAPI wWinMain(HINSTANCE hInstance,	// Application Handle					//
	HINSTANCE hPrevInstance,				// Previous Application Handle			//
	LPTSTR lpCmdLine,						// Long Pointer to Command Line String	//
	int lpCmdShow);							// Shows Value of Command				//

LRESULT CALLBACK WndProc(HWND hWnd,	// Window Handle			//
	UINT message,					// Incoming Message			//
	WPARAM wparam,					// Message Info				//
	LPARAM lparam);					// Additional Message Info	//

// INITIALIZE THE WINDOW //

void InitWindow(void)
{
	// Allocate a Block of Memory for the Window //
	WNDCLASSEX wndClass;  
	ZeroMemory(&wndClass, sizeof(wndClass));

	// Set up the Window //
	wndClass.cbSize			= sizeof(WNDCLASSEX);			// Size of Window Structure	//
	wndClass.lpfnWndProc	= (WNDPROC)WndProc;				// Message Callback			//
	wndClass.lpszClassName	= WINDOW_TITLE;					// Class Name				//
	wndClass.hInstance		= g_hInstance;					// Application Handle		//
	wndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);	// Default Cursor			//
	wndClass.hbrBackground	= (HBRUSH)(COLOR_WINDOWFRAME);	// Background Brush			//

	// Register a New Type of Window //
	RegisterClassEx(&wndClass);

	// Create the Window //
	g_hWnd = CreateWindowEx(
		NULL,
		WINDOW_CLASS,
		WINDOW_TITLE,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		g_hInstance,
		NULL);

	// Display the Window //
	ShowWindow(g_hWnd, SW_SHOW);
	UpdateWindow(g_hWnd);
}

// RUN THE MAIN LOOP //

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	g_hInstance = hInstance;	// Store Application Handle //
	g_bWindowed = WINDOWS_MODE;	// Full-Screen Mode	//

	// Initialize the Window //
	InitWindow();

	// MSG Structure to Catch Window Messages //
	MSG msg; 
	ZeroMemory(&msg, sizeof(msg));

	// Initialize DirectX //
	g_DX.InitDX(g_hWnd, g_hInstance, g_bWindowed);
	g_DI = CDirectInput::GetInstance(g_hInstance, g_hWnd);

	// Timer to find and pass in delta time //
	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	float secsPerCnt = 1.0f / (float)cntsPerSec;

	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);

	// Main Loop //
	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Get Time //
		__int64 currTimeStamp = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
		float dt = (currTimeStamp - prevTimeStamp) * secsPerCnt;

		// DirectX Update and Render Calls //
		g_DI->Update();
		g_GC.UpdateGame(dt);
		// g_DX.Update(dt); //
		g_DX.Render();

		prevTimeStamp = currTimeStamp;
	}

	// Shutdown DirectX //
	g_DI->Shutdown();
	g_DX.Shutdown();

	// Unregister Window //
	UnregisterClass(WINDOW_TITLE, g_hInstance);

	// Return Successful //
	return 0;
}

// MESSAGE COMMANDS //

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	// Attempt to Handle Messages //
	switch(message)
	{
	case (WM_PAINT):
		{
			::InvalidateRect(hWnd,NULL,TRUE);
		}		
		break;
	case(WM_DESTROY):
		{
			::PostQuitMessage(0); 
		}
		break;
	case(WM_KEYDOWN):
		{
			switch(wparam)
			{
			// Escape Closes Application //
			case VK_ESCAPE:
				{
					::PostQuitMessage(0);
				}
				break;
			}
		}
		break;
		/* A Note From Kevin
		// I researched how to do mouse input with the WndProc if we wanted to do this instead	//
		// I kind of like it, it is pretty clean, and it is correct. We would just need to		//
		// decide how we would want to get this data from way out here, to down in the game.	//
	case(WM_LBUTTONDOWN):
		{
			switch(wparam)
			{
			case MK_LBUTTON: // left click
				{
					int xPos = GET_X_LPARAM(lparam);
					int yPos = GET_Y_LPARAM(lparam);
				}
				break;
			case MK_LBUTTON | MK_CONTROL: // control + left click
				{
					int xPos = GET_X_LPARAM(lparam);
					int yPos = GET_Y_LPARAM(lparam);
				}
				break;
			case MK_LBUTTON | MK_SHIFT: // shift + left click
				{
					int xPos = GET_X_LPARAM(lparam);
					int yPos = GET_Y_LPARAM(lparam);
				}
				break;
			}
		}
		break;
		*/
	}
	// Pass to Default Handler //
	return DefWindowProc(hWnd, message, wparam, lparam);
}