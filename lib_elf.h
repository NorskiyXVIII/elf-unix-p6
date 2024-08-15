#ifndef PSIX__LIB__ELF__H
#define PSIX__LIB__ELF__H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define check_argc(strerr)     \
    if (argc <= 1) {            \
        fprintf(stderr, strerr); \
        return 1;                 \
    }

#define debug_info()                         \
    printf("---------DEBUG INFO---------\n"); \
    printf("argc count: %d\n", argc);          \
    for(int i = 1; i < argc; i++) {             \
        printf("argv[%d] = %s\n", i, argv[i]);   \
    }                                             \
    printf("---------DEBUG INFO---------\n");      \

#define check_open(reader, strerr) \
    if (reader == NULL) {\
        fprintf(stderr, strerr, argv[1]);\
        return 2;\
    }


// FROM GNU
typedef uint16_t Elf32_Half; // 16bit
// unsigned and signed 32bit
typedef uint32_t Elf32_Word;
typedef	int32_t  Elf32_Sword; 
//unsigned and signed 32bit
typedef uint64_t Elf32_Xword;
typedef	int64_t  Elf32_Sxword;

// address types
typedef uint32_t Elf32_Addr;

// file offset types
typedef uint32_t Elf32_Off;

// sections???
typedef uint16_t Elf32_Section;

// ver sim
typedef Elf32_Half Elf32_Versym;


/* The ELF file header.  This appears at the start of every ELF file.  */
#define EI_NIDENT (16)


typedef struct {
  unsigned char	e_ident[EI_NIDENT];	/* Magic number and other info */
  Elf32_Half	e_type;			    /* Object file type */
  Elf32_Half	e_machine;		    /* Architecture */
  Elf32_Word	e_version;		    /* Object file version */
  Elf32_Addr	e_entry;		    /* Entry point virtual address */
  Elf32_Off	    e_phoff;		    /* Program header table file offset */
  Elf32_Off	    e_shoff;		    /* Section header table file offset */
  Elf32_Word	e_flags;		    /* Processor-specific flags */
  Elf32_Half	e_ehsize;		    /* ELF header size in bytes */
  Elf32_Half	e_phentsize;		/* Program header table entry size */
  Elf32_Half	e_phnum;		    /* Program header table entry count */
  Elf32_Half	e_shentsize;		/* Section header table entry size */
  Elf32_Half	e_shnum;		    /* Section header table entry count */
  Elf32_Half	e_shstrndx;		    /* Section header string table index */
} elf_header;

typedef struct {
    Elf32_Word	p_type;			/* Segment type */
    Elf32_Off	p_offset;		/* Segment file offset */
    Elf32_Addr	p_vaddr;		/* Segment virtual address */
    Elf32_Addr	p_paddr;		/* Segment physical address */
    Elf32_Word	p_filesz;		/* Segment size in file */
    Elf32_Word	p_memsz;		/* Segment size in memory */
    Elf32_Word	p_flags;		/* Segment flags */
    Elf32_Word	p_align;		/* Segment alignment */
} elf32_phdr;

// classes
#define ELFCLASSNONE (0)
#define ELFCLASS32   (1)
#define ELFCLASS64   (2)

// data
#define ELFDATANONE (0)
// little endian
#define ELFDATA2LSB (1)
// big endian
#define ELFDATA2MSB (2)

// ELF version
#define EV_CURRENT (1)

// OS/ABI
#define ELFOSABI_NONE	  (0)	//UNIX System V ABI
#define ELFOSABI_HPUX	  (1)	//HP-UX
#define ELFOSABI_NETBSD	  (2)	//NetBSD
#define ELFOSABI_GNU	  (3)  //GNU/Linux
#define ELFOSABI_SOLARIS  (6)  //Solaris
#define ELFOSABI_AIX	  (7)  //AIX
#define ELFOSABI_IRIX	  (8)  //IRIX
#define ELFOSABI_FREEBSD  (9)  //FreeBSD
#define ELFOSABI_TRU64	  (10) //Tru64 UNIX
#define ELFOSABI_MODESTO  (11) //Modesto
#define ELFOSABI_OPENBSD  (12) //OpenBSD
#define ELFOSABI_OPENVMS  (13) //OpenVMS
#define ELFOSABI_NSK	  (14) //Non-Stop Kernel
#define ELFOSABI_AROS	  (15) //Amiga Research OS
#define ELFOSABI_FENIXOS  (16) //FenixOS
#define ELFOSABI_CLOUDABI (17) //CloudABI
#define ELFOSABI_OPENVOS  (18) //OpenVOS

