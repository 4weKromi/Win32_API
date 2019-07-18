
#include <tchar.h>
#include <windows.h>

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);  /* Declare Windows procedure */
TCHAR szClassName[ ] = _T("AppWindow");  /* Make the class name into a global variable */

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    HWND hwnd;               /* This handles window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND; /* Use Windows's default colour as the background of the window */

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                        /* Extended possibilites for variation */
           szClassName,              /* Classname */
           _T("Your Window Title"),  /* Title Text */
           WS_OVERLAPPEDWINDOW,      /* default window */
           CW_USEDEFAULT,            /* Windows decides the position */
           CW_USEDEFAULT,            /* where the window ends up on the screen */
           544,                      /* The programs width */
           375,                      /* and height in pixels */
           HWND_DESKTOP,             /* The window is a child-window to desktop */
           NULL,                     /* No menu */
           hThisInstance,            /* Program Instance handler */
           NULL                      /* No Window Creation data */
           );    
    ShowWindow (hwnd, nCmdShow);  /* Make the window visible on screen */
    
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);  /* Translate virtual-key messages into character messages */
        DispatchMessage(&messages);   /* Send message to WindowProcedure */
    }  
    return messages.wParam; /* The program return-value is 0 - The value that PostQuitMessage() gave */
}

/*  This function is called by the Windows function DispatchMessage()  */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message){                  /* handle the messages */
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                     
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
