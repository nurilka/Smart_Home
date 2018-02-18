#ifndef __ISUBSCRIBER_T_H__
#define __ISUBSCRIBER_T_H__

/** @file ISubscriber_t.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include "IData_t.h"


class ISubscriber_t
{
public:    
    ISubscriber_t() {}
    virtual ~ISubscriber_t() {}
    
    virtual void Update(IData_t* _pdata) = 0;

private:    
    ISubscriber_t(const ISubscriber_t& _other);
    ISubscriber_t& operator=(const ISubscriber_t& _other);
};


#endif /* __ISUBSCRIBER_T_H__ */
