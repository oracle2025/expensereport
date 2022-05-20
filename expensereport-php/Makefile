.PHONY: all
all:
	php ExpenseReport.php


test:
	docker run --rm --volume $(shell pwd):/app -w /app --volume ~/.composer:/composer --user $(shell id -u):$(shell id -g) composer composer --no-scripts --ignore-platform-reqs install
