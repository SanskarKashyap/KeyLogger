#include <iostream>
#include <string>

int main() {
    // Define the PowerShell code as a C++ string
    std::string psCode = "$message = 'Hello, world!'; Write-Output $message;";

    // Print the PowerShell code
    std::cout << "PowerShell code:\n" << psCode << "\n\n";

    // Execute the PowerShell code
    system(("powershell.exe -Command \"" + psCode + "\"").c_str());

    return 0;
}
