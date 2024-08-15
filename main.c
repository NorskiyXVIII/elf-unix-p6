#include "lib_elf.h"

int main(int argc, char* argv[]) {
    check_argc("Arguments count < 1\n");

    debug_info();
    elf_header elf;
    elf32_phdr e_tab;
    FILE* reader = fopen(argv[1], "r");
    check_open(reader, "Cannot open file[%s]\n");
    
    elf_to_struct(reader, &elf, &e_tab);
    print_elf_struct(&elf, &e_tab);



    fclose(reader);
    return 0; 
}