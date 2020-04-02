#!/usr/bin/env bash

# The ImageMagick policy is causing maintainer-mode builds to fail.
# I think we can clear some of them with this. Also see
# https://askubuntu.com/q/1081895

if [[ -e /etc/ImageMagick-6/policy.xml ]]; then
    mv /etc/ImageMagick-6/policy.xml /etc/ImageMagick-6/policy.xml.unused
fi
