rm .gitignore
find . -executable -type f >>.gitignore
git add .
git commit -m "update"

git push