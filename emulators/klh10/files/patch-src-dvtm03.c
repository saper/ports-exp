--- src/dvtm03.c.orig	2020-04-09 21:50:05.924442000 +0200
+++ src/dvtm03.c	2020-04-09 21:51:00.884012000 +0200
@@ -233,7 +233,7 @@
     tm->tm_styp = TM_DT45;		/* Say slave is TU45 for now */
     TMREG(tm, RHR_SN) = (7<<8)|(5<<4)|9;	/* Serial Number register */
 #if KLH10_DEV_DPTM03
-    tm->tm_dpname = "dptm03";		/* Subproc executable */
+    tm->tm_dpname = "/usr/local/libexec/klh10-ks-its/dptm03";		/* Subproc executable */
     tm->tm_spath[0] = '\0';		/* Nothing mounted yet */
     tm->tm_dpdbg = FALSE;
 #endif
