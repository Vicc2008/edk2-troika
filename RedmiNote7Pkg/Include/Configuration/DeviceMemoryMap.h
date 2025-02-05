#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 64

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, MaxMem } DeviceMemoryAddHob;

typedef struct {
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
  DeviceMemoryAddHob           HobOption;
  EFI_MEMORY_TYPE              MemoryType;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Address,	  Length,     ResourceType, Resource Attribute, ARM MMU
       Attribute,                  HobOption, EFI Memory Type */
    /*  DDR  */
    /*  DXE Heap  */    
    {0x80C50000, 0x0F3B0000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},
    /*  Display Reserved  */
    {0xEC000000, 0x0085A000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH,
     AddMem, EfiMaxMemoryType},
    /*  UEFI FD  */
    {0x90000000, 0x00300000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  CPU Vectors  */
    {0x80002000, 0x00001000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  UEFI Stack  */
    {0x80003000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},

    /*  HLOS  */
    {0x90700000, 0x2B500000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},

    /* OTHER MEMORY REGIONS */

    /*  REGISTERS  */

    /* Terminator for MMU*/
    {0},
    /* Terminator for LibMem */
    { 0xFFFFFFFF, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, 
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, 
     AddDev, EfiMemoryMappedIO}

};

#endif
