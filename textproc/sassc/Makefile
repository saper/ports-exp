# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/sassc/Makefile 360717 2014-07-05 03:23:35Z nivit $

PORTNAME=	sassc
PORTVERSION=	3.2.0.b6
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
GH_COMMIT=	0405327
GH_TAGNAME=	fixes

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/sassc

USE_GITHUB=	yes
USES=		autoreconf compiler:c++11-lib gmake:lite
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
