#!/bin/sh

COMPILER=""

main() {
    while [ "$#" -gt 0 ]; do
        case "$1" in
            --set-compiler)
                shift
                COMPILER="$1"
                ;;
            *)
                PARAMS+=("$1")
                ;;
        esac
        shift
    done
    echo "compiling with ${COMPILER}"
    set -- "${PARAMS[@]}"
    if [ -z "$COMPILER" ]; then
        clang "$@"
    else
        $COMPILER "$@"
    fi;
}

main "$@"
