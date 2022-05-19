#include <stdio.h>
#include "windows.h"

int WINAPI WinMain(
    [[maybe_unused]] HINSTANCE hInst,
    [[maybe_unused]] HINSTANCE hPrevInst,
    LPSTR lpCmdLine,
    [[maybe_unused]] int nShowCmd)
{
    if (lpCmdLine != nullptr &&
        *lpCmdLine != '\0')
    {
        STARTUPINFO si{};
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);

        PROCESS_INFORMATION pi{};
        ZeroMemory(&pi, sizeof(pi));

        if (!CreateProcess(nullptr, lpCmdLine, nullptr, nullptr, FALSE, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi))
        {
            MessageBox(nullptr, "CreateProcess failed.", nullptr, MB_OK | MB_ICONERROR);
            return -1;
        }
        DWORD exitCode{ 0 };
        WaitForSingleObject(pi.hProcess, INFINITE);
        GetExitCodeProcess(pi.hProcess, &exitCode);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return exitCode;
    }
    MessageBox(nullptr, "Please specify program path as first command line argument.", nullptr, MB_OK | MB_ICONERROR);
    return -2;
}
