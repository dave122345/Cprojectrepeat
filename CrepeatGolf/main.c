#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct member {
    int number;
    char first_name[20];
    char second_name[20];
    char address[30];
    int annual_fee;
    int status;
    char email[30];
    int handicap;
    int bracket;
    int freq;
    int rest;
    int rate;
    struct member * next;
} member;


member* create_member() {
    int op;
    member* new_member = malloc(sizeof(member));
    new_member->next = NULL;
    printf(">Please enter the first name:\n");
    scanf("%s",new_member->first_name);
    
    printf(">Please enter the second name:\n");
    scanf("%s",new_member->second_name);
    
    printf(">Please enter the address:\n");
    scanf("%s",new_member->address);
    
    printf(">Please enter the annual fee:\n");
    scanf("%d",&new_member->annual_fee);
    
    printf(">Please enter the payment status:\n");
    printf("(0 for PAID / 1 for NOT PAID)\n");
    scanf("%d",&new_member->status);
    while(new_member->status <0 || new_member->status > 1){
        printf("Invalid Input!");
        return NULL;
    }
    
    printf(">Please enter the email address:\n");
    scanf("%s",new_member->email);
    
    printf(">Please enter the handicap condition:\n");
    printf("(0 for NOT HANDICAPPED / 1 for HANDICAPPED)\n");
    scanf("%d",&new_member->handicap);
    while(new_member->handicap <0 || new_member->handicap > 1){
        printf("Invalid Input!");
        return NULL;
    }
    
    printf(">Please enter the membership bracket:\n");
    printf("(0 for JUVENILLE / 1 for JUNIOR / 2 for STUDENT / 3 for FULL)\n");
    scanf("%d",&new_member->bracket);
    while(new_member->bracket <0 || new_member->bracket > 3){
        printf("Invalid Input!");
        return NULL;
    }
    
    printf(">Please enter the golf frequency in times per week:\n");
    printf("(0 for NEVER / 1 for ONCE / 2 for TWICE / 3 for MORE )\n");
    scanf("%d",&new_member->freq);
    while(new_member->freq <0 || new_member->freq > 3){
        printf("Invalid Input!");
        return NULL;
    }
    
    printf(">Please enter the restaurant frequency in times per week:\n");
    printf("(0 for NEVER / 1 for ONCE / 2 for TWICE / 3 for MORE )\n");
    scanf("%d",&new_member->rest);
    while(new_member->rest <0 || new_member->rest > 3){
        printf("Invalid Input!");
        return NULL;
    }
    
    printf(">How would you rate the pace of play on the course?\n");
    printf("(0 for BAD / 1 for DISAPPOINTING / 2 for SATISFACTORY / 3 for VERY GOOD / 4 for EXCELLENT )\n");
    scanf("%d",&new_member->rate);
    while(new_member->rate <0 || new_member->rate > 4){
        printf("Invalid Input!");
        return NULL;
    }
    
    return new_member;
}

void add_member(member* head){
    int count = 1;
    member * last = head;
    while(last->next != NULL){
        last = last->next;
        count = count + 1;
    }
    
    member* new_member = create_member();
    if (new_member == NULL){
        return;
    }
    new_member->number = count;
    last->next = new_member;
}

