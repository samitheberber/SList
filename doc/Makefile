all: clean build

TEX=report.tex
TARGET=report.pdf

LATEX_ARGS=--interaction batchmode

$(TARGET): $(TEX)
	pdflatex $(LATEX_ARGS) $(TEX)

clean:
	rm *.aux *.log *.pdf

build: $(TARGET)
