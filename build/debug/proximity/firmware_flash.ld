MEMORY
{
  conf1 : org = 0x08000000, len = 0
  conf2 : org = 0x08000000 + 0, len = 0
  flash : org = 0x08000000 + 0 + 0, len = 128K - 0 - 0
  ram0 : org = 0x20000000, len = 32K
  ram1 : org = 0x00000000, len = 0
  ram2 : org = 0x00000000, len = 0
  ram3 : org = 0x00000000, len = 0
  ram4 : org = 0x10000000, len = 64K
  ram5 : org = 0x00000000, len = 0
  ram6 : org = 0x00000000, len = 0
  ram7 : org = 0x00000000, len = 0
}
REGION_ALIAS("MAIN_STACK_RAM", ram0);
REGION_ALIAS("PROCESS_STACK_RAM", ram0);
REGION_ALIAS("DATA_RAM", ram0);
REGION_ALIAS("BSS_RAM", ram0);
REGION_ALIAS("HEAP_RAM", ram0);
_conf1_address_bottom = ORIGIN(conf1);
_conf1_address_top = ORIGIN(conf1) + LENGTH(conf1);
PROVIDE(conf1_address_bottom = _conf1_address_bottom);
PROVIDE(conf1_address_top = _conf1_address_top);
_conf2_address_bottom = ORIGIN(conf2);
_conf2_address_top = ORIGIN(conf2) + LENGTH(conf2);
PROVIDE(conf2_address_bottom = _conf2_address_bottom);
PROVIDE(conf2_address_top = _conf2_address_top);
INCLUDE rules.ld
