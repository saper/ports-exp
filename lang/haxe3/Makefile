# $FreeBSD$

PORTNAME=	haxe
PORTVERSION=	3.4.7
CATEGORIES=	lang

MAINTAINER=	saper@saper.info
COMMENT=	Haxe programming language, cross-compiler and portable library

LICENSE=	MIT

LIB_DEPENDS=	libneko.so:lang/neko \
		libpcre.so:devel/pcre \
		libgc-threaded.so:devel/boehm-gc-threaded

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	HaxeFoundation
GH_PROJECT=	haxelib:haxelib ocamllibs:ocamllibs
GH_TAGNAME=	${PORTVERSION} a494d8be:haxelib 11b32924:ocamllibs
GH_SUBDIR=	extra/haxelib_src:haxelib libs:ocamllibs

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/src/generators/genneko.ml \
		${WRKSRC}/std/neko/_std/sys/ssl/Certificate.hx \
		${WRKSRC}/std/haxe/io/Path.hx \
		${WRKSRC}/std/hl/_std/sys/ssl/Certificate.hx \
		${WRKSRC}/std/cpp/_std/sys/ssl/Certificate.hx \
		${WRKSRC}/extra/haxelib_src/CHANGES.md \
		${WRKSRC}/extra/haxelib_src/test/RunCi.hx

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/haxe/haxe ${STAGEDIR}${PREFIX}/lib/haxe/haxelib

.include <bsd.port.mk>
