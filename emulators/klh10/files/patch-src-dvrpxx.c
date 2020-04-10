--- src/dvrpxx.c.orig	2020-04-09 21:17:38.548510000 +0200
+++ src/dvrpxx.c	2020-04-09 21:18:23.903488000 +0200
@@ -301,7 +301,7 @@
     rp->rp_spath[0] = '\0';		/* No path (default it later) */
 #if KLH10_DEV_DPRPXX
     rp->rp_dpdma = TRUE;		/* Default is DO use DMA if possible */
-    rp->rp_dpname = "dprpxx";		/* Subproc executable */
+    rp->rp_dpname = "/usr/local/libexec/klh10-ks-its/dprpxx";		/* Subproc executable */
     rp->rp_dpdbg = FALSE;
 #endif
 
