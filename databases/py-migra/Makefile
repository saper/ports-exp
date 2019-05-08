# Created by: Marcin Cieslak <saper@SAPER.INFO>
# $FreeBSD$

PORTNAME=	migra
PORTVERSION=	1.0.1554608452
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	saper@SAPER.INFO
COMMENT=	Like diff but for Postgres schemas

LICENSE=	UNLICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}schemainspect>=0.1.1556103540:devel/py-schemainspect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlbag>0:databases/py-sqlbag@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
