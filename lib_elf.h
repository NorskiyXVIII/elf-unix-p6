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

#define EM_FX66		66		/* Siemens FX66 microcontroller */
#define EM_ST9PLUS	67		/* STMicroelectronics ST9+ 8/16 mc */
#define EM_ST7		68		/* STmicroelectronics ST7 8 bit mc */
#define EM_68HC16	69		/* Motorola MC68HC16 microcontroller */
#define EM_68HC11	70		/* Motorola MC68HC11 microcontroller */
#define EM_68HC08	71		/* Motorola MC68HC08 microcontroller */
#define EM_68HC05	72		/* Motorola MC68HC05 microcontroller */
#define EM_SVX		73		/* Silicon Graphics SVx */
#define EM_ST19		74		/* STMicroelectronics ST19 8 bit mc */
#define EM_VAX		75		/* Digital VAX */
#define EM_CRIS		76		/* Axis Communications 32-bit embedded processor */
#define EM_JAVELIN	77		/* Infineon Technologies 32-bit embedded processor */
#define EM_FIREPATH	78		/* Element 14 64-bit DSP Processor */
#define EM_ZSP		79		/* LSI Logic 16-bit DSP Processor */
#define EM_MMIX		80		/* Donald Knuth's educational 64-bit processor */
#define EM_HUANY	81		/* Harvard University machine-independent object files */
#define EM_PRISM	82		/* SiTera Prism */
#define EM_AVR		83		/* Atmel AVR 8-bit microcontroller */
#define EM_FR30		84		/* Fujitsu FR30 */
#define EM_D10V		85		/* Mitsubishi D10V */
#define EM_D30V		86		/* Mitsubishi D30V */
#define EM_V850		87		/* NEC v850 */
#define EM_M32R		88		/* Mitsubishi M32R */
#define EM_MN10300	89		/* Matsushita MN10300 */
#define EM_MN10200	90		/* Matsushita MN10200 */
#define EM_PJ		91		/* picoJava */
#define EM_OPENRISC	92		/* OpenRISC 32-bit embedded processor */
#define EM_ARC_A5	93		/* ARC Cores Tangent-A5 */
#define EM_XTENSA	94		/* Tensilica Xtensa Architecture */
#define EM_NUM		95

int is_elf(const elf_header* header) {
    if (header->e_ident[1] == 'E' && header->e_ident[2] == 'L' && header->e_ident[3]) return 1;
    
    return 0;
}

int elf_to_struct(FILE* fd, elf_header* header) {
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

    header->e_type      = getc(fd); //TYPE
    header->e_machine   = getc(fd); //ARCH
}

int open_elf(FILE* fd, char** argv, elf_header* header) {
    FILE* reader = fopen(argv[1], "r");
    check_open(reader, "Cannot open file[%s]\n");
    elf_to_struct(fd, header);
}

int print_elf_struct(const elf_header* header) {
    printf("ELF Header: \n");

    //magic
    printf("\tMagic: ");
    for (int i = 1; i < 16; i++)
        printf("%x ", header->e_ident[i]);
    printf("\n");

    // elf type
    switch (header->e_ident[4]) {
    case ELFCLASSNONE:
        printf("\tClass:\tUnknown[%d]\n", header->e_type);
        break;
    case ELFCLASS32:
        printf("\tClass:\tELF32\n");
        break;
    case ELFCLASS64:
        printf("\tClass:\tELF64\n");
        break;
    default:
        printf("\tClass:\tUnknown[%d]\n", header->e_type);
    }

    // data    
    switch (header->e_ident[5]) {
    case ELFDATANONE:
        printf("\tData:\tUnknown\n");
        break;
    case ELFDATA2LSB:
        printf("\tData:\tLittle endian\n");
        break;
    case ELFDATA2MSB:
        printf("\tData:\tBig endian\n");
        break;
    default:
        printf("\tData:\tUnknown[%d]\n", header->e_ident[5]);
    }

    // version
    if (header->e_ident[6] == EV_CURRENT)
        printf("\tVersion: %d (current)\n", header->e_ident[6]);
    else
        printf("\tVersion: Unknown[%d]\n", header->e_ident[6]);
    
    // os/abi
    printf("\tOS/ABI:\t");
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
            printf("Unknown[%d]\n", header->e_ident[7]);
    }

    // ABI
    printf("\tABI version: 0\n");

    // type
    printf("\tType:\t");
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
    printf("\tMachine: ");
    switch (header->e_machine) {
        case EM_NONE:
            printf("No machine\n");
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
        default:
            printf("Unknown\n");
    }
}

#endif