#!/bin/sh
forever start --minUptime $(expr 1000 \* 365 \* 24 \* 60 \* 60 \* 1000) --spinSleepTime $(expr 1 \* 1000) -w --watchDirectory $(pwd) --watchIgnore *.log --watchIgnore node_modules app.js
