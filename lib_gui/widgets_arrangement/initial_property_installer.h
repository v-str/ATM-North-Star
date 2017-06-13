#ifndef INITIAL_PROPERTY_INSTALLER_H
#define INITIAL_PROPERTY_INSTALLER_H

class QWidget;

class InitialPropertyInstaller {
 public:
  enum WidgetSize { kResize, kFixedSize };

  static void SetInitialProperties(QWidget* widget,
                                   int widget_width,
                                   int widget_height,
                                   const WidgetSize& widget_size);
};

#endif  // INITIAL_PROPERTY_INSTALLER_H
