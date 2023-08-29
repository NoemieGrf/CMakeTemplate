#include <iostream>
#include <Windows.h>
#include <GL/GL.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // register window class
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = "SimpleOpenGLExample";

    if (!RegisterClass(&wc))
    {
        MessageBox(nullptr, "Failed to register the window class", "Error", MB_ICONERROR | MB_OK);
        return -1;
    }

    HWND hWnd = CreateWindow("SimpleOpenGLExample",
                             "Simple OpenGL Example",
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT,
                             CW_USEDEFAULT,
                             800, 600, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        MessageBox(NULL, "Failed to create the window", "Error", MB_ICONERROR | MB_OK);
        return -1;
    }

    // init openGL context
    PIXELFORMATDESCRIPTOR pfd =
            {
            sizeof(PIXELFORMATDESCRIPTOR),
            1,
            PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
            PFD_TYPE_RGBA,        // The kind of framebuffer.
            32,                   // Color depth of the framebuffer.
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            24,
            8,
            0
    };

    HDC hDC = GetDC(hWnd);
    GLuint pixelFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pixelFormat, &pfd);

    HGLRC hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);

    // set openGL viewport
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glViewport(0, 0, 800, 600);

    // render loop
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg = { nullptr };

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (msg.message == WM_QUIT)
            break;

        TranslateMessage(&msg);
        DispatchMessage(&msg);

        glClear(GL_COLOR_BUFFER_BIT);

        // 画一个彩色三角形
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.5f);
        glEnd();

        SwapBuffers(hDC);
    }

    // 释放资源
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hRC);
    ReleaseDC(hWnd, hDC);
    DestroyWindow(hWnd);

    return static_cast<int>(msg.wParam);
}