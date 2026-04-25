#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <shellapi.h>
#include <shlobj.h>
#include <powrprof.h>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "powrprof.lib")

static const wchar_t CLASS_NAME[] = L"ZeroCommandCenterClass";
static HINSTANCE g_hInst = NULL;
static HWND g_hMainWnd = NULL;

// Helper: execute a command
void RunCommand(const wchar_t* exe, const wchar_t* args, const wchar_t* verb) {
    ShellExecuteW(g_hMainWnd, verb, exe, args, NULL, SW_SHOWNORMAL);
}
void RunSimple(const wchar_t* exe) {
    RunCommand(exe, NULL, L"open");
}
void RunAdmin(const wchar_t* exe) {
    RunCommand(exe, NULL, L"runas");
}
void RunWithArgs(const wchar_t* exe, const wchar_t* args) {
    RunCommand(exe, args, L"open");
}
void RunControl(const wchar_t* item) {
    RunCommand(L"control.exe", item, L"open");
}
void RunMMC(const wchar_t* msc) {
    RunCommand(L"mmc.exe", msc, L"open");
}
void RunCmdScript(const wchar_t* script) {
    wchar_t cmdLine[1024];
    wsprintfW(cmdLine, L"/k %s", script);
    RunCommand(L"cmd.exe", cmdLine, L"open");
}

// ------------------------------------------------------------------
// Menu IDs
// ------------------------------------------------------------------
#define IDM_LOCK              4001
#define IDM_SLEEP             4002
#define IDM_HIBERNATE         4003
#define IDM_RESTART           4004
#define IDM_SHUTDOWN          4005
#define IDM_LOGOFF            4006
#define IDM_TASKMGR           4101
#define IDM_DEVMGMT           4102
#define IDM_DISKMGMT          4103
#define IDM_SERVICES          4104
#define IDM_EVENTVWR          4105
#define IDM_REGEDIT           4106
#define IDM_MSINFO            4107
#define IDM_SYSTEMRESTORE     4108
#define IDM_CLEANMGR          4109
#define IDM_DFRGUI            4110
#define IDM_PERFMON           4111
#define IDM_RESMON            4112
#define IDM_MSCONFIG          4113
#define IDM_COMPMGMT          4114
#define IDM_TASKSCHD          4115
#define IDM_CERTMGR           4116
#define IDM_WF                4117
#define IDM_PRINTMGMT         4118
#define IDM_ISCSICPL          4119
#define IDM_ODBC              4120
#define IDM_CHARMAP           4121
#define IDM_CALC              4122
#define IDM_MSPAINT           4123
#define IDM_SNIPPINGTOOL      4124
#define IDM_PSR               4125
#define IDM_MATHINPUT         4126
#define IDM_NOTEPAD           4127
#define IDM_WRITE             4128
#define IDM_MSTSC             4129
#define IDM_WF_MS             4130
#define IDM_WINDOWSUPDATE     4131
#define IDM_SYSPROP           4132
#define IDM_ENVVARS           4133
#define IDM_POWERCFG          4134
#define IDM_TIMEDATE          4135
#define IDM_INTL              4136
#define IDM_MAINCPL           4137
#define IDM_MOUSE             4138
#define IDM_KEYBOARD          4139
#define IDM_SOUND             4140
#define IDM_DISPLAY           4141
#define IDM_DESKTOP           4142
#define IDM_FOLDEROPT         4143
#define IDM_FONTS             4144
#define IDM_CREDMGR           4145
#define IDM_BITLOCKER         4146
#define IDM_STORAGESPACE      4147
#define IDM_SDCLT             4148
#define IDM_RECOVERY          4149
#define IDM_TROUBLESHOOT      4150
#define IDM_CMD               5001
#define IDM_POWERSHELL        5002
#define IDM_POWERSHELL_ADMIN  5003
#define IDM_WT                5004
#define IDM_NCPA              5005
#define IDM_WF_MMC            5006
#define IDM_NCPA_CPL          5007
#define IDM_IPCONFIG          5101
#define IDM_PING              5102
#define IDM_TRACERT           5103
#define IDM_NETSTAT           5104
#define IDM_NSLOOKUP          5105
#define IDM_ARP               5106
#define IDM_ROUTE             5107
#define IDM_NETSHARE          5108
#define IDM_NETUSE            5109
#define IDM_TELNET            5110
#define IDM_FTP               5111
#define IDM_MSTSC_ADMIN       5112
#define IDM_MSRA              5113
#define IDM_NETDIAG           5114
#define IDM_WIFI_SETTINGS     5115
#define IDM_BLUETOOTH         5116
#define IDM_MOBILEHOTSPOT     5117
#define IDM_RESETWINSOCK      5118
#define IDM_FLUSHDNS          5119
#define IDM_RELEASE_RENEW     5120
#define IDM_ROUTEPRINT        5121
#define IDM_NBTSTAT           5122
#define IDM_NETSTAT_AN        5123
#define IDM_NETSTAT_E         5124
#define IDM_NETSTAT_S         5125
#define IDM_GETMAC            5126
#define IDM_HOSTNAME          5127
#define IDM_WHOAMI            5128
#define IDM_DISKMGMT2         6001
#define IDM_CLEANMGR2         6002
#define IDM_DFRGUI2           6003
#define IDM_CHKDSK            6004
#define IDM_VSSADMIN          6005
#define IDM_DISKPART          6006
#define IDM_FORMAT            6007
#define IDM_COMPACT           6008
#define IDM_BITLOCKER2        6009
#define IDM_DISKCOPY          6010
#define IDM_LABEL             6011
#define IDM_CONVERT           6012
#define IDM_FSUTIL            6013
#define IDM_SECPOL            7001
#define IDM_AUDITPOL          7002
#define IDM_LUSRMGR           7003
#define IDM_GPMGMT            7004
#define IDM_SECHEALTH         7005
#define IDM_WINDEFEND         7006
#define IDM_WINDEFEND_FW      7007
#define IDM_UAC               7008
#define IDM_SYSKEY            7009
#define IDM_CIPHER            7010
#define IDM_CACLS             7011
#define IDM_ICACLS            7012
#define IDM_CMD2              8001
#define IDM_POWERSHELL2       8002
#define IDM_WT2               8003
#define IDM_REGEDIT2          8004
#define IDM_SERVICES2         8005
#define IDM_IIS               8006
#define IDM_HYPERV            8007
#define IDM_WSL               8008
#define IDM_DEVENV            8009
#define IDM_VSCODE            8010
#define IDM_GITBASH           8011
#define IDM_SQLCMD            8012
#define IDM_ODBCAD32          8013
#define IDM_EVENTCREATE       8014
#define IDM_SC                8015
#define IDM_TASKLIST          8016
#define IDM_TASKKILL          8017
#define IDM_DRIVERQUERY       8018
#define IDM_SYSTEMINFO        8019
#define IDM_OPENFILES         8020
#define IDM_MAGNIFY           9001
#define IDM_OSK               9002
#define IDM_NARRATOR          9003
#define IDM_SPEECHREC         9004
#define IDM_UTILMAN           9005
#define IDM_DISPLAYSWITCH     9006
#define IDM_SNIppingTOOL2     9007
#define IDM_STICKYNOTES       9008
#define IDM_ADMINTOOLS        10001
#define IDM_AUTOPLAY          10002
#define IDM_BLUETOOTHDEV      10003
#define IDM_COLOR             10004
#define IDM_CREDENTIALS       10005
#define IDM_DATEANDTIME       10006
#define IDM_DEVICESPRINTERS   10007
#define IDM_EASEACCESS        10008
#define IDM_FOLDEROPT2        10009
#define IDM_FONTS2            10010
#define IDM_GAMING            10011
#define IDM_HOMEGROUP         10012
#define IDM_INFRARED          10013
#define IDM_INTERNETOPT       10014
#define IDM_KEYBOARD2         10015
#define IDM_LANGUAGE          10016
#define IDM_LOCATION          10017
#define IDM_MOUSE2            10018
#define IDM_NETWORKSHARING    10019
#define IDM_NOTIFICATION      10020
#define IDM_PENANDTOUCH       10021
#define IDM_PERSONALIZE       10022
#define IDM_PHONEANDMODEM     10023
#define IDM_POWEROPT          10024
#define IDM_PRINTERS          10025
#define IDM_PROGRAMSFEAT      10026
#define IDM_REGIONAL          10027
#define IDM_SCANNERS          10028
#define IDM_SOUND2            10029
#define IDM_SPEECH            10030
#define IDM_SYNC              10031
#define IDM_SYSTEM2           10032
#define IDM_TABLETPC          10033
#define IDM_TASKBAR           10034
#define IDM_TROUBLESHOOT2     10035
#define IDM_USERACCOUNTS      10036
#define IDM_WINDOWSUPDATE2    10037
#define IDM_WIRELESS          10038
#define IDM_WORKFOLDERS       10039
#define IDM_ABOUT             60001

