#include <stdio.h>
#include <string.h>

struct PlayStruct
{
    int int_value;
    double double_value;
    char a_string[64];
};

void print_struct(struct PlayStruct ps, struct PlayStruct* pps);
void change_struct(struct PlayStruct ps, struct PlayStruct* pps);
void print_string(char string_to_print[]);
void change_string(char string1[], char* p_string);

int main(int argc, char const *argv[])
{
    struct PlayStruct play_struct;
    play_struct.int_value = 852;
    play_struct.double_value = 25.58;
    strcpy(play_struct.a_string, "Tomala Luca ");

    struct PlayStruct* play_struct_pointer;
    play_struct_pointer = &play_struct;
    /*
        Assign the adress from play_struct to play_struct_pointer can be usefull
        in the later programm
    */

    print_struct(play_struct, play_struct_pointer);

    change_struct(play_struct, play_struct_pointer);
    print_struct(play_struct, play_struct_pointer);
    /*
        Only the struct to which the pointer was pointing changed,
        because the first struct is passed by value, which is
        deleted the moment after the change_struct function terminates,
        and does not affect the original struct at all.
    */

    print_string(play_struct.a_string);
    char name[16];
    strcpy(name, "Luigi");
    change_string(play_struct.a_string, name);
    print_string(play_struct.a_string);
    print_string(name);
    /*
        The value of the struct is not changed because it only copied the content
        at function call.
        You can modifie the variable even it's not in the same function because
        the pointer points and the content of the address isn't changing.
    */

    return 0;
}

void print_struct(struct PlayStruct ps, struct PlayStruct* pps)
{
    printf("Values of struct ps: %d, %lf, %s\n", ps.int_value, ps.double_value, ps.a_string);
    printf("Values of struct pps: %d, %lf, %s\n", pps->int_value, pps->double_value, pps->a_string);
}

void change_struct(struct PlayStruct ps, struct PlayStruct* pps)
{
    ps.int_value = 4319;
    ps.double_value = 87.9654;
    strcpy(ps.a_string, "Daniel");

    pps->int_value = 6666;
    pps->double_value = 45.45454544;
    strcpy(pps->a_string, "Patrick");
}

void print_string(char string_to_print[])
{
    printf("%s\n", string_to_print);
}

void change_string(char string1[], char* p_string)
{
    string1[2]  = '\0';
    p_string[1] = '\0';
}
