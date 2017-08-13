#include "authentication_standard.h"

int AuthenticationStandard::MinLoginLength() { return k_min_login_length_; }

int AuthenticationStandard::MaxLoginLength() { return k_max_login_length_; }

int AuthenticationStandard::PasswordLength() { return k_password_length_; }
