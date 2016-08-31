#Sample Project Usig ODB Library

##How to run the project:
1) Install MySQL server on local machine
```
$ sudo apt-get install mysql-server
```
2) Install ODB compiler on local machine, the compiler can be downloaded here: http://www.codesynthesis.com/products/odb/download.xhtml
```
$ sudo dpkg -i odb_x.y.z-n_<arch>.deb
```
3) Create database
```
mysql> create database odb_test;
```
4) Create table
```
CREATE TABLE `person` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `first` text NOT NULL,
  `last` text NOT NULL,
  `age` smallint(5) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=latin1;
```
5) Change the database credential on 'inc/database.h', line 55 (username, password, database)

6) Compile the project
```
$ mkdir build && cd build #create build directory
$ cmake .. && make #create cmake files and compile
```
7) Run the project
```
$ ./OdbSample 
```