void display_member(member* head, int op, int number, char * name){
    member *tmp = head->next;
    while(tmp != NULL){
        //if the user wants to display the member by number
        //and the current member number is the same as the one passed to the function
        if ((op == 0) && (tmp->number == number)){
            break;
        }
        //if the user wants to display the member by name
        //and the member first name is the same as the one passed to the function
        if ((op == 1) && (strcmp(tmp->first_name, name) == 0)){
            break;
        }
        //the two ifs could be together in a single OR operand
        
        tmp = tmp->next;
    }
    
    if (tmp == NULL){
        printf("Member not registered!\n");
        return;
    }
    
    printf("\n==========================================\n");
    printf("Printing information about member number %d\n",tmp->number);
    printf("First Name: %s\n",tmp->first_name);
    printf("Second Name: %s\n",tmp->second_name);
    printf("Address: %s\n",tmp->address);
    printf("Annual Fee Value: %d\n",tmp->annual_fee);
    printf("Payment Status: %d\n",tmp->status);
    printf("(0 for PAID / 1 for NOT PAID)\n");
    printf("Email: %s\n",tmp->email);
    printf("Handicapped? %d\n",tmp->handicap);
    printf("(0 for NOT HANDICAPPED / 1 for HANDICAPPED)\n");
    printf("Bracket: %d\n",tmp->bracket);
    printf("(0 for JUVENILLE / 1 for JUNIOR / 2 for STUDENT / 3 for FULL)\n");
    printf("Frequency of Golf (in weeks): %d\n",tmp->freq);
    printf("(0 for NEVER / 1 for ONCE / 2 for TWICE / 3 for MORE )\n");
    printf("Frequency in the Restaurant (in weeks): %d\n",tmp->rest);
    printf("(0 for NEVER / 1 for ONCE / 2 for TWICE / 3 for MORE )\n");
    printf("Rating: %d\n",tmp->rate);
    printf("(0 for BAD / 1 for DISAPPOINTING / 2 for SATISFACTORY / 3 for VERY GOOD / 4 for EXCELLENT )\n");
    printf("==========================================\n\n");
}


void display_all(member* head) {
    member * tmp = head->next;
    while(tmp != NULL){
        if(tmp->status == 1){
            display_member(head, 0, tmp->number, NULL);
        }
        tmp = tmp->next;
    }
}

void update(member* head, int op, int number, char* name){
    member *pre = head;
    member *tmp = head->next;
    while(tmp != NULL){
        //if the user wants to display the member by number
        //and the current member number is the same as the one passed to the function
        if ((op == 0) && (tmp->number == number)){
            break;
        }
        //if the user wants to display the member by name
        //and the member first name is the same as the one passed to the function
        if ((op == 1) && (strcmp(tmp->first_name, name) == 0)){
            break;
        }
        //the two ifs could be together in a single OR operand
        
        pre = tmp;
        tmp = tmp->next;
    }
    
    if (tmp == NULL){
        printf("Member not registered!\n");
        return;
    }
    
    member* new_member = create_member();
    new_member->number = tmp->number;
    pre->next = new_member;
    new_member->next = tmp->next;
}

