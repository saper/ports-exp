--- src/kn10dev.c.orig	2020-04-09 20:20:21.549575000 +0200
+++ src/kn10dev.c	2020-04-09 20:28:34.480045000 +0200
@@ -1347,7 +1347,7 @@
 	if (!(res = (*d->dv_readin)(d, of, w, (w10_t *)vp, 128)))
 	    return FALSE;
 	if (op10m_camn(vm_pget(vp), w6hom)) {
-	    if (of) fprintf(of, "Bad HOM check, val = %lo,,%lo\n",
+	    if (of) fprintf(of, "Bad HOM check, sector=%d, val = %lo,,%lo\n",
 			    1, (long)LHGET(w), (long)RHGET(w));
 	    return FALSE;
 	}
@@ -1356,7 +1356,7 @@
 	if (!(res = (*d->dv_readin)(d, of, w, (w10_t *)vp, 128)))
 	    return FALSE;
 	if (op10m_camn(vm_pget(vp), w6hom)) {
-	    if (of) fprintf(of, "Bad HOM check, val = %lo,,%lo\n",
+	    if (of) fprintf(of, "Bad HOM check, sector=%d, val = %lo,,%lo\n",
 			    010, (long)LHGET(w), (long)RHGET(w));
 	    return FALSE;
 	}
