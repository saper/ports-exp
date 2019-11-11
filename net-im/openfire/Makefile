# Created by: Nikolay Pavlov <qpadla@gmail.com>
# $FreeBSD: head/net-im/openfire/Makefile 492302 2019-02-06 13:20:08Z gahr $

PORTNAME=	openfire
PORTVERSION=	4.4.3
PORTEPOCH=	1
CATEGORIES=	net-im java
MASTER_SITES=	https://github.com/igniterealtime/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enterprise instant messaging server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

EXTRACT_DEPENDS=	mvn:devel/maven
EXTRACT_DEPENDS=	mvn:devel/maven
RUN_DEPENDS=	slf4j>=1.7.7:devel/slf4j

USES=		cpe
USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

CPE_VENDOR=	igniterealtime

ALL_TARGET=	${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-message
SUB_LIST+=	DISTDIR=${DISTDIR}

WRKSRC=		${WRKDIR}/Openfire-${PORTVERSION}
INSTALL_WRKSRC=	${WRKSRC}/distribution/target/distribution-base
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PORTDOCS=	*
VARLOG=		/var/log/${PORTNAME}
VARDB=		/var/db/${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}
PLIST_SUB+=	VARLOG=${VARLOG} \
		VARDB=${VARDB}

post-extract:
	(cd "${WRKSRC}" && mvn -Ddistdir="${DISTDIR}" -Doffline=false -gs "${FILESDIR}/settings.xml" validate dependency:resolve-plugins dependency:go-offline)

do-build:
	(cd "${WRKSRC}" && mvn -Ddistdir="${DISTDIR}" -Doffline=true -gs "${FILESDIR}/settings.xml" package)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${VARDB}
	@${MKDIR} ${STAGEDIR}${VARLOG}

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar ${STAGEDIR}${DATADIR}/lib)
	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 log4j2.xml ${STAGEDIR}${DATADIR}/lib)

	(cd ${INSTALL_WRKSRC}/resources && \
	    ${FIND} . \! -path ./security\* \! -path ./nativeAuth\* | \
	    ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} \
	        ${STAGEDIR}${DATADIR}/resources)

	(cd ${INSTALL_WRKSRC}/plugins && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins)

	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/resources/security
	${LN} -sf ${VARDB} ${STAGEDIR}${DATADIR}/embedded-db
	${LN} -sf ${VARLOG} ${STAGEDIR}${DATADIR}/logs
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/${PORTNAME}.xml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.xml.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${STAGEDIR}${ETCDIR}/truststore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${STAGEDIR}${ETCDIR}/keystore.sample
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/security.xml \
		${STAGEDIR}${ETCDIR}/security.xml.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/documentation && ${FIND} . \
	| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1 )

.include <bsd.port.mk>
