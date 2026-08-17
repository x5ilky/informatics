#!/usr/bin/env bash
set -euo pipefail
file="${1:?Usage: $0 <filepath-or-url>}"
if [[ "$file" =~ ^https?:// ]]; then
    filename="${file##*/}"
    filename="${filename%%\?*}"
    filename="${filename:-download.zip}"

    curl -L -o "$filename" "$file"
    file="$filename"
fi

rm -rf .temp
mkdir -p .temp

case "$file" in
    *.zip)
        unzip "$file" -d .temp
        ;;
    *.tar|*.tar.gz|*.tgz|*.tar.bz2|*.tbz2|*.tar.xz|*.txz|*.tar.zst|*.tzst)
        tar -xf "$file" -C .temp
        ;;
    *)
        echo "Unsupported archive format: $file" >&2
        rm -rf .temp
        exit 1
        ;;
esac

rm -f "$file"

(
    shopt -s nullglob
    mv -f .temp/**/* .temp/* .
)
rm -rf .temp

rm -f \
    submit_*.sh \
    compile_*.sh \
    *.c \
    *.pas

printf '\033[1;32m✓ IMPORTED\033[0m\n'
