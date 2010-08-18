#!/bin/sh

if [ $# != 1 ]; then
  echo "$0 <output path>"
  exit 1
fi

md5cmd=$(which md5sum)
if [ ! -x "$md5cmd" ]; then
    md5cmd=$(which md5)
    if [ ! -x "$md5cmd" ]; then
        echo "error: unable to find either 'md5sum' or 'md5'"
        exit 1
    fi
fi

mv $1 $1.bak
$md5cmd < $1.bak > $1
rm -f $1.bak
