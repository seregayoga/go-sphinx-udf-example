# Sphinx UDF in GO example

Example of GO function that calls from sphinx client

# Installation

```
go get -d github.com/seregayoga/go-sphinx-udf-example
cd $GOPATH/src/github.com/seregayoga/go-sphinx-udf-example
make
sudo make install
```

Ensure that `sphinx.conf` contains plugin dir path:
```
common
{
	plugin_dir = /usr/local/sphinx/lib
}
```

# Usage

```
mysql -h127.0.0.1 -P9306

mysql> CREATE FUNCTION gopher_pow RETURNS FLOAT SONAME 'udfexample.so';
Query OK, 0 rows affected (0,00 sec)

mysql> select gopher_pow(2.0, 30.0);
+-----------------------+
| gopher_pow(2.0, 30.0) |
+-----------------------+
| 1073741824.000000     |
+-----------------------+
1 row in set (0,00 sec)
```
