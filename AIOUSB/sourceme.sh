#!/bin/bash
# Setups basic paths

export AIOUSB_ROOT="$(pwd)"
export AIO_LIB_DIR="${AIOUSB_ROOT}/lib"
export AIO_CLASSLIB_DIR="$AIOUSB_ROOT/classlib"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:${AIOUSB_ROOT}/lib:${AIOUSB_ROOT}/classlib"
