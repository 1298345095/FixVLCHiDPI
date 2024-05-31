#include <windows.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char args[4096] = "";
    for (int i = 1; i < argc; ++i)
    {
        strcat(args, "\"");
        strcat(args, argv[i]);
        strcat(args, "\" ");
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char vlcPath[4096] = "";
    strcpy(vlcPath, argv[0]);
    *strrchr(vlcPath, '\\') = '\0';
    strcat(vlcPath, "\\vlc_invoke.exe");

    char environment[] = "QT_AUTO_SCREEN_SCALE_FACTOR=0\0QT_SCREEN_SCALE_FACTORS=1.5\0\0";
    if (!CreateProcess(vlcPath, args, NULL, NULL, FALSE,
                       CREATE_NEW_PROCESS_GROUP, &environment, NULL, &si, &pi))
    {
        return -1;
    }
    return 0;
}
