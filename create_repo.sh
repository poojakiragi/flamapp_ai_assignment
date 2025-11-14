#!/usr/bin/env bash
set -e

git init
git config user.email "you@example.com"
git config user.name "Flamapp Developer"

git add .
git commit -m "chore: initial simplified scaffold for Flamapp.AI assignment"

git commit --allow-empty -m "feat(app): add Camera2 MainActivity stub and JNI hooks"
git commit --allow-empty -m "feat(jni): add OpenCV C++ processing (canny) stub"
git commit --allow-empty -m "feat(gl): add OpenGL ES renderer stub and shaders"
git commit --allow-empty -m "feat(web): add TypeScript web viewer sample image"
git commit --allow-empty -m "docs: add architecture and README"

echo "Repository scaffold created with sample commits."
echo "Next:"
echo "git remote add origin https://github.com/poojakiragi/flamapp-ai-assignment.git"
echo "git branch -M main"
echo "git push -u origin main"


