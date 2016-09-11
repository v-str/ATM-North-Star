#ifndef NOTICE_ABOUT_ERROR_H
#define NOTICE_ABOUT_ERROR_H

#include <iostream>
#include "system_utility.h"

using std::cout;
using std::cin;

class NoticeAboutError
{
public:
    NoticeAboutError();

    void ShowIncorrectLoginMessage() const;
private:

    SystemUtility utility_;

};

#endif // NOTICE_ABOUT_ERROR_H
