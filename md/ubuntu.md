# Ubuntu operations

### export pdf
sudo apt-get install texlive-xetex
pandoc --latex-engine=xelatex -f markdown cuda.md -o cuda.pdf
mupdf cuda.pdf