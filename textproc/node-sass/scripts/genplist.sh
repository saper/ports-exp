( ( cd `make -V STAGEDIR`/`make -V LOCALBASE` && find bin lib -type f -o -type l ) | sort | grep -v ^lib/node_modules/node-sass/vendor ) > pkg-plist