// file type
#define ET_NONE   (0)
#define ET_REL    (1)
#define ET_EXEC   (2)
#define ET_DYN    (3)
#define ET_CORE   (4)

#define ET_LOOS   (65024)
#define ET_HIOS   (65279)

#define ET_LOPROC (65280)
#define ET_HIPROC (65535)

// ARCH
#define EM_NONE		 0		/* No machine */
#define EM_M32		 1		/* AT&T WE 32100 */
#define EM_SPARC	 2		/* SUN SPARC */
#define EM_386		 3		/* Intel 80386 */
#define EM_68K		 4		/* Motorola m68k family */
#define EM_88K		 5		/* Motorola m88k family */
#define EM_860		 7		/* Intel 80860 */
#define EM_MIPS		 8		/* MIPS R3000 big-endian */
#define EM_S370		 9		/* IBM System/370 */
#define EM_MIPS_RS3_LE	10		/* MIPS R3000 little-endian */

#define EM_PARISC	15		/* HPPA */
#define EM_VPP500	17		/* Fujitsu VPP500 */
#define EM_SPARC32PLUS	18		/* Sun's "v8plus" */
#define EM_960		19		/* Intel 80960 */
#define EM_PPC		20		/* PowerPC */
#define EM_PPC64	21		/* PowerPC 64-bit */
#define EM_S390		22		/* IBM S390 */

#define EM_V800		36		/* NEC V800 series */
#define EM_FR20		37		/* Fujitsu FR20 */
#define EM_RH32		38		/* TRW RH-32 */
#define EM_RCE		39		/* Motorola RCE */
#define EM_ARM		40		/* ARM */
#define EM_FAKE_ALPHA	41		/* Digital Alpha */
#define EM_SH		42		/* Hitachi SH */
#define EM_SPARCV9	43		/* SPARC v9 64-bit */
#define EM_TRICORE	44		/* Siemens Tricore */
#define EM_ARC		45		/* Argonaut RISC Core */
#define EM_H8_300	46		/* Hitachi H8/300 */
#define EM_H8_300H	47		/* Hitachi H8/300H */
#define EM_H8S		48		/* Hitachi H8S */
#define EM_H8_500	49		/* Hitachi H8/500 */
#define EM_IA_64	50		/* Intel Merced */
#define EM_MIPS_X	51		/* Stanford MIPS-X */
#define EM_COLDFIRE	52		/* Motorola Coldfire */
#define EM_68HC12	53		/* Motorola M68HC12 */
#define EM_MMA		54		/* Fujitsu MMA Multimedia Accelerator*/
#define EM_PCP		55		/* Siemens PCP */
#define EM_NCPU		56		/* Sony nCPU embeeded RISC */
#define EM_NDR1		57		/* Denso NDR1 microprocessor */
#define EM_STARCORE	58		/* Motorola Start*Core processor */
#define EM_ME16		59		/* Toyota ME16 processor */
#define EM_ST100	60		/* STMicroelectronic ST100 processor */
#define EM_TINYJ	61		/* Advanced Logic Corp. Tinyj emb.fam*/
#define EM_X86_64	62		/* AMD x86-64 architecture */
#define EM_PDSP		63		/* Sony DSP Processor */

#define EM_MCST_ELBRUS (0xAF)
#define EM_TI_C6000    (0x8C)
#define EM_AARCH64     (0xB7)
#define EM_RISCV       (0XF3)
#define EM_BPF         (0xF7)
#define EM_65816       (0x101)

// e_version
#define EV_NONE    (0)
#define EV_CURRENT (1)

int is_elf(const elf_header* header) {
    if (header->e_ident[1] == 'E' && header->e_ident[2] == 'L' && header->e_ident[3]) return 1;
    
    return 0;
}

