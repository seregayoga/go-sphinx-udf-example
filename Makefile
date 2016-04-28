all: go_build c_build

go_build:
	go build -buildmode=c-shared -o gopherpow.so gopherpow.go

c_build:
	gcc -fPIC -shared -o udfexample.so udfexample.c $(CURDIR)/gopherpow.so

install:
	mkdir -p /usr/local/sphinx/lib && cp udfexample.so /usr/local/sphinx/lib/

