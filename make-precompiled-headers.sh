#!/usr/bin/env bash
# 
# Make precompiled headers for each version, opt and debug level
# Run as sudo.
#
#
#
set -euo pipefail

CXX="${CXX:-g++}"
JOBS="${JOBS:-$(nproc)}"

# ──────────────────────────────────────────────────────────────────────────────
# ANSI
# ──────────────────────────────────────────────────────────────────────────────

RESET=$'\033[0m'
BOLD=$'\033[1m'
DIM=$'\033[2m'

RED=$'\033[31m'
GREEN=$'\033[32m'
YELLOW=$'\033[33m'
BLUE=$'\033[34m'
MAGENTA=$'\033[35m'
CYAN=$'\033[36m'
WHITE=$'\033[37m'

BRIGHT_RED=$'\033[91m'
BRIGHT_GREEN=$'\033[92m'
BRIGHT_YELLOW=$'\033[93m'
BRIGHT_BLUE=$'\033[94m'
BRIGHT_MAGENTA=$'\033[95m'
BRIGHT_CYAN=$'\033[96m'

info() {
    printf '%s●%s %s\n' "$BRIGHT_BLUE" "$RESET" "$*"
}

success() {
    printf '%s✓%s %s\n' "$BRIGHT_GREEN" "$RESET" "$*"
}

warn() {
    printf '%s!%s %s\n' "$BRIGHT_YELLOW" "$RESET" "$*"
}

error() {
    printf '%s✗%s %s\n' "$BRIGHT_RED" "$RESET" "$*" >&2
}

section() {
    printf '\n%s%s━━━ %s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━%s\n' \
        "$BOLD" "$BRIGHT_CYAN" "$*" "$RESET"
}

# ──────────────────────────────────────────────────────────────────────────────
# Configuration
# ──────────────────────────────────────────────────────────────────────────────

STANDARDS=(
    c++11
    c++17
    c++20
    c++23
    gnu++11
    gnu++17
    gnu++20
    gnu++23
)

OPTS=(
    O0
    O2
    O3
)

MODES=(
    normal
    debug
    sanitize
)

# ──────────────────────────────────────────────────────────────────────────────
# Helpers
# ──────────────────────────────────────────────────────────────────────────────

find_bits_header() {
    local path

    while IFS= read -r path; do
        path="${path#"${path%%[![:space:]]*}"}"
        path="${path%"${path##*[![:space:]]}"}"

        if [[ -f "$path/bits/stdc++.h" ]]; then
            printf '%s\n' "$path/bits/stdc++.h"
            return 0
        fi
    done < <(
        "$CXX" -E -x c++ - -v </dev/null 2>&1 |
            sed -n \
                '/#include <...> search starts here:/,/End of search list./p' |
            sed '1d;$d'
    )

    return 1
}

mode_colour() {
    case "$1" in
        normal)   printf '%s' "$BRIGHT_GREEN" ;;
        debug)    printf '%s' "$BRIGHT_YELLOW" ;;
        sanitize) printf '%s' "$BRIGHT_MAGENTA" ;;
    esac
}

build_one() {
    local header="$1"
    local outdir="$2"
    local std="$3"
    local opt="$4"
    local mode="$5"

    local name="${std}-${opt}-${mode}"
    local output="$outdir/$name"
    local colour

    colour="$(mode_colour "$mode")"

    local flags=(
        "-std=$std"
        "-$opt"
    )

    case "$mode" in
        normal)
            ;;
        debug)
            flags+=(
                -g
            )
            ;;
        sanitize)
            flags+=(
                -g
                -fsanitize=address,undefined
            )
            ;;
    esac

    printf '%s▶%s %-29s %s[%s]%s\n' \
        "$BRIGHT_BLUE" "$RESET" \
        "$name" \
        "$colour" \
        "building" \
        "$RESET"

    if "$CXX" \
        "${flags[@]}" \
        -x c++-header \
        "$header" \
        -o "$output"
    then
        printf '%s✓%s %-29s %s[%s]%s\n' \
            "$BRIGHT_GREEN" "$RESET" \
            "$name" \
            "$BRIGHT_GREEN" \
            "done" \
            "$RESET"
    else
        printf '%s✗%s %-29s %s[%s]%s\n' \
            "$BRIGHT_RED" "$RESET" \
            "$name" \
            "$BRIGHT_RED" \
            "failed" \
            "$RESET" >&2

        return 1
    fi
}

export -f build_one
export -f mode_colour

export CXX

export RESET
export BOLD
export DIM

export RED
export GREEN
export YELLOW
export BLUE
export MAGENTA
export CYAN
export WHITE