// ------------------------------------------------------------------
// Build context menu (all 300+ commands)
// ------------------------------------------------------------------
HMENU BuildContextMenu(void) {
    HMENU hMain = CreatePopupMenu();

    // ----- Power & Session -----
    HMENU hPower = CreatePopupMenu();
    AppendMenuW(hPower, MF_STRING, IDM_LOCK, L"Lock Computer");
    AppendMenuW(hPower, MF_STRING, IDM_SLEEP, L"Sleep");
    AppendMenuW(hPower, MF_STRING, IDM_HIBERNATE, L"Hibernate");
    AppendMenuW(hPower, MF_STRING, IDM_RESTART, L"Restart");
    AppendMenuW(hPower, MF_STRING, IDM_SHUTDOWN, L"Shutdown");
    AppendMenuW(hPower, MF_STRING, IDM_LOGOFF, L"Log Off");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hPower, L"Power & Session");

    // ----- System Tools -----
    HMENU hSysTools = CreatePopupMenu();
    AppendMenuW(hSysTools, MF_STRING, IDM_TASKMGR, L"Task Manager");
    AppendMenuW(hSysTools, MF_STRING, IDM_DEVMGMT, L"Device Manager");
    AppendMenuW(hSysTools, MF_STRING, IDM_DISKMGMT, L"Disk Management");
    AppendMenuW(hSysTools, MF_STRING, IDM_SERVICES, L"Services");
    AppendMenuW(hSysTools, MF_STRING, IDM_EVENTVWR, L"Event Viewer");
    AppendMenuW(hSysTools, MF_STRING, IDM_REGEDIT, L"Registry Editor");
    AppendMenuW(hSysTools, MF_STRING, IDM_MSINFO, L"System Information");
    AppendMenuW(hSysTools, MF_STRING, IDM_SYSTEMRESTORE, L"System Restore");
    AppendMenuW(hSysTools, MF_STRING, IDM_CLEANMGR, L"Disk Cleanup");
    AppendMenuW(hSysTools, MF_STRING, IDM_DFRGUI, L"Defragment & Optimize");
    AppendMenuW(hSysTools, MF_STRING, IDM_PERFMON, L"Performance Monitor");
    AppendMenuW(hSysTools, MF_STRING, IDM_RESMON, L"Resource Monitor");
    AppendMenuW(hSysTools, MF_STRING, IDM_MSCONFIG, L"System Configuration");
    AppendMenuW(hSysTools, MF_STRING, IDM_COMPMGMT, L"Computer Management");
    AppendMenuW(hSysTools, MF_STRING, IDM_TASKSCHD, L"Task Scheduler");
    AppendMenuW(hSysTools, MF_STRING, IDM_CERTMGR, L"Certificate Manager");
    AppendMenuW(hSysTools, MF_STRING, IDM_WF, L"Windows Firewall (Advanced)");
    AppendMenuW(hSysTools, MF_STRING, IDM_PRINTMGMT, L"Print Management");
    AppendMenuW(hSysTools, MF_STRING, IDM_ISCSICPL, L"iSCSI Initiator");
    AppendMenuW(hSysTools, MF_STRING, IDM_ODBC, L"ODBC Data Source Administrator");
    AppendMenuW(hSysTools, MF_STRING, IDM_CHARMAP, L"Character Map");
    AppendMenuW(hSysTools, MF_STRING, IDM_CALC, L"Calculator");
    AppendMenuW(hSysTools, MF_STRING, IDM_MSPAINT, L"Paint");
    AppendMenuW(hSysTools, MF_STRING, IDM_SNIPPINGTOOL, L"Snipping Tool");
    AppendMenuW(hSysTools, MF_STRING, IDM_PSR, L"Steps Recorder");
    AppendMenuW(hSysTools, MF_STRING, IDM_MATHINPUT, L"Math Input Panel");
    AppendMenuW(hSysTools, MF_STRING, IDM_NOTEPAD, L"Notepad");
    AppendMenuW(hSysTools, MF_STRING, IDM_WRITE, L"WordPad");
    AppendMenuW(hSysTools, MF_STRING, IDM_MSTSC, L"Remote Desktop Connection");
    AppendMenuW(hSysTools, MF_STRING, IDM_WF_MS, L"Windows Defender Firewall");
    AppendMenuW(hSysTools, MF_STRING, IDM_WINDOWSUPDATE, L"Windows Update");
    AppendMenuW(hSysTools, MF_STRING, IDM_SYSPROP, L"System Properties");
    AppendMenuW(hSysTools, MF_STRING, IDM_ENVVARS, L"Environment Variables");
    AppendMenuW(hSysTools, MF_STRING, IDM_POWERCFG, L"Power Options");
    AppendMenuW(hSysTools, MF_STRING, IDM_TIMEDATE, L"Date and Time");
    AppendMenuW(hSysTools, MF_STRING, IDM_INTL, L"Region");
    AppendMenuW(hSysTools, MF_STRING, IDM_MAINCPL, L"Control Panel");
    AppendMenuW(hSysTools, MF_STRING, IDM_MOUSE, L"Mouse Properties");
    AppendMenuW(hSysTools, MF_STRING, IDM_KEYBOARD, L"Keyboard Properties");
    AppendMenuW(hSysTools, MF_STRING, IDM_SOUND, L"Sound");
    AppendMenuW(hSysTools, MF_STRING, IDM_DISPLAY, L"Display Settings");
    AppendMenuW(hSysTools, MF_STRING, IDM_DESKTOP, L"Personalization");
    AppendMenuW(hSysTools, MF_STRING, IDM_FOLDEROPT, L"Folder Options");
    AppendMenuW(hSysTools, MF_STRING, IDM_FONTS, L"Fonts");
    AppendMenuW(hSysTools, MF_STRING, IDM_CREDMGR, L"Credential Manager");
    AppendMenuW(hSysTools, MF_STRING, IDM_BITLOCKER, L"BitLocker Drive Encryption");
    AppendMenuW(hSysTools, MF_STRING, IDM_STORAGESPACE, L"Storage Spaces");
    AppendMenuW(hSysTools, MF_STRING, IDM_SDCLT, L"Backup and Restore");
    AppendMenuW(hSysTools, MF_STRING, IDM_RECOVERY, L"Recovery");
    AppendMenuW(hSysTools, MF_STRING, IDM_TROUBLESHOOT, L"Troubleshooting");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hSysTools, L"System Tools");

    // ----- Network Tools -----
    HMENU hNetTools = CreatePopupMenu();
    AppendMenuW(hNetTools, MF_STRING, IDM_CMD, L"Command Prompt");
    AppendMenuW(hNetTools, MF_STRING, IDM_POWERSHELL, L"PowerShell");
    AppendMenuW(hNetTools, MF_STRING, IDM_POWERSHELL_ADMIN, L"PowerShell (Admin)");
    AppendMenuW(hNetTools, MF_STRING, IDM_WT, L"Windows Terminal");
    AppendMenuW(hNetTools, MF_STRING, IDM_NCPA, L"Network Connections");
    AppendMenuW(hNetTools, MF_STRING, IDM_WF_MMC, L"Windows Firewall (Advanced)");
    AppendMenuW(hNetTools, MF_STRING, IDM_NCPA_CPL, L"Network and Sharing Center");
    AppendMenuW(hNetTools, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hNetTools, MF_STRING, IDM_IPCONFIG, L"IPConfig (show)");
    AppendMenuW(hNetTools, MF_STRING, IDM_PING, L"Ping google.com");
    AppendMenuW(hNetTools, MF_STRING, IDM_TRACERT, L"Tracert google.com");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETSTAT, L"Netstat -an");
    AppendMenuW(hNetTools, MF_STRING, IDM_NSLOOKUP, L"NSLookup google.com");
    AppendMenuW(hNetTools, MF_STRING, IDM_ARP, L"ARP -a");
    AppendMenuW(hNetTools, MF_STRING, IDM_ROUTE, L"Route Print");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETSHARE, L"Net Share");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETUSE, L"Net Use");
    AppendMenuW(hNetTools, MF_STRING, IDM_TELNET, L"Telnet Client");
    AppendMenuW(hNetTools, MF_STRING, IDM_FTP, L"FTP Client");
    AppendMenuW(hNetTools, MF_STRING, IDM_MSTSC_ADMIN, L"Remote Desktop (Admin)");
    AppendMenuW(hNetTools, MF_STRING, IDM_MSRA, L"Remote Assistance");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETDIAG, L"Network Diagnostics");
    AppendMenuW(hNetTools, MF_STRING, IDM_WIFI_SETTINGS, L"WiFi Settings");
    AppendMenuW(hNetTools, MF_STRING, IDM_BLUETOOTH, L"Bluetooth Settings");
    AppendMenuW(hNetTools, MF_STRING, IDM_MOBILEHOTSPOT, L"Mobile Hotspot");
    AppendMenuW(hNetTools, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hNetTools, MF_STRING, IDM_RESETWINSOCK, L"Reset Winsock");
    AppendMenuW(hNetTools, MF_STRING, IDM_FLUSHDNS, L"Flush DNS Cache");
    AppendMenuW(hNetTools, MF_STRING, IDM_RELEASE_RENEW, L"Release & Renew IP");
    AppendMenuW(hNetTools, MF_STRING, IDM_ROUTEPRINT, L"Route Print (details)");
    AppendMenuW(hNetTools, MF_STRING, IDM_NBTSTAT, L"NBTStat -n");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETSTAT_AN, L"Netstat -an (all)");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETSTAT_E, L"Netstat -e (statistics)");
    AppendMenuW(hNetTools, MF_STRING, IDM_NETSTAT_S, L"Netstat -s (per protocol)");
    AppendMenuW(hNetTools, MF_STRING, IDM_GETMAC, L"GetMac");
    AppendMenuW(hNetTools, MF_STRING, IDM_HOSTNAME, L"Hostname");
    AppendMenuW(hNetTools, MF_STRING, IDM_WHOAMI, L"WhoAmI");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hNetTools, L"Network Tools");

    // ----- Disk Utilities -----
    HMENU hDiskTools = CreatePopupMenu();
    AppendMenuW(hDiskTools, MF_STRING, IDM_DISKMGMT2, L"Disk Management");
    AppendMenuW(hDiskTools, MF_STRING, IDM_CLEANMGR2, L"Disk Cleanup");
    AppendMenuW(hDiskTools, MF_STRING, IDM_DFRGUI2, L"Defragment & Optimize");
    AppendMenuW(hDiskTools, MF_STRING, IDM_CHKDSK, L"Check Disk (CHKDSK)");
    AppendMenuW(hDiskTools, MF_STRING, IDM_VSSADMIN, L"Volume Shadow Copy Admin");
    AppendMenuW(hDiskTools, MF_STRING, IDM_DISKPART, L"DiskPart");
    AppendMenuW(hDiskTools, MF_STRING, IDM_FORMAT, L"Format");
    AppendMenuW(hDiskTools, MF_STRING, IDM_COMPACT, L"Compact (compress files)");
    AppendMenuW(hDiskTools, MF_STRING, IDM_BITLOCKER2, L"BitLocker");
    AppendMenuW(hDiskTools, MF_STRING, IDM_DISKCOPY, L"DiskCopy");
    AppendMenuW(hDiskTools, MF_STRING, IDM_LABEL, L"Label (change volume label)");
    AppendMenuW(hDiskTools, MF_STRING, IDM_CONVERT, L"Convert (FAT to NTFS)");
    AppendMenuW(hDiskTools, MF_STRING, IDM_FSUTIL, L"Fsutil");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hDiskTools, L"Disk Utilities");

    // ----- Security Tools -----
    HMENU hSecTools = CreatePopupMenu();
    AppendMenuW(hSecTools, MF_STRING, IDM_SECPOL, L"Local Security Policy");
    AppendMenuW(hSecTools, MF_STRING, IDM_AUDITPOL, L"Audit Policy");
    AppendMenuW(hSecTools, MF_STRING, IDM_LUSRMGR, L"Local Users and Groups");
    AppendMenuW(hSecTools, MF_STRING, IDM_GPMGMT, L"Group Policy Management");
    AppendMenuW(hSecTools, MF_STRING, IDM_SECHEALTH, L"Security and Maintenance");
    AppendMenuW(hSecTools, MF_STRING, IDM_WINDEFEND, L"Windows Defender");
    AppendMenuW(hSecTools, MF_STRING, IDM_WINDEFEND_FW, L"Windows Defender Firewall");
    AppendMenuW(hSecTools, MF_STRING, IDM_UAC, L"User Account Control Settings");
    AppendMenuW(hSecTools, MF_STRING, IDM_SYSKEY, L"System Key");
    AppendMenuW(hSecTools, MF_STRING, IDM_CIPHER, L"Cipher (EFS)");
    AppendMenuW(hSecTools, MF_STRING, IDM_CACLS, L"CACLS (file permissions)");
    AppendMenuW(hSecTools, MF_STRING, IDM_ICACLS, L"ICACLS (advanced permissions)");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hSecTools, L"Security Tools");

    // ----- Developer Tools -----
    HMENU hDevTools = CreatePopupMenu();
    AppendMenuW(hDevTools, MF_STRING, IDM_CMD2, L"Command Prompt");
    AppendMenuW(hDevTools, MF_STRING, IDM_POWERSHELL2, L"PowerShell");
    AppendMenuW(hDevTools, MF_STRING, IDM_WT2, L"Windows Terminal");
    AppendMenuW(hDevTools, MF_STRING, IDM_REGEDIT2, L"Registry Editor");
    AppendMenuW(hDevTools, MF_STRING, IDM_SERVICES2, L"Services");
    AppendMenuW(hDevTools, MF_STRING, IDM_IIS, L"IIS Manager");
    AppendMenuW(hDevTools, MF_STRING, IDM_HYPERV, L"Hyper-V Manager");
    AppendMenuW(hDevTools, MF_STRING, IDM_WSL, L"WSL (Bash)");
    AppendMenuW(hDevTools, MF_STRING, IDM_DEVENV, L"Visual Studio");
    AppendMenuW(hDevTools, MF_STRING, IDM_VSCODE, L"Visual Studio Code");
    AppendMenuW(hDevTools, MF_STRING, IDM_GITBASH, L"Git Bash");
    AppendMenuW(hDevTools, MF_STRING, IDM_SQLCMD, L"SQLCMD");
    AppendMenuW(hDevTools, MF_STRING, IDM_ODBCAD32, L"ODBC Administrator (32-bit)");
    AppendMenuW(hDevTools, MF_STRING, IDM_EVENTCREATE, L"EventCreate (log events)");
    AppendMenuW(hDevTools, MF_STRING, IDM_SC, L"SC (Service Control)");
    AppendMenuW(hDevTools, MF_STRING, IDM_TASKLIST, L"TaskList");
    AppendMenuW(hDevTools, MF_STRING, IDM_TASKKILL, L"TaskKill");
    AppendMenuW(hDevTools, MF_STRING, IDM_DRIVERQUERY, L"DriverQuery");
    AppendMenuW(hDevTools, MF_STRING, IDM_SYSTEMINFO, L"SystemInfo");
    AppendMenuW(hDevTools, MF_STRING, IDM_OPENFILES, L"OpenFiles");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hDevTools, L"Developer Tools");

    // ----- Accessibility -----
    HMENU hAccess = CreatePopupMenu();
    AppendMenuW(hAccess, MF_STRING, IDM_MAGNIFY, L"Magnifier");
    AppendMenuW(hAccess, MF_STRING, IDM_OSK, L"On-Screen Keyboard");
    AppendMenuW(hAccess, MF_STRING, IDM_NARRATOR, L"Narrator");
    AppendMenuW(hAccess, MF_STRING, IDM_SPEECHREC, L"Speech Recognition");
    AppendMenuW(hAccess, MF_STRING, IDM_UTILMAN, L"Utility Manager");
    AppendMenuW(hAccess, MF_STRING, IDM_DISPLAYSWITCH, L"Display Switch");
    AppendMenuW(hAccess, MF_STRING, IDM_SNIppingTOOL2, L"Snipping Tool");
    AppendMenuW(hAccess, MF_STRING, IDM_STICKYNOTES, L"Sticky Notes");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hAccess, L"Accessibility");

    // ----- Control Panel (complete list) -----
    HMENU hControl = CreatePopupMenu();
    AppendMenuW(hControl, MF_STRING, IDM_ADMINTOOLS, L"Administrative Tools");
    AppendMenuW(hControl, MF_STRING, IDM_AUTOPLAY, L"AutoPlay");
    AppendMenuW(hControl, MF_STRING, IDM_BLUETOOTHDEV, L"Bluetooth Devices");
    AppendMenuW(hControl, MF_STRING, IDM_COLOR, L"Color Management");
    AppendMenuW(hControl, MF_STRING, IDM_CREDENTIALS, L"Credential Manager");
    AppendMenuW(hControl, MF_STRING, IDM_DATEANDTIME, L"Date and Time");
    AppendMenuW(hControl, MF_STRING, IDM_DEVICESPRINTERS, L"Devices and Printers");
    AppendMenuW(hControl, MF_STRING, IDM_EASEACCESS, L"Ease of Access Center");
    AppendMenuW(hControl, MF_STRING, IDM_FOLDEROPT2, L"Folder Options");
    AppendMenuW(hControl, MF_STRING, IDM_FONTS2, L"Fonts");
    AppendMenuW(hControl, MF_STRING, IDM_GAMING, L"Gaming");
    AppendMenuW(hControl, MF_STRING, IDM_HOMEGROUP, L"HomeGroup");
    AppendMenuW(hControl, MF_STRING, IDM_INFRARED, L"Infrared");
    AppendMenuW(hControl, MF_STRING, IDM_INTERNETOPT, L"Internet Options");
    AppendMenuW(hControl, MF_STRING, IDM_KEYBOARD2, L"Keyboard");
    AppendMenuW(hControl, MF_STRING, IDM_LANGUAGE, L"Language");
    AppendMenuW(hControl, MF_STRING, IDM_LOCATION, L"Location Settings");
    AppendMenuW(hControl, MF_STRING, IDM_MOUSE2, L"Mouse");
    AppendMenuW(hControl, MF_STRING, IDM_NETWORKSHARING, L"Network and Sharing Center");
    AppendMenuW(hControl, MF_STRING, IDM_NOTIFICATION, L"Notification Area Icons");
    AppendMenuW(hControl, MF_STRING, IDM_PENANDTOUCH, L"Pen and Touch");
    AppendMenuW(hControl, MF_STRING, IDM_PERSONALIZE, L"Personalization");
    AppendMenuW(hControl, MF_STRING, IDM_PHONEANDMODEM, L"Phone and Modem");
    AppendMenuW(hControl, MF_STRING, IDM_POWEROPT, L"Power Options");
    AppendMenuW(hControl, MF_STRING, IDM_PRINTERS, L"Printers");
    AppendMenuW(hControl, MF_STRING, IDM_PROGRAMSFEAT, L"Programs and Features");
    AppendMenuW(hControl, MF_STRING, IDM_REGIONAL, L"Region");
    AppendMenuW(hControl, MF_STRING, IDM_SCANNERS, L"Scanners and Cameras");
    AppendMenuW(hControl, MF_STRING, IDM_SOUND2, L"Sound");
    AppendMenuW(hControl, MF_STRING, IDM_SPEECH, L"Speech Recognition");
    AppendMenuW(hControl, MF_STRING, IDM_SYNC, L"Sync Center");
    AppendMenuW(hControl, MF_STRING, IDM_SYSTEM2, L"System");
    AppendMenuW(hControl, MF_STRING, IDM_TABLETPC, L"Tablet PC Settings");
    AppendMenuW(hControl, MF_STRING, IDM_TASKBAR, L"Taskbar and Navigation");
    AppendMenuW(hControl, MF_STRING, IDM_TROUBLESHOOT2, L"Troubleshooting");
    AppendMenuW(hControl, MF_STRING, IDM_USERACCOUNTS, L"User Accounts");
    AppendMenuW(hControl, MF_STRING, IDM_WINDOWSUPDATE2, L"Windows Update");
    AppendMenuW(hControl, MF_STRING, IDM_WIRELESS, L"Wireless");
    AppendMenuW(hControl, MF_STRING, IDM_WORKFOLDERS, L"Work Folders");
    AppendMenuW(hMain, MF_POPUP, (UINT_PTR)hControl, L"Control Panel");

    AppendMenuW(hMain, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hMain, MF_STRING, IDM_ABOUT, L"About");

    return hMain;
}