int elf_to_struct(FILE* fd, elf_header* header, elf32_phdr* h_tab) {
    // MAGIC NUMBERS
    header->e_ident[0]  = getc(fd); //0
    header->e_ident[1]  = getc(fd); //E
    header->e_ident[2]  = getc(fd); //L
    header->e_ident[3]  = getc(fd); //F
    header->e_ident[4]  = getc(fd); //CLASS
    header->e_ident[5]  = getc(fd); //DATA
    header->e_ident[6]  = getc(fd); //VERSION
    header->e_ident[7]  = getc(fd); //OSABI
    header->e_ident[8]  = getc(fd); //ABIVERSION
    header->e_ident[9]  = getc(fd); //PAD
    header->e_ident[10] = getc(fd); //PAD
    header->e_ident[11] = getc(fd); //PAD
    header->e_ident[12] = getc(fd); //PAD
    header->e_ident[13] = getc(fd); //PAD
    header->e_ident[14] = getc(fd); //PAD
    header->e_ident[15] = getc(fd); //PAD

    unsigned char* elf_addr_ptr = &(header->e_type);
    elf_addr_ptr[0] = getc(fd); //TYPE //16
    elf_addr_ptr[1] = getc(fd); //TYPE //17

    elf_addr_ptr = &(header->e_machine);
    elf_addr_ptr[0] = getc(fd); //ARCH //18
    elf_addr_ptr[1] = getc(fd); //ARCH //19

    elf_addr_ptr = &(header->e_version);
    elf_addr_ptr[0] = getc(fd); //VER //20
    elf_addr_ptr[1] = getc(fd); //VER //21
    elf_addr_ptr[2] = getc(fd); //VER //22
    elf_addr_ptr[2] = getc(fd); //VER //23

    elf_addr_ptr = &(header->e_entry);
    elf_addr_ptr[0] = getc(fd); //ENTRY_POINT //24
    elf_addr_ptr[1] = getc(fd); //ENTRY_POINT //25
    elf_addr_ptr[2] = getc(fd); //ENTRY_POINT //26
    elf_addr_ptr[3] = getc(fd); //ENTRY_POINT //27

    elf_addr_ptr = &(header->e_phoff);
    elf_addr_ptr[0] = getc(fd); //PHOFF //28
    elf_addr_ptr[1] = getc(fd); //PHOFF //29
    elf_addr_ptr[2] = getc(fd); //PHOFF //30
    elf_addr_ptr[3] = getc(fd); //PHOFF //31

    elf_addr_ptr = &(header->e_shoff);
    elf_addr_ptr[0] = getc(fd); //SHOFF //32
    elf_addr_ptr[1] = getc(fd); //SHOFF //33
    elf_addr_ptr[2] = getc(fd); //SHOFF //34
    elf_addr_ptr[3] = getc(fd); //SHOFF //35

    elf_addr_ptr = &(header->e_flags);
    elf_addr_ptr[0] = getc(fd); //FLAGS //36
    elf_addr_ptr[1] = getc(fd); //FLAGS //37
    elf_addr_ptr[2] = getc(fd); //FLAGS //38
    elf_addr_ptr[3] = getc(fd); //FLAGS //39

    elf_addr_ptr = &(header->e_ehsize);
    elf_addr_ptr[0] = getc(fd); //EHSIZE //40
    elf_addr_ptr[1] = getc(fd); //EHSIZE //41
    elf_addr_ptr = &(header->e_phentsize);
    elf_addr_ptr[0] = getc(fd); //PHENTSIZE //42
    elf_addr_ptr[1] = getc(fd); //PHENTSIZE //43
    elf_addr_ptr = &(header->e_phnum);
    elf_addr_ptr[0] = getc(fd); //44
    elf_addr_ptr[1] = getc(fd); //45
    elf_addr_ptr = &(header->e_shentsize);
    elf_addr_ptr[0] = getc(fd); //46
    elf_addr_ptr[1] = getc(fd); //47
    elf_addr_ptr = &(header->e_shnum);
    elf_addr_ptr[0] = getc(fd); //48
    elf_addr_ptr[1] = getc(fd); //49
    elf_addr_ptr = &(header->e_shstrndx);
    elf_addr_ptr[0] = getc(fd); //50
    elf_addr_ptr[1] = getc(fd); //51

    //next table head
    for (int i = 51; i <= header->e_phoff; i++) getc(fd);

    elf_addr_ptr = &(h_tab->p_type);
    elf_addr_ptr[0] = getc(fd);
    elf_addr_ptr[1] = getc(fd);
    elf_addr_ptr[2] = getc(fd);
    elf_addr_ptr[3] = getc(fd);
}

//atphoff


/*int open_elf(FILE* fd, char** argv, elf_header* header) {
    FILE* reader = fopen(argv[1], "r");
    check_open(reader, "Cannot open file[%s]\n");
    elf_to_struct(fd, header);
}*/

