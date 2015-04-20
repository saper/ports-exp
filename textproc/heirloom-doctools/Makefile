# $FreeBSD: head/textproc/heirloom-doctools/Makefile 373037 2014-11-22 08:05:32Z hrs $

PORTNAME=	heirloom-doctools
PORTVERSION=	0.0.150406
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities

LICENSE=	CDDL

USE_GITHUB=	yes
GH_ACCOUNT=	n-t-roff
GH_TAGNAME=	${PORTVERSION:S,0.0.,,}

USES=	gmake tar:bzip2
ALL_TARGET=	#empty
MAKE_ENV+=	INSTALL=${INSTALL} \
		BINDIR=${BINDIR} \
		LIBDIR=${LIBDIR} \
		PUBDIR=${PUBDIR} \
		MANDIR=${MANDIR} \
		MACDIR=${MACDIR} \
		FNTDIR=${FNTDIR} \
		PSTDIR=${PSTDIR} \
		TABDIR=${TABDIR} \
		HYPDIR=${HYPDIR} \
		REFDIR=${REFDIR} \
		ROOT=${STAGEDIR}
MAKEFILE=	makefile
PLIST_SUB=	LIBEXECDIR=libexec/${PORTNAME}

MACDIR?=	${DATADIR}/tmac
FNTDIR?=	${DATADIR}/font
TABDIR?=	${DATADIR}/nterm
HYPDIR?=	${DATADIR}/hyphen
REFDIR?=	${PREFIX}/libexec/${PORTNAME}/reftools
PUBDIR?=	${DATADIR}/pub
BINDIR?=	${PREFIX}/bin
LIBDIR?=	${PREFIX}/libexec/${PORTNAME}
PSTDIR?=	${DATADIR}/font/devpost/postscript
MANDIR?=	${PREFIX}/man

PORTDOCS=	 *

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
