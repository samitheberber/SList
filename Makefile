all: clean build testing

build:
	@echo
	@echo Building whole project
	make -C doc build
	make -C src build
	@echo Building whole project completed
	@echo

testing:
	@echo
	@echo Testing whole project
	make -C src testing
	@echo Testing whole project completed
	@echo

clean:
	@echo
	@echo Cleaning whole project
	make -C doc clean
	make -C src clean
	@echo Cleaning whole project completed
	@echo
