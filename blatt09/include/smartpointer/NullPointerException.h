/**
 * @file NullPointerException.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H


/**
 * @brief NullPointerException welche ausgelöst wird, wenn bei der Dereferenzierung eines “leeren” Smartpointers, dessen interner Objektzeiger pObj ein nullptr ist.
 * 
 */
class NullPointerException : public std::runtime_error{
public:

    NullPointerException(): runtime_error( "NullPointerException: Bei der Dereferenzierung eines “leeren” Smartpointers, ist dessen interner Objektzeiger pObj ein nullptr" ) {}
};


#endif /* NULLPOINTEREXCEPTION_H */
