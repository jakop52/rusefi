#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")/../../.."
make -j12 PROJECT_BOARD=zgrywus-k8 config
make -j12 PROJECT_BOARD=zgrywus-k8 build/rusefi.bin build/rusefi.hex
