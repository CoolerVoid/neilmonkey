Author: Antonio Costa "Cooler_"
contact: c00f3r[at]gmail[dot]com


+-------------------------+------+
| Neil Monkey |  WarGame  | 0x01 |
+-------------+-----------+------+
+++++++++++++++++++++++ BETA

Mission Level 0x01
==================
So this is simple example how web app
can be lethal if not validate inputs,
the interesting from this game,is that
have many forms to find one course to 
exploit.

Your mission is simple,exploit the "CGI"
file "find.cgi",get the one user pass 
and crack the MD5 and try enter in auth on 
"auth.cgi". 


How to install and use
=======================
so i test in my centOS,

# yum intall mysql-server mysql-client httpd phpmyadmin \
 libcgi-devel libdbi-devel libdbi-dbd-mysql

on debian
libdbi-dev,libcgi-dev...

first step create table in MySQL

CREATE TABLE neiluser(
 id int NOT NULL auto_increment,
 login varchar(30),
 pass varchar(32),
 state varchar(32),
 mail varchar(80),
 bankcode integer(18),
 created_at TIMESTAMP,
 updated_at TIMESTAMP,
 PRIMARY KEY(id,login)
);

insert this data;

INSERT INTO neiluser (login,pass,state,mail,bankcode) VALUES ("Chapolin", "5fbe6dd510f6bf166fd289227953204f","RJ","chap@x.com","leite");
INSERT INTO neiluser (login,pass,state,mail,bankcode) VALUES ("madruga", "20a26462ac59b7c059a909932f4f86be","SC","madru@x.com","71");
INSERT INTO neiluser (login,pass,state,mail,bankcode) VALUES ("heman", "6ac2c10a6aa073b7ee1ad31993cbde44","SC","greyskul@x.com","sheha");
INSERT INTO neiluser (login,pass,state,mail,bankcode) VALUES ("jaspion", "5fc83d2bf1d3922eccc4364d207935a4","SP","jap@x.com","001");

now look the find.c file read coments...

I guess about change DBI api to "MySQL.h",
because DBI bind some logs, this causes somes
mistakes on hour to bypass query slashs...
