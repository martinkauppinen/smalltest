.PHONY: all
all: 01-widget 02-widget 03-widget footest arithmetictest

.PHONY: clean
clean:
	rm -f 01-widget 02-widget 03-widget footest arithmetictest

%: %.cpp
	g++ -o $@ $^ -I../src