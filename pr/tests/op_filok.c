/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 * 
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 * 
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */

/***********************************************************************
**
** Name: op_filok.c
**
** Description: Test Program to verify the PR_Open finding an existing file.
**
** Modification History:
** 03-June-97 AGarcia- Initial version
***********************************************************************/

/***********************************************************************
** Includes
***********************************************************************/
/* Used to get the command line option */
#include "prinit.h"
#include "prmem.h"
#include "prio.h"
#include "prerror.h"
#include <stdio.h>

#ifdef XP_MAC
#include "prlog.h"
#define printf PR_LogPrint
#else
#endif

static PRFileDesc *t1;

PRIntn error_code;

int main(int argc, char **argv)
{


#ifdef XP_MAC
	SetupMacPrintfLog("pr_open_re.log");
#endif
	

	
    PR_STDIO_INIT();
#ifndef XP_OS2
	t1 = PR_Open("/usr/tmp/ttools/nspr20/err03.tmp", PR_TRUNCATE | PR_RDWR, 0666);
#else
    t1 = PR_Open("tempfile.txt", PR_TRUNCATE | PR_RDWR, 0666);
#endif
	if (t1 == NULL) {
		if (PR_GetError() == PR_FILE_NOT_FOUND_ERROR) {
				printf ("error code is %d \n", PR_GetError());
				printf ("File should be found\n");
			return 1;
		}
	}
	else {
		printf ("Test passed \n");
		return 0;
	}
}			