void delete(member* head, int number){
    member *pre = head;
    member *tmp = head->next;
    while(tmp != NULL){
        if (tmp->number == number){
            break;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    
    if (tmp == NULL){
        printf("Member not registered!\n");
        return;
    }
    
    //this line deletes tmp
    pre->next = tmp->next;
    
}

void statistics(member* head){
    int total = 0;
    int golf_n = 0;
    int golf_o = 0;
    int golf_t = 0;
    int golf_m = 0;
    int rest_n = 0;
    int rest_o = 0;
    int rest_t = 0;
    int rest_m = 0;
    
    member* tmp = head;
    while(tmp != NULL){
        if (tmp->freq == 0){
            golf_n++;
        }
        else if (tmp->freq == 1 ){
            golf_o++;
        }
        else if (tmp->freq == 2){
            golf_t++;
        }
        else if (tmp->freq == 3 ){
            golf_m++;
        }
        
        if (tmp->rest == 0 ){
            rest_n++;
        }
        else if (tmp->rest == 1 ){
            rest_o++;
        }
        else if (tmp->rest == 2){
            rest_t++;
            
        }
        else if (tmp->rest == 2){
            rest_m++;
        }
        total++;
        tmp = tmp->next;
    }
    
    printf("The percentage of people that NEVER play golf is: %.2f%%\n", (float)(golf_n*100/total));
    printf("The percentage of people that play golf ONCE a week is: %.2f%%\n", (float)(golf_o*100/total));
    printf("The percentage of people that play golf TWICE a week is: %.2f%%\n", (float)(golf_t*100/total));
    printf("The percentage of people that play golf more than TWICE a week is: %.2f%%\n", (float)(golf_m*100/total));
    printf("The percentage of people that NEVER use the club's restaurant is: %.2f%%\n", (float)(rest_n*100/total));
    printf("The percentage of people that use the club's restaurant ONCE a week is: %.2f%%\n", (float)(rest_o*100/total));
    printf("The percentage of people that use the club's restaurant TWICE a week is: %.2f%%\n", (float)(rest_t*100/total));
    printf("The percentage of people that use the club's restaurant more than TWICE a week is: %.2f%%\n", (float)(rest_m*100/total));
    
}

void save_file(member* head){
    FILE *f = fopen("file.txt", "w");
    if (f==NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    int total = 0;
    int golf_n = 0;
    int golf_o = 0;
    int golf_t = 0;
    int golf_m = 0;
    int rest_n = 0;
    int rest_o = 0;
    int rest_t = 0;
    int rest_m = 0;
    
    member* tmp = head;
    while(tmp != NULL){
        
        fprintf(f,"\n==========================================\n");
        fprintf(f,"Printing information about member number %d\n",tmp->number);
        fprintf(f,"First Name: %s\n",tmp->first_name);
        fprintf(f,"Second Name: %s\n",tmp->second_name);
        fprintf(f,"Address: %s\n",tmp->address);
        fprintf(f,"Annual Fee Value: %d\n",tmp->annual_fee);
        fprintf(f,"Payment Status: %d\n",tmp->status);
        fprintf(f,"(0 for PAID / 1 for NOT PAID)\n");
        fprintf(f,"Email: %s\n",tmp->email);
        fprintf(f,"Handicapped? %d\n",tmp->handicap);
        fprintf(f,"(0 for NOT HANDICAPPED / 1 for HANDICAPPED)\n");
        fprintf(f,"Bracket: %d\n",tmp->bracket);
        fprintf(f,"(0 for JUVENILLE / 1 for JUNIOR / 2 for STUDENT / 3 for FULL)\n");
        fprintf(f,"Frequency of Golf (in weeks): %d\n",tmp->freq);
        fprintf(f,"(0 for NEVER / 1 for ONCE / 2 for TWICE / 3 for MORE )\n");
        fprintf(f,"Frequency in the Restaurant (in weeks): %d\n",tmp->rest);
        fprintf(f,"(0 for NEVER / 1 for ONCE / 2 for TWICE / 3 for MORE )\n");
        fprintf(f,"Rating: %d\n",tmp->rate);
        fprintf(f,"(0 for BAD / 1 for DISAPPOINTING / 2 for SATISFACTORY / 3 for VERY GOOD / 4 for EXCELLENT )\n");
        fprintf(f,"==========================================\n\n");
        
        if (tmp->freq == 0){
            golf_n++;
        }
        else if (tmp->freq == 1 ){
            golf_o++;
        }
        else if (tmp->freq == 2){
            golf_t++;
        }
        else if (tmp->freq == 3 ){
            golf_m++;
        }
        
        if (tmp->rest == 0 ){
            rest_n++;
        }
        else if (tmp->rest == 1 ){
            rest_o++;
        }
        else if (tmp->rest == 2){
            rest_t++;
            
        }
        else if (tmp->rest == 2){
            rest_m++;
        }
        total++;
        tmp = tmp->next;
    }
    
    fprintf(f,"The percentage of people that NEVER play golf is: %.2f%%\n", (float)(golf_n*100/total));
    fprintf(f,"The percentage of people that play golf ONCE a week is: %.2f%%\n", (float)(golf_o*100/total));
    fprintf(f,"The percentage of people that play golf TWICE a week is: %.2f%%\n", (float)(golf_t*100/total));
    fprintf(f,"The percentage of people that play golf more than TWICE a week is: %.2f%%\n", (float)(golf_m*100/total));
    fprintf(f,"The percentage of people that NEVER use the club's restaurant is: %.2f%%\n", (float)(rest_n*100/total));
    fprintf(f,"The percentage of people that use the club's restaurant ONCE a week is: %.2f%%\n", (float)(rest_o*100/total));
    fprintf(f,"The percentage of people that use the club's restaurant TWICE a week is: %.2f%%\n", (float)(rest_t*100/total));
    fprintf(f,"The percentage of people that use the club's restaurant more than TWICE a week is: %.2f%%\n", (float)(rest_m*100/total));
    
}
int login(){
    FILE* fp;
    char line[100];
    char buffer[8][8];
    char user[8];
    char pass[8];
    int flag = 0;
    int i=0;
    char ch;
    
    if ((fp = fopen("login.txt", "r")) == NULL)
    {
        printf("No login.txt file!\n");
        return 0;
    }
    while (fgets(buffer[i], sizeof(line), fp)) {
        buffer[i][6] = '\0';
        i++;
    }
    
    printf("Please insert login name:\n");
    scanf("%s",&user);
    //note that here is i+2 to check only the logins, not the passwords
    i = 0;
    for(i=0;i<6;i=i+2){
        if(strcmp(buffer[i],user) == 0){
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("Invalid username.");
        return 0;
    }
    
    //asks for password
    printf("Please insert password for %s:\n", user);
    for(int j=0;j<6;j++){
        ch = getch();
        pass[j] = ch;
        ch = '*';
        printf("%c", ch);
    }
    if(strcmp(buffer[i+1],pass) != 0){
        printf("Password incorrect.");
        return 0;
    }
    
    printf("\n\n");
    fclose(fp);
    return 1;
}

void save_list(member* head){
    FILE* f = fopen("Memberships.txt", "wb");
    member* tmp = head->next;
    while(tmp != NULL){
        member current = *tmp;
        fwrite(&current, sizeof(struct member), 1, f);
        printf("Saved member %d to file.\n", current.number);
        tmp = tmp->next;
    }
}

int main(){
    //make user login
    //if (login()==0) {
    //    return 0;
    //}
    
    //load list
    FILE* f = fopen("Memberships.txt", "rb");
    //potentially no need for the malloc but needs to be allocated to new on the first run only
    member* head = malloc(sizeof(member));
    member* tail = head;
    int count = 0;
    while(1){
        int result;
        member *new = malloc(sizeof(member));
        result = fread(new, sizeof(struct member), 1, f);
        if (result != 1){
            if(feof(f)){
                break;
            }
            errno = ferror(f);
            perror("Could not read from file\n");
            exit(errno);
        }
        tail->next = new;
        tail = new;
        count++;
    }
    fclose(f);
    tail->next = NULL;
    printf("Loaded %d members into list!\n\n",count);
    
    //main menu
    int option = -1;
    while (option != 0){
        printf("====== SELECT AN OPTION BELOW ======\n");
        printf("1)Add Member\n");
        printf("2)Display All Members in Debt\n");
        printf("3)Display Member Details\n");
        printf("4)Update Member\n");
        printf("5)Delete Member\n");
        printf("6)Generate Statistics\n");
        printf("7)Print All Members into report file\n");
        printf("0)Exit\n\n");
        
        scanf("%d",&option);
        printf("\nOption %d selected\n\n",option);
        int op;
        int number;
        char name[20];
        switch(option){
            case 1:
                add_member(head);
                break;
            case 2:
                display_all(head);
                break;
            case 3:
                printf("====== SELECT AN OPTION BELOW ======\n");
                printf("1)Insert Member Number\n");
                printf("2)Insert Member Name\n");
                scanf("%d", &op);
                if(op == 1){
                    printf(">Enter member number: \n");
                    scanf("%d",&number);
                }else{
                    if(op == 2){
                        printf(">Enter member name: \n");
                        scanf("%s",name);
                    }else{
                        printf("Invalid option!");
                        break;
                    }
                }
                display_member(head, op-1, number, name);
                break;
            case 4:
                printf("====== SELECT AN OPTION BELOW ======\n");
                printf("1)Insert Member Number\n");
                printf("2)Insert Member Name\n");
                scanf("%i", &op);
                if(op == 1){
                    printf(">Enter member number: \n");
                    scanf("%d",&number);
                }else{
                    if(op == 2){
                        printf(">Enter member name: \n");
                        scanf("%s",name);
                    }else{
                        printf("Invalid option!");
                        break;
                    }
                }
                update(head, op-1, number, name);
                break;
            case 5:
                printf(">Enter member number: \n");
                scanf("%d",&number);
                delete(head, number);
                break;
            case 6:
                statistics(head);
                break;
            case 7:
                save_file(head);
                printf("Saved to file.txt\n");
                break;
            case 0:
                save_list(head);
                return 1;
            default:
                printf("==Please Select a valid Input==\n\n");
        }
    }
    return 0;
}