int print_elf_struct(const elf_header* header, const elf32_phdr* h_tab) {
    printf("ELF Header: \n");

    //magic
    printf("\tMagic: ");
    for (int i = 1; i < 16; i++)
        printf("%x ", header->e_ident[i]);
    printf("\n");

    // elf type
    switch (header->e_ident[4]) {
    case ELFCLASSNONE:
        printf("\tClass:\t\t\t\t\tUnknown[%x]\n", header->e_type);
        break;
    case ELFCLASS32:
        printf("\tClass:\t\t\t\t\tELF32\n");
        break;
    case ELFCLASS64:
        printf("\tClass:\t\t\t\t\tELF64\n");
        break;
    default:
        printf("\tClass:\t\t\t\t\tUnknown[%x]\n", header->e_type);
    }

    // data    
    switch (header->e_ident[5]) {
    case ELFDATANONE:
        printf("\tData:\t\t\t\t\tUnknown\n");
        break;
    case ELFDATA2LSB:
        printf("\tData:\t\t\t\t\tLittle endian\n");
        break;
    case ELFDATA2MSB:
        printf("\tData:\t\t\t\t\tBig endian\n");
        break;
    default:
        printf("\tData:\t\t\t\t\tUnknown[%x]\n", header->e_ident[5]);
    }

    // version
    if (header->e_ident[6] == EV_CURRENT)
        printf("\tVersion:\t\t\t\t%d (current)\n", header->e_ident[6]);
    else
        printf("\tVersion:\t\t\t\tUnknown[%d]\n", header->e_ident[6]);
    
    // os/abi
    printf("\tOS/ABI:\t\t\t\t\t");
    switch (header->e_ident[7]) {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP - UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_GNU:
            printf("GNU ELF\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("Tru64 UNIX\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Modesto\n");
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        case ELFOSABI_OPENVMS:
            printf("OpenVMS\n");
            break;
        case ELFOSABI_NSK:
            printf("Non - Stop Kernel\n");
            break;
        case ELFOSABI_AROS:
            printf("Amiga Research OS\n");
            break;
        case ELFOSABI_FENIXOS:
            printf("FenixOS\n");
            break;
        case ELFOSABI_CLOUDABI:
            printf("CloudABI\n");
            break;
        case ELFOSABI_OPENVOS:
            printf("OpenVOS\n");
            break;
        default:
            printf("Unknown[%x]\n", header->e_ident[7]);
    }

    // ABI
    printf("\tABI version:\t\t\t\t%d\n", header->e_ident[8]);

    // type
    printf("\tType:\t\t\t\t\t");
    switch(header->e_type) {
        case ET_NONE:
            printf("Unknown\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            if (header->e_type >= ET_LOOS && header->e_type <= ET_HIOS)
                printf("Reserved inclusive range. Operating system specific\n");
            else if (header->e_type >= ET_LOPROC && header->e_type <= ET_HIPROC)
                printf("Reserved inclusive range. Processor specific.\n");
            else
                printf("Unknown\n");
    }

    // machine
    printf("\tMachine:\t\t\t\t", header->e_machine);
    switch (header->e_machine) {
        case EM_NONE:
            printf("Advanced Micro Devices X86-64\n");
            break;
        case EM_M32:
            printf("AT&T WE 32100\n");
            break;
        case EM_SPARC:
            printf("SUN SPARC\n");
            break;
        case EM_386:
            printf("Intel 80386\n");
            break;
        case EM_68K:
            printf("Motorola m68k family\n");
            break;
        case EM_88K:
            printf("Motorola m88k family\n");
            break;
        case EM_860: 
            printf("Intel 80860\n");
            break;
        case EM_MIPS:
            printf("MIPS R3000 big-endian\n");
            break;
        case EM_S370: 
            printf("IBM System/370");
            break;
        case EM_MIPS_RS3_LE:
            printf("MIPS R3000 little-endian\n");
            break;
        case EM_PARISC:
            printf("Hewlett-Packard PA-RISC\n");
            break;
        case EM_960:
            printf("Intel 80960\n");
            break;
        case EM_PPC:
            printf("PowerPC\n");
            break;
        case EM_PPC64:
            printf("PowerPC (64-bit)\n");
            break;
        case EM_S390:
            printf("S390, including S390x\n");
            break;
        case EM_V800:
            printf("IBM SPU/SPC\n");
            break;
        case EM_FR20:
            printf("Fujitsu FR20\n");
            break;
        case EM_RH32:
            printf("TRW RH-32\n");
            break;
        case EM_RCE:
            printf("Motorola RCE\n");
            break;
        case EM_ARM:
            printf("ARM (up to ARMv7/Aarch32)\n");
            break;
        case EM_FAKE_ALPHA:
            printf("Digital Alpha\n");
            break;
        case EM_SH:
            printf("SuperH\n");
            break;
        case EM_SPARCV9:
            printf("SPARC Version 9\n");
            break;
        case EM_TRICORE:
            printf("Siemens TriCore embedded processor\n");
            break;
        case EM_ARC:
            printf("Argonaut RISC Core\n");
            break;
        case EM_H8_300:
            printf("Hitachi H8/300\n");
            break;
        case EM_H8_300H:
            printf("Hitachi H8/300H\n");
            break;
        case EM_H8S:
            printf("Hitachi H8S\n");
            break;
        case EM_H8_500:
            printf("Hitachi H8/500\n");
            break;
        case EM_IA_64:
            printf("IA-64\n");
            break;
        case EM_MIPS_X:
            printf("Stanford MIPS-X\n");
            break;
        case EM_COLDFIRE:
            printf("Motorola ColdFire\n");
            break;
        case EM_68HC12:
            printf("Motorola M68HC12\n");
            break;
        case EM_MMA:
            printf("Fujitsu MMA Multimedia Accelerator\n");
            break;
        case EM_PCP:
            printf("Siemens PCP\n");
            break;
        case EM_NCPU:
            printf("Sony nCPU embedded RISC processor\n");
            break;
        case EM_NDR1:
            printf("Denso NDR1 microprocessor\n");
            break;
        case EM_STARCORE:
            printf("Motorola Star*Core processor\n");
            break;
        case EM_ME16:
            printf("Toyota ME16 processor\n");
            break;
        case EM_ST100:
            printf("STMicroelectronics ST100 processor\n");
            break;
        case EM_TINYJ:
            printf("Advanced Logic Corp. TinyJ embedded processor family\n");
            break;
        case EM_X86_64:
            printf("x86-64\n");
            break;
        case EM_MCST_ELBRUS:
            printf("Elbrus (proc arch)\n");
            break;
        case EM_TI_C6000:
            printf("TMS320C6000 Family\n");
            break;
        case EM_AARCH64:
            printf("ARM 64-bits (ARMv8/Aarch64)\n");
            break;
        case EM_RISCV:
            printf("RISC-V\n");
            break;
        case EM_BPF:
            printf("Berkeley Packet Filter\n");
            break;
        case EM_65816:
            printf("WDC 65C816\n");
            break;
        default:
            printf("Unknown (%d)\n", header->e_machine);
    }

    // version
    if (header->e_version != 1)
        printf("\tVersion:\t\t\t\t0x1\n");
    else 
        printf("\tVersion:\t\t\t\t0x%x!\n", header->e_version);

    // version
    printf("\tEntry:\t\t\t\t\t0x%x\n", header->e_entry);

    //start of program headers

    printf("\tStart of program headers:\t\t%d", header->e_phoff);
    
    if (header->e_phoff < 10 && header->e_phoff < header->e_shoff) 
        printf("  (bytes into file)\n");
    else 
        printf(" (bytes into file)\n");
    //start of section headers
    printf("\tStart of section headers:\t\t%d (bytes into file)\n", header->e_shoff);
    //flags
    printf("\tFlags:\t\t\t\t\t0x%x\n", header->e_flags);
    //size of this headers
    printf("\tSize of this headers:\t\t\t%d (bytes)\n", header->e_ehsize);
    //size of program headers
    printf("\tSize of program headers:\t\t%d (bytes)\n", header->e_phentsize);
    //numofprhd
    printf("\tNumber of program headers:\t\t%d\n", header->e_phnum);
    //shentsize
    printf("\tSize of section headers:\t\t%d\n", header->e_shentsize);
    //num of sec headers
    printf("\tNumber of section headers:\t\t%d\n", header->e_shnum);
    //sect head str tabl idnx
    printf("\tSection header string table index:\t%d\n", header->e_shstrndx);

    if (header->e_shentsize == 0 && header->e_shnum == 1) 
        printf("readelf32_p6: \n\t\
        Warning: possibly corrupt ELF header - it has a non-zero program header offset, but no program headers\n");
    
    printf("h_tab->p_type = %d\n", h_tab->p_type);

}

#endif