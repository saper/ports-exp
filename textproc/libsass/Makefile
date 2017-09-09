# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 437554 2017-04-02 12:48:37Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.4.5
PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	sass

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
PATHFIX_MAKEFILEIN=	GNUmakefile.am
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

STATIC_PIC=	${PORTNAME}_pic.a

post-build:
	(cd ${WRKSRC}/src/.libs && ${AR} rf ${STATIC_PIC} *.o)

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${PORTVERSION}\"" > ${WRKSRC}/version.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/${STATIC_PIC} ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
