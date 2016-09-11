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

    void NoticeAboutIncorrectLoginMessage() const;
    void NoticeAboutIncorrectFormatPasswordMessage() const;

    void NoticeAboutIncorrectDataMessage() const;
    void NoticeAboutIncorrectSum() const;

private:

    SystemUtility utility_;

};

#endif // NOTICE_ABOUT_ERROR_H
