﻿#include <graphical_splash_screen.h>

#include <QObject>
#include <QRect>

#include <atm_splash_screen.h>
#include <main_widget.h>
#include <side.h>
#include <widget_hider.h>

gui::GraphicalSplashScreen::GraphicalSplashScreen()
    : splash_screen_(new AtmSplashScreen),
      hider_(new WidgetHider),
      main_widget_(new gui::MainWidget) {
  splash_screen_->SetCompanyName("North Star");
  hider_->SetWidgetForHideAnimation(splash_screen_);
  hider_->SetHideDirection(Side::kUp);
  SetConnections();
}

gui::GraphicalSplashScreen::~GraphicalSplashScreen() {
  delete splash_screen_;
  delete hider_;
  delete main_widget_;
}

void gui::GraphicalSplashScreen::RunInitialScreen() { splash_screen_->show(); }

void gui::GraphicalSplashScreen::SetConnections() {
  QObject::connect(splash_screen_,
                   SIGNAL(PassPositionWhenEnterPressed(const QRect&)), hider_,
                   SLOT(Hide(const QRect&)));
  QObject::connect(splash_screen_,
                   SIGNAL(PassPositionWhenEnterPressed(const QRect&)),
                   main_widget_, SLOT(SetWidgetGeometry(const QRect&)));
  QObject::connect(splash_screen_, SIGNAL(PassScreenSizeCondition(bool)),
                   main_widget_, SLOT(FullScreenSizeCondition(bool)));
  QObject::connect(hider_, SIGNAL(IsAlreadyHidden()), splash_screen_,
                   SLOT(close()));
  QObject::connect(hider_, SIGNAL(IsAlreadyHidden()), main_widget_,
                   SLOT(ShowMainWidget()));
}
