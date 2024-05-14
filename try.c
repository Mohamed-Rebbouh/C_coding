#include"auth_user.h"



int main(){
User user;
char * name,*pass,*email;
name="mohamed";
pass="password";
email="mohamed@gmail.com";
Creat_User(&user,name,pass,email);
Print_User(user);
return 0;
}


