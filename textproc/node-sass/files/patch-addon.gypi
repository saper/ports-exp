--- node_modules/pangyp/addon.gypi	2015-06-10 08:16:35.900343000 +0000
+++ node_modules/pangyp/addon.gypi	2015-05-11 05:53:50.000000000 +0000
@@ -5,9 +5,7 @@
     'product_prefix': '',
 
     'include_dirs': [
+      '<(node_root_dir)',
-      '<(node_root_dir)/src',
-      '<(node_root_dir)/deps/uv/include',
-      '<(node_root_dir)/deps/v8/include'
     ],
 
     'target_conditions': [
