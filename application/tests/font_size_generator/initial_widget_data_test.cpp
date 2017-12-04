#include <doctest.h>

#include <QFont>
#include <QWidget>

#include <initial_widget_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("negative font scale multiplier = -1.1") {
    double font_scale_multiplier = -1.1;

    WHEN("method SetFontScaleMultiplier called with this parameter") {
      InitialWidgetData initial_widget_data;
      initial_widget_data.SetFontScaleMultiplier(font_scale_multiplier);
      THEN("method FontScaleMultiplier should return 0") {
        double result = initial_widget_data.FontScaleMultiplier();
        REQUIRE(result == 0.0);
      }
    }
  }
}
