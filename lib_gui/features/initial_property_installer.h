#ifndef INITIAL_PROPERTY_INSTALLER_H
#define INITIAL_PROPERTY_INSTALLER_H

class QWidget;

class InitialPropertyInstaller {
 public:
  static void InstallInitialProperies(QWidget* widget,
                                      int widget_width,
                                      int widget_height);
};

#endif  // INITIAL_PROPERTY_INSTALLER_H
