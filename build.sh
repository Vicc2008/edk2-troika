#!/bin/bash
# based on the instructions from edk2-platform
set -e
. build_common.sh
# not actually GCC5; it's GCC7 on Ubuntu 18.04.
GCC5_AARCH64_PREFIX=aarch64-linux-gnu- build -s -n 0 -a AARCH64 -t GCC5 -p RedmiNote7Pkg/RedmiNote7Pkg.dsc
cat workspace/Build/RedmiNote7Pkg/DEBUG_GCC5/FV/REDMINOTE7PKG_UEFI.fd troika.dtb >>uefi_image
