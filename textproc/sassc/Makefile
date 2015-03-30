# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/sassc/Makefile 360717 2014-07-05 03:23:35Z nivit $

PORTNAME=	sassc
PORTVERSION=	3.2.0.b2
CATEGORIES=	textproc
DISTNAME=	${PORTVERSION:S,.b,-beta.,}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

LIB_DEPENDS=	libsass.so:${PORTSDIR}/textproc/libsass

AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV+=	SASSC_VERSION="${PORTVERSION}"

CPPFLAGS+=	-I${LOCALBASE}/include

GH_ACCOUNT=	saper
GH_COMMIT=	9ca36a4
GH_TAGNAME=	fixes

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/sassc

USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_GITHUB=	yes
USES=		compiler:c++11-lib

.include <bsd.port.mk>
