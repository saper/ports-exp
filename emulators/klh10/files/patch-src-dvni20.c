--- src/dvni20.c.orig	2020-04-09 21:53:10.434924000 +0200
+++ src/dvni20.c	2020-04-09 21:53:33.849870000 +0200
@@ -354,7 +354,7 @@
     ni->ni_c3dly = 5;		/* Conservative 5-millisec timeout for T10 */
     ni->ni_c3dlyct = 0;
 #if KLH10_DEV_DPNI20
-    ni->ni_dpname = "dpni20";	/* Pathname of device subproc */
+    ni->ni_dpname = "/usr/local/libexec/klh10-ks-its/dpni20";	/* Pathname of device subproc */
     ni->ni_dpidly = 5;		/* Conservative 5-second timeout for T10/T20 */
     ni->ni_dpdbg = FALSE;
 #endif
