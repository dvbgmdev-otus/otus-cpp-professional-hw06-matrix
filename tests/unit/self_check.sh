#!/usr/bin/env bash
set -eEuo pipefail
trap 'echo "[ERROR] ${BASH_SOURCE[0]}:${LINENO}: \"${BASH_COMMAND}\" failed" >&2' ERR

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd -P)"
# shellcheck disable=SC1091
source "$SCRIPT_DIR/../../scripts/lib/config.sh"
# shellcheck disable=SC1091
source "$LIB_DIR/logging.sh"

BINARY="$BIN_DIR/otus_matrix"

check_output() {
    local name="$1"
    local expected="$2"
    local actual="$3"

    if [[ "$actual" != "$expected" ]]; then
        log_error "Test failed: $name"
        log_error "Expected: [$expected]"
        log_error "Actual:   [$actual]"
        exit 1
    fi

    log_ok "Passed: $name"
}


main() {
    if [[ ! -x "$BINARY" ]]; then
        log_error "Binary not found or not executable: $BINARY"
        exit 1
    fi

    local output
    output="$("$BINARY")"

    local expected
    expected="$(cat <<'EXPECTED'
1 0 0 0 0 0 0 8
0 2 0 0 0 0 7 0
0 0 3 0 0 6 0 0
0 0 0 4 5 0 0 0
0 0 0 4 5 0 0 0
0 0 3 0 0 6 0 0
0 2 0 0 0 0 7 0
1 0 0 0 0 0 0 8
18
Cell(0,9) = 9
Cell(1,1) = 1
Cell(1,8) = 8
Cell(2,2) = 2
Cell(2,7) = 7
Cell(3,3) = 3
Cell(3,6) = 6
Cell(4,4) = 4
Cell(4,5) = 5
Cell(5,4) = 4
Cell(5,5) = 5
Cell(6,3) = 3
Cell(6,6) = 6
Cell(7,2) = 2
Cell(7,7) = 7
Cell(8,1) = 1
Cell(8,8) = 8
Cell(9,9) = 9
EXPECTED
)"

    check_output "full program output" "$expected" "$output"

    log_ok "Self-check passed"
}

main "$@"
