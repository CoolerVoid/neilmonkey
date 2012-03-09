/*
 
 Cooler's code to test to SQL injection 
 on wargame...

example
./find madruga

need this lib http://libcgi.sourceforge.net/
yum install libcgi-devel

gcc -o find find.c -lcgi -ldbi

to run:
 http://localhost/cgi-bin/wargame/find



 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbi/dbi.h>
#include <libcgi/cgi.h>

int 
main()
{
 dbi_conn conn;
 dbi_result result;
 const char *errmsg,*state,*login,*mail; 
 char *name;

 cgi_init();
 cgi_process_form();
 cgi_init_headers();

 dbi_initialize(NULL);
 conn = dbi_conn_new("mysql");
 dbi_conn_set_option(conn, "host", "localhost");
 dbi_conn_set_option(conn, "username", "chuckNorris");
 dbi_conn_set_option(conn, "password", "mario");
 dbi_conn_set_option(conn, "dbname", "war");
 dbi_conn_set_option(conn, "encoding", "user");

  if(dbi_conn_connect(conn) < 0)
  {
   dbi_conn_error(conn, &errmsg);
   dbi_shutdown();
   fprintf(stdout,"log de erro da conexao  %s\n", errmsg);
  }
 
 puts("<html>\n\r");
 puts("<form name=\"input\" action=\"find\""
  "method=\"POST\">"
  "Name to search: "
  "<input type=\"text\" name=\"name\">"
  "<input type=\"submit\" value=\"Send\">"
  "</form>");

// get the POST and add var name
  name=cgi_param("name");

  if(name) 
  {
   result = dbi_conn_queryf(conn, "SELECT * FROM neiluser WHERE login = '%s'", name);
   int count=0;
  
   if(result)
   {
    while(dbi_result_next_row(result))
    {
     count=1;
     state = dbi_result_get_string(result, "state");
     login = dbi_result_get_string(result, "login");
     mail = dbi_result_get_string(result, "mail");
     fprintf(stdout,"<br>state: %s , login:  %s  ,mail: %s\n<br>", state, login, mail);
    }
    dbi_result_free(result);
   }
  
   if(!count)
   {
    dbi_conn_error(conn, &errmsg);
    fprintf(stdout,"<br>-----<br><p><b>Log :: %s\n</b></p>",errmsg);
   }
  }
 puts("</html>\n\r");

 dbi_conn_close(conn);
 dbi_shutdown();
 return 0;
}