export BRIGHT_RED
export BRIGHT_GREEN
export BRIGHT_YELLOW
export BRIGHT_BLUE
export BRIGHT_MAGENTA
export BRIGHT_CYAN

# ──────────────────────────────────────────────────────────────────────────────
# Main
# ──────────────────────────────────────────────────────────────────────────────

printf '\n'
printf '%s%s' "$BOLD" "$BRIGHT_CYAN"
printf '╭──────────────────────────────────────────────────────────╮\n'
printf '│              GCC PRECOMPILED HEADER BUILDER              │\n'
printf '╰──────────────────────────────────────────────────────────╯\n'
printf '%s' "$RESET"

section "Detecting compiler"

info "Compiler: ${BOLD}${CXX}${RESET}"
info "GCC version: ${BOLD}$("$CXX" -dumpfullversion -dumpversion)${RESET}"

if [[ $EUID -ne 0 ]]; then
    printf '\n'
    warn "Root permission is required to write into GCC's include directory."
    printf '\n'
    printf '  Run:\n\n'
    printf '    %ssudo CXX=%q JOBS=%q %q%s\n\n' \
        "$BRIGHT_CYAN" "$CXX" "$JOBS" "$0" "$RESET"
    exit 1
fi

HEADER="$(find_bits_header || true)"

if [[ -z "$HEADER" ]]; then
    error "Could not locate bits/stdc++.h"
    exit 1
fi

OUTDIR="${HEADER}.gch"

section "Configuration"

printf '  %sCompiler%s      %s%s%s\n' \
    "$DIM" "$RESET" "$BOLD" "$CXX" "$RESET"

printf '  %sHeader%s        %s%s%s\n' \
    "$DIM" "$RESET" "$BOLD" "$HEADER" "$RESET"

printf '  %sOutput%s        %s%s%s\n' \
    "$DIM" "$RESET" "$BOLD" "$OUTDIR" "$RESET"

printf '  %sWorkers%s       %s%s%s\n' \
    "$DIM" "$RESET" "$BOLD" "$JOBS" "$RESET"

printf '  %sStandards%s     %s%s%s\n' \
    "$DIM" "$RESET" "$CYAN" "${STANDARDS[*]}" "$RESET"

printf '  %sOptimisation%s  %s%s%s\n' \
    "$DIM" "$RESET" "$YELLOW" "${OPTS[*]}" "$RESET"

printf '  %sModes%s         %snormal  %sdebug  %ssanitize%s\n' \
    "$DIM" "$RESET" \
    "$BRIGHT_GREEN" \
    "$BRIGHT_YELLOW" \
    "$BRIGHT_MAGENTA" \
    "$RESET"

TASKS=()

for std in "${STANDARDS[@]}"; do
    for opt in "${OPTS[@]}"; do
        for mode in "${MODES[@]}"; do
            TASKS+=("$std|$opt|$mode")
        done
    done
done

TOTAL="${#TASKS[@]}"

printf '\n'
info "Total PCH variants: ${BOLD}${TOTAL}${RESET}"

section "Preparing output"

if [[ -f "$OUTDIR" ]]; then
    warn "Removing existing single-file PCH:"
    printf '  %s%s%s\n' "$DIM" "$OUTDIR" "$RESET"
    rm -f "$OUTDIR"
fi

mkdir -p "$OUTDIR"

success "Output directory ready."

section "Building ${TOTAL} variants"

printf '%s' "$DIM"
printf '  normal   = standard compilation\n'
printf '  debug    = -g\n'
printf '  sanitize = -g -fsanitize=address,undefined\n'
printf '%s\n' "$RESET"

START_TIME="$(date +%s)"

printf '%s\n' "${TASKS[@]}" |
    xargs -P "$JOBS" -I '{}' bash -c '
        IFS="|" read -r std opt mode <<< "$1"
        build_one "$2" "$3" "$std" "$opt" "$mode"
    ' _ '{}' "$HEADER" "$OUTDIR"

END_TIME="$(date +%s)"
ELAPSED=$((END_TIME - START_TIME))

section "Complete"

success "Built ${BOLD}${TOTAL}${RESET} PCH variants."
success "Elapsed: ${BOLD}${ELAPSED}s${RESET}"

printf '\n'
printf '  %sOutput:%s %s\n\n' "$DIM" "$RESET" "$OUTDIR"

printf '%s%s' "$BOLD" "$BRIGHT_GREEN"
printf '╭──────────────────────────────────────────────────────────╮\n'
printf '│                     BUILD COMPLETE                       │\n'
printf '╰──────────────────────────────────────────────────────────╯\n'
printf '%s\n' "$RESET"
