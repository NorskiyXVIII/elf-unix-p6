#include "lib_elf.h"

int main(int argc, char* argv[]) {
    check_argc("Arguments count < 1\n");

    debug_info();
    elf_header elf;
    FILE* reader = fopen(argv[1], "r");
    check_open(reader, "Cannot open file[%s]\n");
    
    elf_to_struct(reader, &elf);
    print_elf_struct(&elf);



    fclose(reader);
    return 0; 
}