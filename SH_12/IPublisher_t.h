#ifndef __IPUBLISHER_T_H__
#define __IPUBLISHER_T_H__


/** @file IPublisher_t.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include "ISubscriber_t.h"

class IPublisher_t
{
public:    
    IPublisher_t() {}
    virtual ~IPublisher_t() {}
    
    virtual void AddSubscriber(ISubscriber_t* _sub) = 0;
    virtual void RemoveSubscriber(ISubscriber_t* _sub) = 0;
    
    virtual void Notify(IData_t* _data) = 0;

private:    
    IPublisher_t(const IPublisher_t& _other);
    IPublisher_t& operator=(const IPublisher_t& _other);
};


#endif /* __IPUBLISHER_T_H__ */
