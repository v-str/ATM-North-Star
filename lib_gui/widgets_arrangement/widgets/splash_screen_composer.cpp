#include <splash_screen_composer.h>

#include <QFrame>
#include <QLabel>

#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

AtmLabelStretcher SplashScreenComposer::kAtmLabelStretcher;

void SplashScreenComposer::TuneLabels(QLabel* version_label,
                                      QLabel* company_name_label,
                                      QLabel* text_label,
                                      QLabel* atm_label) {
  SetText(version_label, text_label, atm_label);
  SetGeometry(version_label, company_name_label);
  SetFont(version_label, company_name_label, text_label, atm_label);
  SetAlignment(company_name_label, text_label, atm_label);
}

void SplashScreenComposer::StretchAtmLabel(const DeltaSize& delta_size,
                                           QLabel* atm_label) {
  kAtmLabelStretcher.StretchAtmLabel(atm_label, delta_size.Width(),
                                     delta_size.Height());
}

void SplashScreenComposer::SetText(QLabel* version_label,
                                   QLabel* text_label,
                                   QLabel* atm_label) {
  version_label->setText("v1.0.1");
  text_label->setText("Press <Enter> to start");
  atm_label->setText("ATM");
}

void SplashScreenComposer::SetGeometry(QLabel* version_label,
                                       QLabel* company_name_label) {
  version_label->setGeometry(SplashScreenGeometry::VersionLabel());
  company_name_label->setGeometry(SplashScreenGeometry::CompanyNameLabel());
}

void SplashScreenComposer::SetFont(QLabel* version_label,
                                   QLabel* company_name_label,
                                   QLabel* text_label,
                                   QLabel* atm_label) {
  version_label->setFont(WidgetFont::SetFont(8));
  company_name_label->setFont(WidgetFont::SetFont(25));
  text_label->setFont(WidgetFont::SetFont(15));
  atm_label->setFont(WidgetFont::SetFont());
}

void SplashScreenComposer::SetAlignment(QLabel* company_name_label,
                                        QLabel* text_label,
                                        QLabel* atm_label) {
  company_name_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  text_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  atm_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}
