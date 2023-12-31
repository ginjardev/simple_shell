#!/usr/bin/env bash

set -e

ROOTDIR="$(pwd)"

set -x

cat > "${ROOTDIR}/AUTHORS" <<- EOF
	# File @generated by simple_shell/generate-authors.sh. DO NOT EDIT.
	# This file lists all contributors to the repository.

	$(git -C "$ROOTDIR" log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf)
EOF
