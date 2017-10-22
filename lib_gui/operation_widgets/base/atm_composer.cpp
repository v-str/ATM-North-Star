#include <atm_composer.h>

#include <atm_button.h>
#include <side.h>

BackButtonComposer AtmComposer::kBackButtonComposer;
DeltaSize AtmComposer::kDeltaSize;

void AtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  kDeltaSize = delta_size;
}

void AtmComposer::ComposeBackButton(AtmButton* back_button) {
  kBackButtonComposer.ComposeBackButton(kDeltaSize, back_button);
}
