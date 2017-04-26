PAPER=00-main


all: rubber #clean


grap:
	(cd graphs/; make)

cod:
	(cd code/; make)

pdf:
	pdflatex $(PAPER)
	bibtex $(PAPER)
	pdflatex $(PAPER)
	pdflatex $(PAPER)

rubber:
	rubber -d $(PAPER).tex

mk:
	latexmk -pvc -pdf $(PAPER).tex

clean:
	rm -f *.blg  *.bak *~ *.log *.aux *.bbl

distclean:
	rm -f $(PAPER).dvi $(PAPER).pdf $(PAPER).ps

