#include <splash_screen_composer.h>

#include <QFrame>
#include <QLabel>

#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

void SplashScreenComposer::TuneLabels(QLabel* version_label,
                                      QLabel* company_name_label,
                                      QLabel* text_label,
                                      QLabel* atm_label) {
  version_label->setText("v1.0.1");
  version_label->setGeometry(SplashScreenGeometry::VersionLabel());
  version_label->setFont(WidgetFont::SetFont(8));

  company_name_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  company_name_label->setGeometry(SplashScreenGeometry::CompanyNameLabel());
  company_name_label->setFont(WidgetFont::SetFont(25));

  text_label->setText("Press <Enter> to start");
  text_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  text_label->setFont(WidgetFont::SetFont(15));

  atm_label->setText("ATM");
  atm_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  atm_label->setFont(WidgetFont::SetFont());
}

void SplashScreenComposer::StretchAtmLabel(const DeltaSize& delta_size,
                                           QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size.Width(),
                                       delta_size.Height());
}
