#include <console_mode.h>

#include <output_setup.h>
#include <user_messenger.h>

// =========== New Code ==============
#include <atm_interactor.h>

// new code
ConsoleMode::ConsoleMode() : atm_(new AtmInteractor()) {
  OutputSetup::SetupTwoStreamsForOutput();
}
// new code
ConsoleMode::~ConsoleMode() {}

void ConsoleMode::RunATM() {
  initial_menu_.RunApplication();

  RunProgram();
}

void ConsoleMode::RunProgram() {
  int user_choice = initial_menu_.UserChoice();
  RunSectionBasedOn(user_choice);

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
  }

  if (user_choice != kQuit) {
    ShowIncorrectRegistration();
  }
}

void ConsoleMode::DemoMenu() {
  demo_mode_.RunDemoMenu();
  if (demo_mode_.UserWantToRegistrate()) {
    RegistrateUser();
  }
}

void ConsoleMode::
    RegistrateUser() {  // registrator_.RunRegistrationMenu(user_);
}

void ConsoleMode::MainProgramMenu() {
  do {
    UserMessenger::ShowMainMenu();
    ExecuteOperation(user_input_.GetDigitInputFromUser());
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
  SuggestToQuit();
}

void ConsoleMode::SuggestToQuit() {
  user_want_to_exit_ = quit_menu_handler_.GetQuitResult();
}

bool ConsoleMode::IsCorrectRegistration() const {
  // return registrator_.IsRegistrationStatusOk();
  return true;
}

void ConsoleMode::EndProgram() const { UserMessenger::WishAGoodDay(); }

void ConsoleMode::ShowIncorrectRegistration() const {
  UserMessenger::ShowIncorrectRegistration();
}
