#include <windows.h>
#include <iostream>

int WIN_HACK() {
    const char* command = "powershell -Command \"slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX; slmgr /skms kms.digiboy.ir; slmgr /ato\"";
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    CreateProcess(NULL, (LPWSTR)command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

int MENU() {
    int choice;
    std::cout << "1. Activate Windows\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        WIN_HACK();
        std::cout << "Windows activated successfully.\n";
        break;
    case 2:
        std::cout << "Exiting...\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        MENU();
        break;
    }
    return 0;

}

int main() {
    MENU();
    return 0;
}
