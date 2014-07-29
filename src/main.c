#include <stdint.h>
#include <string.h>

#include "qm/qm_leds.h"
#include "node/bsp.h"

/* Local-scope objects -----------------------------------------------------*/


static QEvt const *l_qm_leds_QSto[10];      /* Event queue storage for Blinky */


static QF_MPOOL_EL(QEvt) l_qmlPoolSto[10];
static QF_MPOOL_EL(general_evt) l_general_pool[5];

static QSubscrList    l_subscrSto[MAX_SIG];
/*..........................................................................*/
void main() 
{   
    bsp_init();
    serial_init();
    
    QF_init();    

    qm_leds_ctor();
    
    /* initialize the event pools... */
    QF_poolInit(l_qmlPoolSto, sizeof(l_qmlPoolSto), sizeof(l_qmlPoolSto[0]));
    QF_poolInit(l_general_pool, sizeof(l_general_pool), sizeof(l_general_pool[0]));

    /* init publish-subscribe */
    QF_psInit(l_subscrSto, Q_DIM(l_subscrSto));
                  
    QACTIVE_START(ao_qm_leds,
                  2U,
                  l_qm_leds_QSto, Q_DIM(l_qm_leds_QSto),
                  (void *)0, 0U, 
                  (QEvt *)0);

    QF_run();                              /* run the QF application */
  
}

/**
 * @}
 */
