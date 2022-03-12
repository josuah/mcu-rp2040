#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FIELD(reg, fld)		(((reg) & fld##_Msk) >> fld##_Pos)

/* halt the execution */
void __stop_program(void);

#endif
