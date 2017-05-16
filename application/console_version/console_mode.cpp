#include <console_mode.h>

#include <initial_messenger.h>
#include <output_setup.h>
#include <user_messenger.h>

// =========== New Code ==============
#include <atm.h>
#include <user_input_processor.h>

// new code
ConsoleMode::ConsoleMode() : atm_(new Atm()) {}
// new code
ConsoleMode::~ConsoleMode() { delete atm_; }

void ConsoleMode::RunInitialScreen() {
  OutputSetup::SetupTwoStreamsForOutput();
  InitialMessenger::DisplayInitialScreen();
  RunProgram();
}

void ConsoleMode::RunProgram() {
  RunSectionBasedOn(UserInputProcessor::GetMenuItem());

  if (IsCorrectRegistration()) {
    MainProgramMenu();
  }

  EndProgram();
}

void ConsoleMode::RunSectionBasedOn(int user_choice) {
  if (user_choice == kDemo) {
    DemoMenu();
  } else if (user_choice == kRegistration) {
    RegistrateUser();
  } else if (user_choice == kQuit) {
  } else {
    ShowIncorrectRegistration();
  }
}

void ConsoleMode::DemoMenu() {
  demo_mode_.ShowDemoMode();
  if (demo_mode_.UserWantToRegistrate()) {
    RegistrateUser();
  }
}

void ConsoleMode::RegistrateUser() { registrator_.RegisterUser(user_); }

void ConsoleMode::MainProgramMenu() {
  do {
    UserMessenger::ShowMainMenu();
    ExecuteOperation(UserInputProcessor::GetMenuItem());
  } while (!user_want_to_exit_);
}

void ConsoleMode::ExecuteOperation(int user_choice) {
  if (user_choice == kAccount) {
    account_informator_.DisplayAccountInformationFor(&user_);
  } else if (user_choice == kRefill) {
    refill_.StartRefillOperationFor(&user_);
  } else if (user_choice == kCredit) {
    credit_department_.StartCreditOperationFor(&user_);
  } else if (user_choice == kWidthdrawal) {
    withdrawal_.WithdrawCashFrom(&user_);
  } else if (user_choice == kStatement) {
    statement_.ShowStatementFor(&user_);
  } else if (user_choice == kExitProgram) {
    UserMessenger::ReRequestAboutExit();
  } else {
    UserMessenger::ShowIncorrectMainMenuInput();
    user_want_to_exit_ = false;
  }
  SuggestToExit();
}

void ConsoleMode::SuggestToExit() {
  UserMessenger::SuggestToExit();
  for (;;) {
    int result_of_quit = UserInputProcessor::GetMenuItem();

    if (result_of_quit == kMainMenu) {
      user_want_to_exit_ = false;
      break;
    } else if (result_of_quit == kQuit || result_of_quit == kSubMenuQuit) {
      user_want_to_exit_ = true;
      break;
    } else {
      UserMessenger::ShowIncorrectInput();
    }
  }
}

bool ConsoleMode::IsCorrectRegistration() const {
  return registrator_.IsCorrectRegistration();
}

void ConsoleMode::EndProgram() const { UserMessenger::WishAGoodDay(); }

void ConsoleMode::ShowIncorrectRegistration() const {
  UserMessenger::ShowIncorrectRegisterData();
}
