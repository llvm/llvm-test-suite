#!/bin/sh
# Stand in for strip to allow calling it on the "executables" used by these
# tests (which are shell scripts in reality).
shift $(($# - 2))
cp "$2" "$1"
