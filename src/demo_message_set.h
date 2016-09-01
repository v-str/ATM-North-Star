#ifndef DEMO_MESSAGE_SET_H
#define DEMO_MESSAGE_SET_H

#include <string>

using string = std::string;

void WriteTextWithDelay(const string &text);

void ShowDemoMenu();
void ShowWelcomeDemoMessage();

void ShowDemoAccountInfoMsg();
void ShowInfoAboutRefillMsg();
void ShowDemoCreditAppMsg();
void ShowDemoWidthdrawalMsg();
void ShowDemoStatementMsg();

#endif  // DEMO_MESSAGE_SET_H
