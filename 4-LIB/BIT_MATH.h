#define Set_bit(var,bit_no) var=var|(1<<bit_no)
#define Clr_bit(var,bit_no) var=var&~(1<<bit_no)
#define Toggle_bit(var,bit_no) var=var^(1<<bit_no)
#define Get_bit(var,bit_no) (var>>bit_no)&1
