#!/bin/bash

timestamp() {
  date '+%Y-%m-%d %H:%M:%S:%Z'
}

auto_commit_msg="Auto commited at $(timestamp)"

git add .
git commit -m "$auto_commit_msg"
git push
