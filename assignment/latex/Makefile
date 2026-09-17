TEX     := pdflatex
TEXOPTS := -interaction=nonstopmode -halt-on-error
SRC     := $(wildcard *.tex)
SRC     := $(filter-out common.tex,$(SRC))
PDF     := $(SRC:.tex=.pdf)

.PHONY: all clean distclean

all: $(PDF)

%.pdf: %.tex common.tex
	$(TEX) $(TEXOPTS) $<
	$(TEX) $(TEXOPTS) $<

clean:
	rm -f *.aux *.log *.out *.toc *.fls *.fdb_latexmk *.synctex.gz

distclean: clean
	rm -f $(PDF)
