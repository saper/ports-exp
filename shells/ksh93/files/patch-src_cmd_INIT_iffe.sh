--- src/cmd/INIT/iffe.sh.orig	2016-02-28 17:09:22 UTC
+++ src/cmd/INIT/iffe.sh
@@ -3446,7 +3446,7 @@ $src
 						(eval "$src") <&$nullin || e=1
 						;;
 					mac*|nomac*)
-						if	compile $cc -E $tmp.c <&$nullin >$tmp.i
+						if	compile $cc -E -P $tmp.c <&$nullin >$tmp.i
 						then	sed -e '/<<[ 	]*".*"[ 	]*>>/!d' -e 's/<<[ 	]*"//g' -e 's/"[ 	]*>>//g' $tmp.i
 						else	e=1
 						fi
@@ -3737,7 +3737,7 @@ $inc
 <<\"#define $v\">>	$v	<<\"/* native $v */\">>
 <<\"#endif\">>
 #endif" > $tmp.c
-					if	compile $cc -E $tmp.c <&$nullin >$tmp.i
+					if	compile $cc -E -P $tmp.c <&$nullin >$tmp.i
 					then	sed -e '/<<[ 	]*".*"[ 	]*>>/!d' -e 's/<<[ 	]*"//g' -e 's/"[ 	]*>>//g' $tmp.i > $tmp.t
 						if	test -s $tmp.t
 						then	success
