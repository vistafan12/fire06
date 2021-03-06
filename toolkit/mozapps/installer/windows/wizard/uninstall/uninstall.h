/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code, released
 * March 31, 1998.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Sean Su <ssu@netscape.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef _SETUP_H_
#define _SETUP_H_

#ifdef __cplusplus
#define PR_BEGIN_EXTERN_C       extern "C" {
#define PR_END_EXTERN_C         }
#else
#define PR_BEGIN_EXTERN_C
#define PR_END_EXTERN_C
#endif

#define PR_EXTERN(type) type

typedef unsigned int PRUint32;
typedef int PRInt32;

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <direct.h>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"

#define CLASS_NAME                      "Uninstall"
#define CLASS_NAME_UNINSTALL_DLG        "MozillaSetupDlg"
#define FILE_INI_UNINSTALL              "uninstall.ini"
#define FILE_LOG_INSTALL                "install_wizard.log"

#ifdef MOZ_PHOENIX
#define WIZ_TEMP_DIR                    "ff_temp"
#elif defined(MOZ_THUNDERBIRD)
#define WIZ_TEMP_DIR                    "tb_temp"
#else
#define WIZ_TEMP_DIR                    "ns_temp"
#endif

#define MAX_KILL_PROCESS_RETRIES        10

/* WTD: What To Do */
#define WTD_ASK                         0
#define WTD_CANCEL                      1
#define WTD_NO                          2
#define WTD_NO_TO_ALL                   3
#define WTD_YES                         4
#define WTD_YES_TO_ALL                  5

/* WS: WinSpawn wait values */
#define WS_DO_NOT_WAIT                  FALSE
#define WS_WAIT                         TRUE

/* CI: Check Instance */
#define CI_FORCE_QUIT_PROCESS           TRUE
#define CI_CLOSE_PROCESS                FALSE

/* PP: Parse Path */
#define PP_FILENAME_ONLY                1
#define PP_PATH_ONLY                    2
#define PP_ROOT_ONLY                    3

#define MAX_BUF                         4096
#define MAX_BUF_TINY                    256
#define ERROR_CODE_HIDE                 0
#define ERROR_CODE_SHOW                 1
#define CX_CHECKBOX                     13
#define CY_CHECKBOX                     13

/* WIZ: WIZARD defines */
#define WIZ_OK                          0
#define WIZ_ERROR_UNDEFINED             1024
#define WIZ_MEMORY_ALLOC_FAILED         1025
#define WIZ_OUT_OF_MEMORY               WIZ_MEMORY_ALLOC_FAILED
#define WIZ_ARCHIVES_MISSING            1026
#define WIZ_CRC_PASS                    WIZ_OK
#define WIZ_CRC_FAIL                    1028
#define WIZ_SETUP_ALREADY_RUNNING       1029
#define WIZ_TOO_MANY_NETWORK_ERRORS     1030
#define WIZ_ERROR_PARSING_INTERNAL_STR  1031
#define WIZ_ERROR_REGKEY                1032
#define WIZ_ERROR_INIT                  1033
#define WIZ_ERROR_LOADING_RESOURCE_LIB  1034
#define WIZ_FILE_NOT_FOUND              1035
#define WIZ_ERROR_PARSING_UNINST_STRS   1036

/* CMI: Cleanup Mail Integration */
#define CMI_OK                          0
#define CMI_APP_PATHNAME_NOT_FOUND      1

/* FO: File Operation */
#define FO_OK                           0
#define FO_SUCCESS                      0
#define FO_ERROR_FILE_NOT_FOUND         1
#define FO_ERROR_DESTINATION_CONFLICT   2
#define FO_ERROR_CHANGE_DIR             3

/* Mode of Setup to run in */
#define NOT_SET                         -1
#define NORMAL                          0
#define SILENT                          1
#define AUTO                            2
#define SHOWICONS                       3
#define HIDEICONS                       4
#define SETDEFAULT                      5

/* OS: Operating System */
#define OS_WIN9x                        0x00000001
#define OS_WIN95_DEBUTE                 0x00000002
#define OS_WIN95                        0x00000004
#define OS_WIN98                        0x00000008
#define OS_NT                           0x00000010
#define OS_NT3                          0x00000020
#define OS_NT4                          0x00000040
#define OS_NT5                          0x00000080
#define OS_NT50                         0x00000100
#define OS_NT51                         0x00000200

typedef struct dlgUninstall
{
  BOOL  bShowDialog;
  LPSTR szTitle;
  LPSTR szMessage0;
} diU;

typedef struct uninstallStruct
{
  int       mode;
  LPSTR     szAppPath;
  LPSTR     szLogPath;
  LPSTR     szLogFilename;
  LPSTR     szCompanyName;
  LPSTR     szProductName;
  LPSTR     szDescription;
  LPSTR     szUninstallKeyDescription;
  LPSTR     szUninstallFilename;
  HKEY      hWrMainRoot;
  LPSTR     szWrMainKey;
  HKEY      hWrRoot;
  LPSTR     szWrKey;
  LPSTR     szUserAgent;
  LPSTR     szDefaultComponent;
  LPSTR     szClientAppID;
  LPSTR     szClientAppPath;
  BOOL      bVerbose;
  BOOL      bUninstallFiles;
  BOOL      bSharedInst;
  HFONT     definedFont;
  char      szInstallPath[MAX_BUF];
} uninstallGen;

typedef struct sInfoLine sil;
struct sInfoLine
{
  ULONGLONG       ullLineNumber;
  LPSTR           szLine;
  sil             *Next;
  sil             *Prev;
};

#endif

