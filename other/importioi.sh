#!/usr/bin/env bash
set -euo pipefail
file="${1:?Usage: $0 <filepath-or-url>}"
if [[ "$file" =~ ^https?:// ]]; then
    filename="${file##*/}"
    filename="${filename%%\?*}"
    filename="${filename:-download.zip}"

    curl -o "$filename" -LO "$file"
    file="$filename"
fi
rm -rf .temp
mkdir -p .temp
unzip "$file" -d .temp
rm "$file"
mv .temp/*/** .
rm -rf .temp
rm submit_*.sh
printf '\033[1;32m✓ IMPORTED\033[0m\n'
