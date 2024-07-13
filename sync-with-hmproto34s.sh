#!/bin/bash
git clone https://github.com/hmasdev/hmproto34s.git ./hmproto34s
cp hmproto34s/keymaps/default/keymap.c ./keymaps/default/keymap.c
cp hmproto34s/keymaps/default/keymap.c ./keymaps/vial/keymap.c
cp -r hmproto34s/keymaps/hmasdevmap ./keymaps/
rm -rf hmproto34s
