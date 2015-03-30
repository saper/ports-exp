# Created by: Marcin Cieslak <saper@SAPER.INFO>
# $FreeBSD$

PORTNAME=	node-sass
PORTVERSION=	3.0.0.b4
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	textproc www

MAINTAINER=	saper@SAPER.INFO
COMMENT=	C/C++ Sass compiler bindings for nodejs

LICENSE=	MIT

FETCH_DEPENDS=	npm>=0:${PORTSDIR}/www/npm
BUILD_DEPENDS=	npm>=0:${PORTSDIR}/www/npm \
		${LOCALBASE}/lib/libsass.a:${PORTSDIR}/textproc/libsass
RUN_DEPENDS=	npm>=0:${PORTSDIR}/www/npm

USES=		compiler python:2.7 gmake:lite

GH_ACCOUNT=	saper
GH_COMMIT=	5d5dff4
GH_TAGNAME=	FreeBSD

USE_GITHUB=	yes

NO_BUILD=	yes

MAKE_ENV+=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX} V=1
MAKE_ENV+=	SKIP_SASS_BINARY_DOWNLOAD_FOR_CI=yes
MAKE_ENV+=	LIBSASS_EXT=yes CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	LIBSASS_LIBRARY=${LOCALBASE}/lib/libsass.a
MAKE_ENV+=	LIBSASS_CFLAGS=-I${LOCALBASE}/include

NODE_MODULES=	${WRKDIR}/node_modules

NODE_GYP=	${WRKSRC}/node_modules/pangyp/bin/node-gyp

.include <bsd.port.pre.mk>
.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	GYP_DEFINES=clang=1
.else
USE_GCC=	any
.endif

post-fetch:
	${MKDIR} ${NODE_MODULES}
	${CP} ${FILESDIR}/package.json ${WRKDIR}
	(cd ${NODE_MODULES} && ${SETENV} HOME=${WRKDIR} npm install)

do-install:
	${MV} ${NODE_MODULES} ${WRKSRC}
	(cd ${STAGEDIR}${PREFIX}/lib && ${SETENV} HOME=${WRKDIR} ${CONFIGURE_ENV} ${MAKE_ENV} npm install ${WRKSRC})
	${LN} -s ${PREFIX}/lib/node_modules/.bin/node-sass ${STAGEDIR}${PREFIX}/bin/node-sass

.include <bsd.port.post.mk>
