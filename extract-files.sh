#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=hltetmo
./../../$VENDOR/hlte-common/extract-files.sh $@
