

#include "arm/arm.h"
#include "utils/utils.h"
#include "exception.h"
#include "trapFrame.h"

#include "syscall/syscall.h"

void exception_sync_el0_handler(TRAP_FRAME* trap_frame) {

    U64 esr = utils_read_sysreg(esr_el1);
    U32 ec = ESR_ELx_EC(esr);

    switch (ec)
    {
    // using svc instruction
    case ESR_ELx_EC_SVC64:
        syscall_handler(trap_frame);
        break;
    
    default:
        break;
    }

}
