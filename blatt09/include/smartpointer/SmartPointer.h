/*
 * SmartPointer.h
 *
 */

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "smartpointer/RefCounter.h"
#include "smartpointer/NullPointerException.h"


/**
 * Template class to represent smart pointers (like std::shared_ptr)
 */
template<class T>
class SmartPointer {
public:
    /**
     * Constructor
     *
     * Constructs a new smart pointer from a raw pointer, sets the reference
     * counter to 1.
     *
     * @param p is a raw pointer to the object to be shared
     */
    SmartPointer(T * const p = nullptr){
        rc->inc();
        pObj = p;
    }

    /**
     * Copy constructor
     *
     * Constructs a new smart pointer from another smart pointer, increments the
     * reference counter.
     *
     * @param p is another smart pointer
     */
    SmartPointer(const SmartPointer& p){
        rc = p.rc;
        pObj = p.pObj;
    }

    /**
     * Destructor
     *
     * Decrements the reference counter. If it reaches zero, the shared object will
     * be free'd.
     */
    virtual ~SmartPointer(){
        rc->dec();
        if(rc->isZero()){
            free(pObj);
        }
    }

    /**
     * Dereferences the smart pointer
     *
     * @return a pointer to the shared object
     */
    T *operator->() const{
        if(pObj == nullptr){
            throw NullPointerException();
        }else{
            return pObj;
        }
    }

    /**
     * Dereferences the smart pointer
     *
     * @return a reference to the shared object
     */
    T &operator*() const{
        if(pObj == nullptr){
            throw NullPointerException();
        }else{
            return &pObj;
        }
    }

    /**
     * Assignment
     *
     * Changes the shared object, thus we need first to do the same
     * like the destructor, then something like the constructor.
     *
     * @param p raw pointer to the new object
     */
    const SmartPointer &operator=(T * const p){
        free(pObj);
        pObj = p;
    }

    /**
     * Assignment
     *
     * Changes the shared object, thus we need first to do the same
     * like the destructor, then something like the copy constructor.
     *
     * @param p is another smart pointer
     */
    const SmartPointer &operator=(const SmartPointer& p){
        free(pObj);
        pObj = p.pObj;
    }

    /**
     * Comparison
     *
     * @return true, if `p` shares the same object
     */
    bool operator==(const SmartPointer& p) const{
        if(pObj == p.pObj){
            return true;
        }else {
            return false;
        }
    }

    /**
     * Comparison
     *
     * @return true, if `p` does not shares the same object
     */
    bool operator!=(const SmartPointer& p) const{
        if(pObj != p.pObj){
            return true;
        }else {
            return false;
        }
    }

    /**
     * Boolean context
     *
     * @return true, if we have a shared object; false otherwise
     */
    operator bool() const{
        if(pObj != nullptr){
            return true;
        }else{
            return false;
        }
    }

private:
    T* pObj;            ///< Pointer to the current shared object
    RefCounter* rc;     ///< Pointer to the reference counter (used for the current object)
};


#endif  // SMARTPOINTER_H

