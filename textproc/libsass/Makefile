# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 360716 2014-07-05 02:58:20Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.2.0.b5
CATEGORIES=	textproc
DISTNAME=	$(PORTVERSION:S,.b,-beta.,)

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

AUTOMAKE_ARGS=	--add-missing

GH_ACCOUNT=	saper
GH_COMMIT=	0dd6543
GH_TAGNAME=	test/node/860

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

USES=		libtool pathfix compiler:c++11-lib
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_GITHUB=	yes
USE_LDCONFIG=	yes

post-build:
	(cd ${WRKSRC}/.libs && ${AR} rf ${PORTNAME}.a *.o)

.include <bsd.port.mk>
