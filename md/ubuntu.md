# Operations

## Ubuntu
### export pdf
sudo apt-get install texlive-xetex
pandoc --latex-engine=xelatex -f markdown cuda.md -o cuda.pdf
mupdf cuda.pdf

### vscode git push failed
git config --global credential.helper cache

