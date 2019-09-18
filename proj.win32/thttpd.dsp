# Microsoft Developer Studio Project File - Name="thttpd" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=thttpd - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "thttpd.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "thttpd.mak" CFG="thttpd - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "thttpd - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "thttpd - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "thttpd - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "thttpd - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MT /W3 /Gm /GX /ZI /I "../" /I "../evnet" /I "../classes" /I "../utils" /I "./" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "WIN32_LEAN_AND_MEAN" /YX /FD /GZ /c /Tp
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:console /debug /machine:I386 /out:"thttpd.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "thttpd - Win32 Release"
# Name "thttpd - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "evnet"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\evnet\acceptor.c
# End Source File
# Begin Source File

SOURCE=..\evnet\acceptor.h
# End Source File
# Begin Source File

SOURCE=..\evnet\aesocket.c
# End Source File
# Begin Source File

SOURCE=..\evnet\aesocket.h
# End Source File
# Begin Source File

SOURCE=..\evnet\channel.c
# End Source File
# Begin Source File

SOURCE=..\evnet\channel.h
# End Source File
# Begin Source File

SOURCE=..\evnet\dataqueue.c
# End Source File
# Begin Source File

SOURCE=..\evnet\dataqueue.h
# End Source File
# Begin Source File

SOURCE=..\evnet\event.c
# End Source File
# Begin Source File

SOURCE=..\evnet\event.h
# End Source File
# Begin Source File

SOURCE=..\evnet\evfunclib.h
# End Source File
# Begin Source File

SOURCE=..\evnet\httparser.c
# End Source File
# Begin Source File

SOURCE=..\evnet\httparser.h
# End Source File
# Begin Source File

SOURCE=..\evnet\httpc.c
# End Source File
# Begin Source File

SOURCE=..\evnet\httpc.h
# End Source File
# Begin Source File

SOURCE=..\evnet\httpd.c
# End Source File
# Begin Source File

SOURCE=..\evnet\httpd.h
# End Source File
# Begin Source File

SOURCE=..\evnet\libnet.c
# End Source File
# Begin Source File

SOURCE=..\evnet\libnet.h
# End Source File
# Begin Source File

SOURCE=..\evnet\muparser.c
# End Source File
# Begin Source File

SOURCE=..\evnet\muparser.h
# End Source File
# Begin Source File

SOURCE=..\evnet\upload.c
# End Source File
# Begin Source File

SOURCE=..\evnet\upload.h
# End Source File
# End Group
# Begin Group "utils"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\utils\buffer.c
# End Source File
# Begin Source File

SOURCE=..\utils\buffer.h
# End Source File
# Begin Source File

SOURCE=..\utils\libos.c
# End Source File
# Begin Source File

SOURCE=..\utils\libos.h
# End Source File
# Begin Source File

SOURCE=..\utils\listlib.h
# End Source File
# Begin Source File

SOURCE=..\utils\log.c
# End Source File
# Begin Source File

SOURCE=..\utils\log.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\classes\bootstrap.c
# End Source File
# Begin Source File

SOURCE=..\classes\thttpd.c
# End Source File
# Begin Source File

SOURCE=..\classes\thttpd.h
# End Source File
# Begin Source File

SOURCE=..\classes\utils.c
# End Source File
# Begin Source File

SOURCE=..\classes\utils.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
