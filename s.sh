#!/bin/bash

# Always run from current repo (VS Code terminal safe)
cd "$(pwd)" || exit

# Safety check: ensure this is a git repo
if [ ! -d ".git" ]; then
  echo "❌ Not a git repository. Run inside your Learning_DSA folder."
  exit 1
fi

# Add all changes
git add .

# If nothing to commit, stop
if git diff --cached --quiet; then
  echo "⚠️ No changes to commit."
  exit 0
fi

# Commit with timestamp
timestamp=$(date "+%Y-%m-%d %H:%M:%S")

git commit -m "DSA update - $timestamp"

# Push to GitHub
git push origin main

echo "✅ Pushed successfully!"