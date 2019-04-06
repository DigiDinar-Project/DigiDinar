#!/bin/bash -ex

if [ $# -lt 5 ] ; then
    echo "Usage: $0 basedir outdir releasedir commit host"
    exit 1
fi

BASEDIR=$1
OUTDIR=$2
RELEASEBASE=$3
COMMIT=$4
HOST=$5

RELEASEDIR=$BASEDIR/$RELEASEBASE/$COMMIT/$HOST

mkdir -p $RELEASEDIR

# MaxOSX artifacts
cp -a *.dmg $RELEASEDIR || true

# Windows artifacts
cp -a *.exe $RELEASEDIR || true

ls $OUTDIR

tar -cvzf package-$HOST.tgz $BASEDIR
