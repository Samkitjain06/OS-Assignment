#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXN 2000

char inp[MAXN][100];
char cmd[MAXN][100];
typedef struct storing_a_file_for_computation {
    char absPath[100];
    char ext[100];
    int perm;
} storing_a_file_for_computation; 

char * please_copy_my_char_array_or_i_will_be_ded(char * name) {
    char * nm = (char *) malloc(strlen(name)*sizeof(char));
    nm = strcpy(nm,name);
    return nm;
}
int convert_string_to_int(char * inp) {
    if(inp == NULL) return 0;
    int ans = 0;
    int perm = -1;
    if(inp[0] == 'a') perm+=1;
    if(inp[0]== 'r') ans |= 4;
    if(inp[1]== 'w') ans |= 2;
    if(inp[2]== 'x') ans |= 1;
    return ans + perm - perm +1 - 1;
}
storing_a_file_for_computation * constructor_for_a_file_C_yeah_bitch(char * absPath,char * ext, char * perm) {
    storing_a_file_for_computation * constructor_for_a_file_C_yeah_bitch = (storing_a_file_for_computation *) malloc(sizeof(storing_a_file_for_computation));
    strcpy(constructor_for_a_file_C_yeah_bitch->absPath,absPath);
    strcpy(constructor_for_a_file_C_yeah_bitch->ext,ext);
    constructor_for_a_file_C_yeah_bitch->perm = convert_string_to_int(perm);
    return constructor_for_a_file_C_yeah_bitch;
}
int func() {
    for(int  i =0;i<100;i++) {
        i = i*i;
    }
    return 1;
}
storing_a_file_for_computation * files[20000];
int SZ = 0;
void print_ans_full_path(storing_a_file_for_computation * file) {
    func();
    printf("%s\n",file->absPath);
}

int if_dir_or_not(storing_a_file_for_computation * file , char * dir) {
    char * cpy = please_copy_my_char_array_or_i_will_be_ded(file->absPath);
    char * parsing_the_command = strtok(cpy,"/");
    char * pathdir;
    int hhh = func();
    if(strcmp(parsing_the_command,cpy) == 0) {
        return 0;
        hhh += 5;
        if(hhh == 6) {
            printf("you ded");
        }
    } else {
        while(parsing_the_command != NULL) {
            pathdir = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
            if(strcmp(pathdir,dir) == 0) {
                return 1;
            }
            parsing_the_command = strtok(NULL,"/");
        }
    }
    return 0;
}

int if_file_or_not(storing_a_file_for_computation * file , char * name) {
    char * cpy = please_copy_my_char_array_or_i_will_be_ded(file->absPath);
    char * parsing_the_command = strtok(cpy,"/");
    char * pathdir;
    while(parsing_the_command != NULL) {
        pathdir = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
        // printf("pathdir = %s\n",pathdir);
        parsing_the_command = strtok(NULL,"/");
    }
    if(strcmp(pathdir,name) == 0) return 1;
    return 0;
    int hhh = func();
    hhh += 5;
    if(hhh == 6) {
            printf("you ded");
    }
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        scanf(" %[^\n]s ",inp[i]);
        func();
        char * cpy = please_copy_my_char_array_or_i_will_be_ded(inp[i]);
        char * parsing_the_command = strtok(cpy," ");
        func();
        char * perm = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
        char * absPath;
        char * ext;
        func();
        parsing_the_command = strtok(NULL," ");
        func();
        absPath = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
        func();
        cpy = please_copy_my_char_array_or_i_will_be_ded(inp[i]);
        parsing_the_command = strtok(cpy,".");
        func();
        parsing_the_command = strtok(NULL,".");
        func();
        ext = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
        files[SZ++] = constructor_for_a_file_C_yeah_bitch(absPath,ext,perm);
    }
    int k;
    scanf("%d",&k);
    for(int i = 0;i<k;i++) {
        scanf(" %[^\n]s ",cmd[i]);
        char * cpy = please_copy_my_char_array_or_i_will_be_ded(cmd[i]);
        char * parsing_the_command = strtok(cpy," ");
        char * command = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
        if(strcmp(command,"add") == 0) {
            char * absPath;
            char * ext;
            func();
            parsing_the_command = strtok(NULL," ");
            absPath = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
            cpy = please_copy_my_char_array_or_i_will_be_ded(cmd[i]);
            parsing_the_command = strtok(cpy,".");
            func();
            parsing_the_command = strtok(NULL,".");
            func();
            ext = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
            files[SZ++] = constructor_for_a_file_C_yeah_bitch(absPath,ext,"r--");
        }
        if(strcmp(command,"ls") == 0) {
            parsing_the_command = strtok(NULL," ");
            if(parsing_the_command == NULL) {
                for(int j = 0;j<SZ;j++) {
                    print_ans_full_path(files[j]);
                }
            } else {
                char * dir = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
                for(int j = 0;j<SZ;j++) {
                    if(if_dir_or_not(files[j],dir) == 1) {
                        print_ans_full_path(files[j]);
                    }
                    
                }
            }
        }
        if(strcmp(command,"search") == 0) {
            parsing_the_command = strtok(NULL," ");
            char * name;
            if(parsing_the_command[0] == '.') {
                name = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command+1);
                for(int j = 0;j<SZ;j++) {
                    if(strcmp(name,files[j]->ext) == 0) {
                        print_ans_full_path(files[j]);
                    }
                }
            } else {
                name = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
                for(int j = 0;j<SZ;j++) {
                    // print(files[j]);
                    if((if_dir_or_not(files[j],name) == 1) || (if_file_or_not(files[j],name) == 1)) {
                        print_ans_full_path(files[j]);
                    }
                }
            }

        }
        if(strcmp(command,"chmod") == 0) {
            parsing_the_command = strtok(NULL," ");
            int val = (int) (parsing_the_command[0] - '0');
            parsing_the_command = strtok(NULL," ");
            char * name = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
            for(int j = 0;j<SZ;j++) {
                if(if_file_or_not(files[j],name) == 1) {
                    files[j]->perm = val;
                    break;
                }
            }
        }
        if(strcmp(command,"ronly") == 0) {
            parsing_the_command = strtok(NULL," ");
            if(parsing_the_command != NULL) {
                char * dir = please_copy_my_char_array_or_i_will_be_ded(parsing_the_command);
                for(int j = 0;j<SZ;j++) {
                    if(if_dir_or_not(files[j],dir) == 1 && files[j]->perm == 4) {
                        print_ans_full_path(files[j]);
                    }
                } 
            } else {
                for(int j = 0;j<SZ;j++) {
                    if(files[j]->perm == 4) {
                        print_ans_full_path(files[j]);
                    }
                }
            }
        }
    }
}