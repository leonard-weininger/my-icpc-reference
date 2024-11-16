LATEXCMD = pdflatex -shell-escape -output-directory build
export TEXINPUTS=.:content/tex/:
export max_print_line = 1048576

main:
	mkdir -p build/
	$(LATEXCMD) content/main.tex
	$(LATEXCMD) content/main.tex
	$(LATEXCMD) content/test-session/test-session.tex 
	$(LATEXCMD) content/test-session/test-session.tex
	cp build/main.pdf main.pdf
	cp build/test-session.pdf test-session.pdf
	rm -f header.tmp

clean:
	rm -f main.pdf test-session.pdf
	rm -f build -rf

.PHONY: kactl clean
