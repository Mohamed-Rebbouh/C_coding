#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<regex.h>

#define MAX_LENGTH 50
#define MAX_LINE_LENGTH 1024
#define DELIMITER ","
typedef struct user{

    char name[MAX_LENGTH];
    char pass_word[MAX_LENGTH];
    char email[MAX_LENGTH];

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
fprintf(file,"\n%s,%s,%s,%d",user->name,user->pass_word,user->email,key);
fclose(file);
return 1;
}



int Email_not_in_csv(const char *email) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Split the line into columns
        char *name = strtok(line, DELIMITER);
        char *pass = strtok(NULL, DELIMITER);
        char *csv_email = strtok(NULL, DELIMITER);
        char *key_str = strtok(NULL, DELIMITER);

        // Check if the email matches
        if (csv_email != NULL && strcmp(csv_email, email) == 0) {
            fclose(file);
            return 0; // Email found
        }
    }

    fclose(file);
    return 1; // Email not found
}



void aloc_User(User *user){
    *user=(User)malloc(sizeof(user));
    if (*user==NULL)printf("NULL");
    else printf("good");
}

int email_regex(char *email){
regex_t regex;
int reti;
regcomp(&regex, "@gmail\\.com$", 0);
reti = regexec(&regex, email, 0, NULL, 0);
regfree(&regex);
    if (!reti) {
        return 1; //  match
    } else if (reti == REG_NOMATCH) {
        return 0; //  no match
    } else {
        fprintf(stderr, "Regex match failed\n");
        return 0; //  failure
    } 
}



int Creat_User(User *user ,char* name,char* pass_word,char *email){
    if(email_regex(email) && Email_not_in_csv(email))
    {aloc_User(user);
    strcpy((*user)->name ,name);
    strcpy((*user)->pass_word,pass_word);
    strcpy((*user)->email,email);
    write_in_csv(*user);
    return 1;}
    else{
        printf("Email not valide");
        return 0;
    }

}


void Print_User(User user){
    printf("i'am %s User here and my email are  %s ",user->name,user->email);
}



void decrypt_pass(char* pass, int key) {
    int len = strlen(pass);
    for (int i = 0; i < len; i++) {
        if (pass[i] >= 'a' && pass[i] <= 'z') {
            pass[i] = pass[i] -  key;
            pass[i]+=pass[i]<'a'?97:0;
        } else if (pass[i] >= 'A' && pass[i] <= 'Z') {
            pass[i] =pass[i]-key;
            pass[i]+=pass[i]<'A'?65:0;
        }
    }
}

