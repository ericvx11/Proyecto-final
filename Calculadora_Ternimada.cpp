#incluir <ventanas.h>
#incluir <cadena>
#incluir <iostream>

#define ID_BUTTON_SUM 1
#define ID_BUTTON_RES 2
#define ID_BUTTON_MUL 3
#define ID_BUTTON_DIV 4
#define ID_BUTTON_NOC 5


double GetNumberFromEdit(HWND hEdit){
    char buffer[256];
    GetWindowText(hEdit, buffer, 256);
    return atof(buffer);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	
	  switch (msg)
    {
    case WM_CREATE:
        hEdit1 = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
        hEdit2 = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 130, 20, 100, 20, hwnd, NULL, NULL, NULL);
        hEditRes = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY, 240, 20, 100, 20, hwnd, NULL, NULL, NULL);

        hAdd = CreateWindow("Button", " + ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 20, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_SUM, NULL, NULL);
        hSub = CreateWindow("Button", " - ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 110, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_RES, NULL, NULL);
        hMul = CreateWindow("Button", " X ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_MUL, NULL, NULL);
        hDiv = CreateWindow("Button", " / ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 290, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_DIV, NULL, NULL);
        hClr = CreateWindow("Button", "OtraVez", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 380, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_NOC, NULL, NULL);
        break;
	
}



// VENTANA GRAFICA
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow){
    const char CLASS_NAME[] = "Calculadora Proyecto";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);
    HWND hwnd = CreateWindow(CLASS_NAME, "Calculadora Proyecto", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 150, NULL, NULL, hInst, NULL);
    if (hwnd == NULL){
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
