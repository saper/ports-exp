--- src/dvlhdh.c.orig	2020-04-09 21:54:00.216384000 +0200
+++ src/dvlhdh.c	2020-04-09 21:56:30.303052000 +0200
@@ -227,9 +227,9 @@
     lh->lh_dpidly = 0;
     lh->lh_dpdbg = FALSE;
 #if KLH10_DEV_DPIMP
-    lh->lh_dpname = "dpimp";		/* Pathname of device subproc */
+    lh->lh_dpname = "/usr/local/libexec/klh10-ks-its/dpimp";		/* Pathname of device subproc */
 #elif KLH10_DEV_SIMP
-    lh->lh_dpname = "simp";		/* Pathname of device subproc */
+    lh->lh_dpname = "/usr/local/libexec/klh10-ks-its/simp";		/* Pathname of device subproc */
 #endif
 
     prm_init(&prm, buff, sizeof(buff),
