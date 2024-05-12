#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 50

typedef struct user{

    char name[MAX_LENGTH];
    char pass_word[MAX_LENGTH];

}user;
typedef user* User;

void crypt_pass(char* pass, int key) {
    int len = strlen(pass);
    for (int i = 0; i < len; i++) {
        if (pass[i] >= 'a' && pass[i] <= 'z') {
            pass[i] = 'a' + (pass[i] - 'a' + key) % 26;
        } else if (pass[i] >= 'A' && pass[i] <= 'Z') {
            pass[i] = 'A' + (pass[i] - 'A' + key) % 26;
        }
    }
}


int write_in_csv(User user){

FILE *file ;
file=fopen("data.csv","a");
if (file==NULL){
    return 0;
}
int key=rand()%25+1;
crypt_pass(user->pass_word,key);
fprintf(file,"\n%s,%s,%d",user->name,user->pass_word,key);
fclose(file);
return 1;
}



void aloc_User(User *user){
    *user=(User)malloc(sizeof(user));
    if (*user==NULL)printf("NULL");
    else printf("good");
}


void Creat_User(User *user ,char* name,char* pass_word ){
    aloc_User(user);
    strcpy((*user)->name ,name);
    strcpy((*user)->pass_word,pass_word);
}


void Print_User(User user){
    printf("i'am %s User here %s ",user->name,user->pass_word);
}

int main() {
    User user1;
    char *nam = "mohamed";
    char *pass = "try";
    Creat_User(&user1, nam, pass);
    write_in_csv(user1);
    Print_User(user1);
    free(user1); // Freeing allocated memory
    return 0;
}




