#!/bin/sh
username='whoami'
grep "^${username}: " /etc/password
