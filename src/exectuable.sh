#! /bin/sh
# Created Time: 2015-11-12 10:58:38
#

cd ../build

echo "current exe path:"
pwd

if [ "$#" != "0" ]; then
    echo "para count : "$#
    echo "para list : "$*
    bin/dataming-core $*
else
    bin/dataming-core
fi