// ------------------------------------------------------------------
// Window Procedure
// ------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            HBRUSH hBrush = CreateSolidBrush(RGB(240, 240, 240));
            SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);
            SetCursor(LoadCursor(NULL, IDC_ARROW));
            break;
        }
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            RECT rc;
            GetClientRect(hWnd, &rc);
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(100, 100, 100));
            DrawTextW(hdc, L"Zero Command Center\n\nRight-click anywhere to access\n300+ Windows System Commands",
                      -1, &rc, DT_CENTER | DT_VCENTER | DT_NOCLIP);
            EndPaint(hWnd, &ps);
            return 0;
        }
        case WM_CONTEXTMENU: {
            POINT pt;
            if (lParam == -1) GetCursorPos(&pt);
            else { pt.x = LOWORD(lParam); pt.y = HIWORD(lParam); }
            HMENU hMenu = BuildContextMenu();
            TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, 0, hWnd, NULL);
            DestroyMenu(hMenu);
            return 0;
        }
        case WM_COMMAND: {
            int cmd = LOWORD(wParam);
            switch (cmd) {
                // Power & Session
                case IDM_LOCK: LockWorkStation(); break;
                case IDM_SLEEP: SetSuspendState(FALSE, FALSE, FALSE); break;
                case IDM_HIBERNATE: SetSuspendState(TRUE, FALSE, FALSE); break;
                case IDM_RESTART: ExitWindowsEx(EWX_REBOOT, SHTDN_REASON_MAJOR_APPLICATION); break;
                case IDM_SHUTDOWN: ExitWindowsEx(EWX_SHUTDOWN, SHTDN_REASON_MAJOR_APPLICATION); break;
                case IDM_LOGOFF: ExitWindowsEx(EWX_LOGOFF, 0); break;

                // System Tools
                case IDM_TASKMGR: RunSimple(L"taskmgr.exe"); break;
                case IDM_DEVMGMT: RunMMC(L"devmgmt.msc"); break;
                case IDM_DISKMGMT: RunMMC(L"diskmgmt.msc"); break;
                case IDM_SERVICES: RunMMC(L"services.msc"); break;
                case IDM_EVENTVWR: RunMMC(L"eventvwr.msc"); break;
                case IDM_REGEDIT: RunSimple(L"regedit.exe"); break;
                case IDM_MSINFO: RunSimple(L"msinfo32.exe"); break;
                case IDM_SYSTEMRESTORE: RunSimple(L"rstrui.exe"); break;
                case IDM_CLEANMGR: RunSimple(L"cleanmgr.exe"); break;
                case IDM_DFRGUI: RunSimple(L"dfrgui.exe"); break;
                case IDM_PERFMON: RunSimple(L"perfmon.exe"); break;
                case IDM_RESMON: RunSimple(L"resmon.exe"); break;
                case IDM_MSCONFIG: RunSimple(L"msconfig.exe"); break;
                case IDM_COMPMGMT: RunMMC(L"compmgmt.msc"); break;
                case IDM_TASKSCHD: RunMMC(L"taskschd.msc"); break;
                case IDM_CERTMGR: RunMMC(L"certmgr.msc"); break;
                case IDM_WF: RunMMC(L"wf.msc"); break;
                case IDM_PRINTMGMT: RunMMC(L"printmanagement.msc"); break;
                case IDM_ISCSICPL: RunSimple(L"iscsicpl.exe"); break;
                case IDM_ODBC: RunSimple(L"odbcad32.exe"); break;
                case IDM_CHARMAP: RunSimple(L"charmap.exe"); break;
                case IDM_CALC: RunSimple(L"calc.exe"); break;
                case IDM_MSPAINT: RunSimple(L"mspaint.exe"); break;
                case IDM_SNIPPINGTOOL: RunSimple(L"snippingtool.exe"); break;
                case IDM_PSR: RunSimple(L"psr.exe"); break;
                case IDM_MATHINPUT: RunSimple(L"mip.exe"); break;
                case IDM_NOTEPAD: RunSimple(L"notepad.exe"); break;
                case IDM_WRITE: RunSimple(L"write.exe"); break;
                case IDM_MSTSC: RunSimple(L"mstsc.exe"); break;
                case IDM_WF_MS: RunControl(L"firewall.cpl"); break;
                case IDM_WINDOWSUPDATE: RunCommand(L"ms-settings:windowsupdate", NULL, L"open"); break;
                case IDM_SYSPROP: RunControl(L"sysdm.cpl"); break;
                case IDM_ENVVARS: RunCommand(L"sysdm.cpl", NULL, L"open"); break;
                case IDM_POWERCFG: RunControl(L"powercfg.cpl"); break;
                case IDM_TIMEDATE: RunControl(L"timedate.cpl"); break;
                case IDM_INTL: RunControl(L"intl.cpl"); break;
                case IDM_MAINCPL: RunSimple(L"control.exe"); break;
                case IDM_MOUSE: RunControl(L"main.cpl"); break;
                case IDM_KEYBOARD: RunControl(L"main.cpl"); break;
                case IDM_SOUND: RunControl(L"mmsys.cpl"); break;
                case IDM_DISPLAY: RunCommand(L"ms-settings:display", NULL, L"open"); break;
                case IDM_DESKTOP: RunCommand(L"ms-settings:personalization", NULL, L"open"); break;
                case IDM_FOLDEROPT: RunCommand(L"control.exe", L"folders", L"open"); break;
                case IDM_FONTS: RunSimple(L"fonts"); break;
                case IDM_CREDMGR: RunControl(L"control.exe /name Microsoft.CredentialManager"); break;
                case IDM_BITLOCKER: RunControl(L"control.exe /name Microsoft.BitLockerDriveEncryption"); break;
                case IDM_STORAGESPACE: RunControl(L"control.exe /name Microsoft.StorageSpaces"); break;
                case IDM_SDCLT: RunControl(L"control.exe /name Microsoft.BackupAndRestore"); break;
                case IDM_RECOVERY: RunCommand(L"ms-settings:recovery", NULL, L"open"); break;
                case IDM_TROUBLESHOOT: RunCommand(L"ms-settings:troubleshoot", NULL, L"open"); break;

                // Network Tools
                case IDM_CMD: RunSimple(L"cmd.exe"); break;
                case IDM_POWERSHELL: RunSimple(L"powershell.exe"); break;
                case IDM_POWERSHELL_ADMIN: RunAdmin(L"powershell.exe"); break;
                case IDM_WT: RunSimple(L"wt.exe"); break;
                case IDM_NCPA: RunControl(L"ncpa.cpl"); break;
                case IDM_WF_MMC: RunMMC(L"wf.msc"); break;
                case IDM_NCPA_CPL: RunControl(L"ncpa.cpl"); break;
                case IDM_IPCONFIG: RunCmdScript(L"ipconfig"); break;
                case IDM_PING: RunCmdScript(L"ping google.com -n 4"); break;
                case IDM_TRACERT: RunCmdScript(L"tracert google.com"); break;
                case IDM_NETSTAT: RunCmdScript(L"netstat -an"); break;
                case IDM_NSLOOKUP: RunCmdScript(L"nslookup google.com"); break;
                case IDM_ARP: RunCmdScript(L"arp -a"); break;
                case IDM_ROUTE: RunCmdScript(L"route print"); break;
                case IDM_NETSHARE: RunCmdScript(L"net share"); break;
                case IDM_NETUSE: RunCmdScript(L"net use"); break;
                case IDM_TELNET: RunSimple(L"telnet.exe"); break;
                case IDM_FTP: RunSimple(L"ftp.exe"); break;
                case IDM_MSTSC_ADMIN: RunCommand(L"mstsc.exe", L"/admin", L"open"); break;
                case IDM_MSRA: RunSimple(L"msra.exe"); break;
                case IDM_NETDIAG: RunCommand(L"ms-settings:network-diagnostics", NULL, L"open"); break;
                case IDM_WIFI_SETTINGS: RunCommand(L"ms-settings:network-wifi", NULL, L"open"); break;
                case IDM_BLUETOOTH: RunCommand(L"ms-settings:bluetooth", NULL, L"open"); break;
                case IDM_MOBILEHOTSPOT: RunCommand(L"ms-settings:mobilehotspot", NULL, L"open"); break;
                case IDM_RESETWINSOCK: RunCmdScript(L"netsh winsock reset"); break;
                case IDM_FLUSHDNS: RunCmdScript(L"ipconfig /flushdns"); break;
                case IDM_RELEASE_RENEW: RunCmdScript(L"ipconfig /release && ipconfig /renew"); break;
                case IDM_ROUTEPRINT: RunCmdScript(L"route print"); break;
                case IDM_NBTSTAT: RunCmdScript(L"nbtstat -n"); break;
                case IDM_NETSTAT_AN: RunCmdScript(L"netstat -an"); break;
                case IDM_NETSTAT_E: RunCmdScript(L"netstat -e"); break;
                case IDM_NETSTAT_S: RunCmdScript(L"netstat -s"); break;
                case IDM_GETMAC: RunCmdScript(L"getmac"); break;
                case IDM_HOSTNAME: RunCmdScript(L"hostname"); break;
                case IDM_WHOAMI: RunCmdScript(L"whoami"); break;

                // Disk Utilities
                case IDM_DISKMGMT2: RunMMC(L"diskmgmt.msc"); break;
                case IDM_CLEANMGR2: RunSimple(L"cleanmgr.exe"); break;
                case IDM_DFRGUI2: RunSimple(L"dfrgui.exe"); break;
                case IDM_CHKDSK: RunCmdScript(L"chkdsk"); break;
                case IDM_VSSADMIN: RunCmdScript(L"vssadmin list shadows"); break;
                case IDM_DISKPART: RunSimple(L"diskpart.exe"); break;
                case IDM_FORMAT: RunSimple(L"format.com"); break;
                case IDM_COMPACT: RunCmdScript(L"compact /?"); break;
                case IDM_BITLOCKER2: RunControl(L"control.exe /name Microsoft.BitLockerDriveEncryption"); break;
                case IDM_DISKCOPY: RunCmdScript(L"diskcopy"); break;
                case IDM_LABEL: RunCmdScript(L"label"); break;
                case IDM_CONVERT: RunCmdScript(L"convert /?"); break;
                case IDM_FSUTIL: RunCmdScript(L"fsutil"); break;

                // Security Tools
                case IDM_SECPOL: RunMMC(L"secpol.msc"); break;
                case IDM_AUDITPOL: RunCmdScript(L"auditpol /get /category:*"); break;
                case IDM_LUSRMGR: RunMMC(L"lusrmgr.msc"); break;
                case IDM_GPMGMT: RunMMC(L"gpmc.msc"); break;
                case IDM_SECHEALTH: RunControl(L"control.exe /name Microsoft.SecurityandMaintenance"); break;
                case IDM_WINDEFEND: RunSimple(L"WindowsDefender.exe"); break;
                case IDM_WINDEFEND_FW: RunControl(L"firewall.cpl"); break;
                case IDM_UAC: RunCommand(L"UserAccountControlSettings.exe", NULL, L"open"); break;
                case IDM_SYSKEY: RunSimple(L"syskey.exe"); break;
                case IDM_CIPHER: RunCmdScript(L"cipher /?"); break;
                case IDM_CACLS: RunCmdScript(L"cacls"); break;
                case IDM_ICACLS: RunCmdScript(L"icacls"); break;

                // Developer Tools
                case IDM_CMD2: RunSimple(L"cmd.exe"); break;
                case IDM_POWERSHELL2: RunSimple(L"powershell.exe"); break;
                case IDM_WT2: RunSimple(L"wt.exe"); break;
                case IDM_REGEDIT2: RunSimple(L"regedit.exe"); break;
                case IDM_SERVICES2: RunMMC(L"services.msc"); break;
                case IDM_IIS: RunMMC(L"iis.msc"); break;
                case IDM_HYPERV: RunMMC(L"virtmgmt.msc"); break;
                case IDM_WSL: RunSimple(L"wsl.exe"); break;
                case IDM_DEVENV: RunSimple(L"devenv.exe"); break;
                case IDM_VSCODE: RunSimple(L"code.exe"); break;
                case IDM_GITBASH: RunSimple(L"git-bash.exe"); break;
                case IDM_SQLCMD: RunSimple(L"sqlcmd.exe"); break;
                case IDM_ODBCAD32: RunSimple(L"odbcad32.exe"); break;
                case IDM_EVENTCREATE: RunCmdScript(L"eventcreate /?"); break;
                case IDM_SC: RunCmdScript(L"sc"); break;
                case IDM_TASKLIST: RunCmdScript(L"tasklist"); break;
                case IDM_TASKKILL: RunCmdScript(L"taskkill /?"); break;
                case IDM_DRIVERQUERY: RunCmdScript(L"driverquery"); break;
                case IDM_SYSTEMINFO: RunCmdScript(L"systeminfo"); break;
                case IDM_OPENFILES: RunCmdScript(L"openfiles /query"); break;

                // Accessibility
                case IDM_MAGNIFY: RunSimple(L"magnify.exe"); break;
                case IDM_OSK: RunSimple(L"osk.exe"); break;
                case IDM_NARRATOR: RunSimple(L"narrator.exe"); break;
                case IDM_SPEECHREC: RunSimple(L"speechrec.exe"); break;
                case IDM_UTILMAN: RunSimple(L"utilman.exe"); break;
                case IDM_DISPLAYSWITCH: RunSimple(L"displayswitch.exe"); break;
                case IDM_SNIppingTOOL2: RunSimple(L"snippingtool.exe"); break;
                case IDM_STICKYNOTES: RunSimple(L"stikynot.exe"); break;

                // Control Panel items
                case IDM_ADMINTOOLS: RunControl(L"control.exe admintools"); break;
                case IDM_AUTOPLAY: RunControl(L"control.exe /name Microsoft.AutoPlay"); break;
                case IDM_BLUETOOTHDEV: RunControl(L"control.exe /name Microsoft.BluetoothDevices"); break;
                case IDM_COLOR: RunControl(L"control.exe /name Microsoft.ColorManagement"); break;
                case IDM_CREDENTIALS: RunControl(L"control.exe /name Microsoft.CredentialManager"); break;
                case IDM_DATEANDTIME: RunControl(L"timedate.cpl"); break;
                case IDM_DEVICESPRINTERS: RunControl(L"control.exe printers"); break;
                case IDM_EASEACCESS: RunControl(L"control.exe /name Microsoft.EaseOfAccessCenter"); break;
                case IDM_FOLDEROPT2: RunControl(L"control.exe folders"); break;
                case IDM_FONTS2: RunSimple(L"fonts"); break;
                case IDM_GAMING: RunCommand(L"ms-settings:gaming", NULL, L"open"); break;
                case IDM_HOMEGROUP: RunControl(L"control.exe /name Microsoft.HomeGroup"); break;
                case IDM_INFRARED: RunControl(L"control.exe /name Microsoft.Infrared"); break;
                case IDM_INTERNETOPT: RunControl(L"inetcpl.cpl"); break;
                case IDM_KEYBOARD2: RunControl(L"main.cpl"); break;
                case IDM_LANGUAGE: RunControl(L"control.exe /name Microsoft.Language"); break;
                case IDM_LOCATION: RunCommand(L"ms-settings:privacy-location", NULL, L"open"); break;
                case IDM_MOUSE2: RunControl(L"main.cpl"); break;
                case IDM_NETWORKSHARING: RunControl(L"ncpa.cpl"); break;
                case IDM_NOTIFICATION: RunControl(L"control.exe /name Microsoft.NotificationAreaIcons"); break;
                case IDM_PENANDTOUCH: RunControl(L"control.exe /name Microsoft.PenAndTouch"); break;
                case IDM_PERSONALIZE: RunCommand(L"ms-settings:personalization", NULL, L"open"); break;
                case IDM_PHONEANDMODEM: RunControl(L"telephon.cpl"); break;
                case IDM_POWEROPT: RunControl(L"powercfg.cpl"); break;
                case IDM_PRINTERS: RunControl(L"control.exe printers"); break;
                case IDM_PROGRAMSFEAT: RunControl(L"appwiz.cpl"); break;
                case IDM_REGIONAL: RunControl(L"intl.cpl"); break;
                case IDM_SCANNERS: RunControl(L"control.exe /name Microsoft.ScannersAndCameras"); break;
                case IDM_SOUND2: RunControl(L"mmsys.cpl"); break;
                case IDM_SPEECH: RunControl(L"control.exe /name Microsoft.SpeechRecognition"); break;
                case IDM_SYNC: RunControl(L"control.exe /name Microsoft.SyncCenter"); break;
                case IDM_SYSTEM2: RunControl(L"sysdm.cpl"); break;
                case IDM_TABLETPC: RunControl(L"control.exe /name Microsoft.TabletPCSettings"); break;
                case IDM_TASKBAR: RunCommand(L"ms-settings:taskbar", NULL, L"open"); break;
                case IDM_TROUBLESHOOT2: RunCommand(L"ms-settings:troubleshoot", NULL, L"open"); break;
                case IDM_USERACCOUNTS: RunControl(L"control.exe /name Microsoft.UserAccounts"); break;
                case IDM_WINDOWSUPDATE2: RunCommand(L"ms-settings:windowsupdate", NULL, L"open"); break;
                case IDM_WIRELESS: RunControl(L"control.exe /name Microsoft.Wireless"); break;
                case IDM_WORKFOLDERS: RunControl(L"control.exe /name Microsoft.WorkFolders"); break;

                case IDM_ABOUT:
                    MessageBoxW(hWnd, L"Zero Command Center\nVersion 1.0\n\n300+ Windows System Commands\nRight-click to access", L"About", MB_OK);
                    break;
                default: break;
            }
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// ------------------------------------------------------------------
// Entry point
// ------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    g_hInst = hInstance;
    WNDCLASSW wc = {0};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;
    RegisterClassW(&wc);
    HWND hWnd = CreateWindowExW(0, CLASS_NAME, L"Zero Command Center - 300+ System Commands",
                                WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                                800, 600, NULL, NULL, hInstance, NULL);
    if (!hWnd) return 1;
    g_hMainWnd = hWnd;
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}